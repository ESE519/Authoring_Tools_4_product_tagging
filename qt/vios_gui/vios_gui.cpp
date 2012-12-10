#include "vios_gui.h"
#include "ui_vios_gui.h"
#include "general.h"

using namespace face;

int bound (int x, int l, int u){
    if (x<l)
        x = l;
    else if (x>u)
        x = u;
    return x;
}

QImage ViosGui::Mat2QImage(const Mat& mat)
{
    // 8-bits unsigned, NO. OF CHANNELS=1
    if(mat.type()==CV_8UC1)
    {
        // Set the color table (used to translate colour indexes to qRgb values)
        QVector<QRgb> colorTable;
        for (int i=0; i<256; i++)
            colorTable.push_back(qRgb(i,i,i));
        // Copy input Mat
        const uchar *qImageBuffer = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage img(qImageBuffer, mat.cols, mat.rows, mat.step, QImage::Format_Indexed8);
        img.setColorTable(colorTable);
        return img;
    }
    // 8-bits unsigned, NO. OF CHANNELS=3
    if(mat.type()==CV_8UC3)
    {
        // Copy input Mat
        const uchar *qImageBuffer = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage img(qImageBuffer, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return img.rgbSwapped();
    }
    else
    {
        qDebug() << "ERROR: Mat could not be converted to QImage.";
        return QImage();
    }
} // MatToQImage()
void ViosGui::custom_style_sheet(){
    basestyle = "border: 2px solid gray; border-radius: 5px; margin-top: 1ex; /* leave space at the top for the title */} QGroupBox::title { subcontrol-origin: margin; subcontrol-position: top center; /* position at the top center */ padding: 0 3px; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #CECECE, stop: 1 #FFFFFF);}";
    style.resize(3);
    style[0] ="QGroupBox {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #E0E0E0, stop: 1 #FFFFFF); "+basestyle;
    style[1] ="QGroupBox {background-color: qlineargradient(spread:pad, x1:0.441, y1:0.574, x2:1, y2:0, stop:0 rgba(239, 174, 31, 255), stop:1 rgba(255, 255, 255, 255)); "+basestyle;
    style[2] ="QGroupBox {background-color: qlineargradient(spread:pad, x1:0.440758, y1:0.574, x2:1, y2:0, stop:0 rgba(31, 174, 31, 255), stop:1 rgba(255, 255, 255, 255)); "+basestyle;
}

ViosGui::ViosGui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ViosGui)
{
    ui->setupUi(this);
    video_step = 2*DEFAULT_VIDEO_STEP;
    image_step = 5;
    signalMapper = new QSignalMapper(this);
    default_pen.setColor(QColor(255,0,0));
    default_pen.setJoinStyle(Qt::RoundJoin);
    active_pen.setColor(QColor(0,255,0));
    active_pen.setJoinStyle(Qt::RoundJoin);
    active_pen.setWidth(2);
    custom_style_sheet();
    ui->selected_images->setStyleSheet(style[0]);
    ui->mode_video->setChecked(1);
    video_mode_load_flag = 0;
    image_mode_load_flag = 0;
    detection_strength = 0;
    directory = QDir::current();
    image_filter << "*.jpg" << "*.jpeg" << "*.JPEG" << "*.JPG" << "*.png" << "*.PNG" << "*.bmp" << "*.BMP" << "*.tiff" << "*.TIFF";
    video_filter << "*.wmv" << "*.WMV" << "*.avi" << "*.AVI" << "*.flv" << "*.FLV" << "*.mp*" << "*.MP*" << "*.ts" << "*.TS";
    connect(ui->browse, SIGNAL(clicked()), this, SLOT(browse_files()));

    connect(ui->fwd_skip_button, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->fwd_skip_button, QString::fromStdString("fwd_skip"));
    connect(ui->prev_skip_button, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->prev_skip_button, QString::fromStdString("prev_skip"));
    connect(ui->fwd_button, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->fwd_button, QString::fromStdString("fwd"));
    connect(ui->prev_button, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->prev_button, QString::fromStdString("prev"));
    connect(signalMapper, SIGNAL(mapped(const QString &)),this, SIGNAL(map_buttons(const QString &)));
    connect(this,SIGNAL(map_buttons(const QString &)),this,SLOT(menu_decode(const QString &)));

    connect(ui->frame_skip_textedit, SIGNAL(textChanged()), this, SLOT(change_skip_step()));

    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->horizontalSlider, SLOT(setValue(int)));
    connect(ui->horizontalSlider, SIGNAL(sliderReleased()), this, SLOT(set_slider()));

    connect(ui->show_margins, SIGNAL(clicked()), this, SLOT(show_margins()));

    connect(ui->h_indent, SIGNAL(valueChanged(double)), this, SLOT(change_margins(double)));
    connect(ui->v_indent, SIGNAL(valueChanged(double)), this, SLOT(change_margins(double)));

    connect(ui->select_button, SIGNAL(clicked()), this, SLOT(select_image()));
    connect(ui->discard_button, SIGNAL(clicked()), this, SLOT(discard_image()));
    connect(ui->train_button, SIGNAL(clicked()), this, SLOT(build_recognizer()));

    connect(ui->add_button, SIGNAL(clicked()), this, SLOT(add_labels()));
    connect(ui->delete_button, SIGNAL(clicked()), this, SLOT(delete_labels()));

    scene = new QGraphicsScene();
    scene_detected = new QGraphicsScene();
    scene_cropped = new QGraphicsScene();
    ui->graphicsView_frame->setScene(scene);
    ui->graphicsView_detection->setScene(scene_detected);
    ui->graphicsView_processed->setScene(scene_cropped);
    vline1 = new QGraphicsLineItem();
    vline2 = new QGraphicsLineItem();
    hline = new QGraphicsLineItem();
    vline1->setPen(default_pen);
    vline2->setPen(default_pen);
    hline->setPen(default_pen);

    train_path = "../train/";
    junk_path = "../train/junk/";
    train_recognizer_file = train_path + "train.csv";
    ftrainwrite.open(train_recognizer_file.c_str(),ios::app);
    ifstream ftrainread(train_recognizer_file.c_str(),ifstream::in);
    system(("mkdir " + junk_path).c_str());
    class_label_file = train_path + "class_label.csv";
    radio =(QRadioButton **) malloc(10*sizeof(QRadioButton *));
    check =(QCheckBox **) malloc(10*sizeof(QCheckBox *));
    ifstream fin(class_label_file.c_str(),ifstream::in);
    if(!fin){
        ofstream fout(class_label_file.c_str(),ofstream::out);
        fout.close();
    }
    else {
        string label;
        int cnt = 0;
        while(fin>>label){
            class_label.push_back(label);
            radio[cnt]=(new QRadioButton(QString::fromStdString(label),this));
            check[cnt]=(new QCheckBox("",this));
            ui->label_grid->addWidget(radio[cnt],cnt,0);
            ui->label_grid->addWidget(check[cnt],cnt,1);
            system(("mkdir " + train_path + class_label[cnt]).c_str());
            cnt++;
        }
        if (class_label.size()>0)
            (*radio[0]).setChecked(1);
        fin.close();
    }
    int clabel;
    Mat tmpI;
    string path,label,line;
    while(getline(ftrainread,line)){
        stringstream liness(line);
        getline(liness,path,';');
        getline(liness,label);
        clabel = atoi(label.c_str());
        tmpI = imread(line,0);
        train_img.push_back(tmpI);
        train_label.push_back(class_label[clabel]);
        train_num_label.push_back(clabel);
    }
    ftrainread.close();
}

ViosGui::~ViosGui()
{
    delete ui;
}

void ViosGui::delete_labels(){
    int tmpn = class_label.size();
    for (int i=0;i<class_label.size(); i++){
        if (check[i]->isChecked()){
            system(("mv " + train_path + class_label[i] + " " + junk_path).c_str());
            class_label.erase(class_label.begin()+i);
        }
    }
    for (int i=class_label.size()-1;i>=0;i--){
        ui->label_grid->removeWidget(radio[i]);
        ui->label_grid->removeWidget(check[i]);
        delete(radio[i]);
        delete(check[i]);
    }
    radio =(QRadioButton **) malloc(10*sizeof(QRadioButton *));
    check =(QCheckBox **) malloc(10*sizeof(QCheckBox *));
    ui->label_grid->update();
    //radio.clear();
    //check.clear();
    ofstream fout(class_label_file.c_str(),ofstream::out);
    for (int i=0;i<class_label.size();i++){
        fout << class_label[i] << endl;
        radio[i]=(new QRadioButton(QString::fromStdString(class_label[i])));
        check[i]=(new QCheckBox(""));
        ui->label_grid->addWidget(radio[i],i,0);
        ui->label_grid->addWidget(check[i],i,1);
    }
    if (class_label.size()>0)
        (*radio[0]).setChecked(1);
    fout.close();
}

void ViosGui::add_labels(){
    string str = ui->label_editor->toPlainText().toStdString();
    stringstream sin(str);
    string line;
    int cnt = class_label.size();
    while(sin>>line){
        class_label.push_back(line);
        if (cnt >=10)
            break;
        radio[cnt]=(new QRadioButton(QString::fromStdString(line)));
        check[cnt]=(new QCheckBox(""));
        ui->label_grid->addWidget(radio[cnt],cnt,0);
        ui->label_grid->addWidget(check[cnt],cnt,1);
        system(("mkdir "+train_path+line).c_str());
        cnt++;
    }
    ui->label_editor->clear();
    ofstream fout(class_label_file.c_str(),ofstream::out);
    for (int i=0;i<class_label.size();i++){
        fout << class_label[i] << endl;
    }
    if (class_label.size()>0)
        (*radio[0]).setChecked(1);
    fout.close();
}

void ViosGui::load_data()
{
    if (ui->mode_video->isChecked()){
        cap.open(input_path);
        frame_count = cap.get(CV_CAP_PROP_FRAME_COUNT);
        frame_pos = 0;
        ui->horizontalSlider->setMaximum(frame_count-1);
        ui->horizontalSlider->setTracking(1);
        video_mode_load_flag = 1;
        image_mode_load_flag = 0;
        update_image();
    }
    else if (ui->mode_image->isChecked()){
        image_names = directory.entryList();
        frame_pos = 0;
        frame_count = image_names.size();
        ui->horizontalSlider->setMaximum(frame_count-1);
        ui->horizontalSlider->setTracking(1);
        image_mode_load_flag = 1;
        video_mode_load_flag = 0;
        update_image();
    }
}

void ViosGui::menu_decode(const QString & button_name)
{
    int step = 0;
    if (video_mode_load_flag==1){
        if (button_name == "fwd_skip")
            step = video_step;
        else if (button_name == "prev_skip")
            step = -1* video_step;
        else if (button_name == "fwd")
            step = DEFAULT_VIDEO_STEP;
        else if (button_name == "prev")
            step = -1 * DEFAULT_VIDEO_STEP;
        frame_pos += step;
        update_image();
    }
    else if (image_mode_load_flag == 1){
        if (button_name == "fwd_skip")
            step = image_step;
        else if (button_name == "prev_skip")
            step = -1* image_step;
        else if (button_name == "fwd")
            step = 1;
        else if (button_name == "prev")
            step = -1;
        frame_pos += step;
        update_image();
    }
}

void ViosGui::update_image()
{
    detection_strength = 0;
    detection_flag = 0;
    saved_flag = 0;
    Mat out1;
    if (frame_pos >= frame_count)
        frame_pos = frame_count - 1;
    else if (frame_pos < 0)
        frame_pos = 0;
    if (video_mode_load_flag==1){
        cap.set(CV_CAP_PROP_POS_FRAMES,frame_pos);
        cap >> image_cv;
    }
    else{
        QString tmp = image_names.at(frame_pos);
        image_cv = imread(input_path+"/"+tmp.toStdString());
    }
    recognizer.detect_face(face_pos,eye,image_cv);
    if (video_mode_load_flag == 1)
        frame_pos = cap.get(CV_CAP_PROP_POS_FRAMES);
    ui->horizontalSlider->setValue(frame_pos);
    image_qt = Mat2QImage(image_cv);
    scene->clear();
    scene->addPixmap(QPixmap::fromImage(image_qt));
    num_face_detections = face_pos.size();
    if (ui->show_margins->checkState()){
        scene_detected->removeItem(vline1);
        scene_detected->removeItem(vline2);
        scene_detected->removeItem(hline);
    }
    if (num_face_detections > 0){
        scene->addRect(face_pos[0].x,face_pos[0].y,face_pos[0].width,face_pos[0].height,active_pen);
        scene_detected->clear();
        Mat roi;
        cv::resize(image_cv(face_pos[0]),roi,Size(150,150),0,0,INTER_LINEAR);
        //roi = image_cv(face_pos[0]);
        scene_detected->addPixmap(QPixmap::fromImage(Mat2QImage(roi)));
        double scale = 150.0/((face_pos[0].width + face_pos[0].height)/2);
        //scale = 1;
        Rect eye_rect_right, eye_rect_left;
        eye_rect_right.x = (scale*(eye[0].right_pos.x -face_pos[0].x - eye[0].right_radius));
        eye_rect_right.y = (scale*(eye[0].right_pos.y -face_pos[0].y - eye[0].right_radius));
        eye_rect_right.width =(scale*2*eye[0].right_radius);
        eye_rect_right.height = (scale*2*eye[0].right_radius);

        eye_rect_left.x = (scale*(eye[0].left_pos.x -face_pos[0].x - eye[0].left_radius));
        eye_rect_left.y=(scale*(eye[0].left_pos.y -face_pos[0].y - eye[0].left_radius));
        eye_rect_left.width=(scale*2*eye[0].left_radius);
        eye_rect_left.height=(scale*2*eye[0].left_radius);

        eye[0].left_pos.x -= face_pos[0].x;
        eye[0].left_pos.y -= face_pos[0].y;
        eye[0].right_pos.x -= face_pos[0].x;
        eye[0].right_pos.y -= face_pos[0].y;
        Mat temp_roi = image_cv(face_pos[0]);
        recognizer.align_face(out1,temp_roi,eye[0],ui->h_indent->value(),ui->v_indent->value(),Size(recognizer.FACE_RECOGNIZE_SIZE,recognizer.FACE_RECOGNIZE_SIZE));
        detection_strength=0;
        if (eye[0].left_radius > 0){
            scene_detected->addEllipse(eye_rect_left.x,eye_rect_left.y,eye_rect_left.width,eye_rect_left.height,QPen(QColor(0,0,255)));
            detection_strength++;
        }
        if (eye[0].right_radius > 0){
            scene_detected->addEllipse(eye_rect_right.x,eye_rect_right.y,eye_rect_right.width,eye_rect_right.height,QPen(QColor(0,0,255)));
            detection_strength++;
        }
        for (int i=1;i<num_face_detections;i++)
            scene->addRect(face_pos[i].x,face_pos[i].y,face_pos[i].width,face_pos[i].height,default_pen);
        scene_cropped->addPixmap(QPixmap::fromImage(Mat2QImage(out1)));
        out1.copyTo(selected_img);
        detection_flag = 1;
    }
    else{
        scene_detected->clear();
        scene_cropped->clear();
    }
    ui->selected_images->setStyleSheet(style[detection_strength]);
    if (ui->show_margins->checkState()){
        int x1 = ui->graphicsView_detection->geometry().width()*ui->h_indent->value();
        int y2 = ui->graphicsView_detection->geometry().height()-1;
        x1 = bound(x1,1,ui->graphicsView_detection->geometry().width()-1);
        y2 = bound(y2,1,ui->graphicsView_detection->geometry().height()-1);
        vline1->setLine(x1,1,x1,y2);
        x1 = ui->graphicsView_detection->geometry().width()*(1 - ui->h_indent->value());
        x1 = bound(x1,1,ui->graphicsView_detection->geometry().width()-1);
        vline2->setLine(x1,1,x1,y2);
        scene_detected->addItem(vline1);
        scene_detected->addItem(vline2);
        int y1 = ui->graphicsView_detection->geometry().height()*ui->v_indent->value();
        int x2 = ui->graphicsView_detection->geometry().width()-1;
        x2 = bound(x2,1,ui->graphicsView_detection->geometry().width()-1);
        y1 = bound(y1,1,ui->graphicsView_detection->geometry().height()-1);
        hline->setLine(1,y1,x2,y1);
        scene_detected->addItem(hline);
    }
}

void ViosGui::show_margins()
{
    if (ui->show_margins->checkState()){
        int x1 = ui->graphicsView_detection->geometry().width()*ui->h_indent->value();
        int y2 = ui->graphicsView_detection->geometry().height()-1;
        x1 = bound(x1,1,ui->graphicsView_detection->geometry().width()-1);
        y2 = bound(y2,1,ui->graphicsView_detection->geometry().height()-1);
        vline1->setLine(x1,1,x1,y2);
        x1 = bound(x1,1,ui->graphicsView_detection->geometry().width()-1);
        x1 = ui->graphicsView_detection->geometry().width()*(1 - ui->h_indent->value());
        vline2->setLine(x1,1,x1,y2);
        scene_detected->addItem(vline1);
        scene_detected->addItem(vline2);
        int y1 = ui->graphicsView_detection->geometry().height()*ui->v_indent->value();
        int x2 = ui->graphicsView_detection->geometry().width()-1;
        x2 = bound(x2,1,ui->graphicsView_detection->geometry().width()-1);
        y1 = bound(y1,1,ui->graphicsView_detection->geometry().height()-1);
        hline->setLine(1,y1,x2,y1);
        scene_detected->addItem(hline);
    }
    else{
        scene_detected->removeItem(vline1);
        scene_detected->removeItem(vline2);
        scene_detected->removeItem(hline);
    }
}
void ViosGui::change_margins(double value)
{
    int x1 = ui->graphicsView_detection->geometry().width()*ui->h_indent->value();
    int y2 = ui->graphicsView_detection->geometry().height()-1;
    x1 = bound(x1,1,ui->graphicsView_detection->geometry().width()-1);
    y2 = bound(y2,1,ui->graphicsView_detection->geometry().height()-1);
    vline1->setLine(x1,1,x1,y2);
    x1 = ui->graphicsView_detection->geometry().width()*(1 - ui->h_indent->value());
    x1 = bound(x1,1,ui->graphicsView_detection->geometry().width()-1);
    vline2->setLine(x1,1,x1,y2);
    int y1 = ui->graphicsView_detection->geometry().height()*ui->v_indent->value();
    int x2 = ui->graphicsView_detection->geometry().width()-1;
    y1 = bound(y1,1,ui->graphicsView_detection->geometry().height()-1);
    hline->setLine(1,y1,x2,y1);
}

string num2strdigits(unsigned int num, unsigned int numdigits){
    string digits;
    digits.resize(numdigits);
    int div=10;
    for (int i=numdigits-1; i>=0; i--){
        digits[i] = '0' + (num % div);
        num/=div;
    }
    return digits;
}

void ViosGui::select_image(){
    int idx;
    Mat tmp(recognizer.FACE_RECOGNIZE_SIZE,recognizer.FACE_RECOGNIZE_SIZE,CV_8UC1);
    if(detection_flag && !saved_flag && class_label.size()>0){
        for (int i=0;i<class_label.size();i++){
            if (radio[i]->isChecked()){
                idx = i;
                break;
            }
        }
        selected_img.copyTo(tmp);
        train_img.push_back(tmp);
        train_label.push_back(class_label[idx]);
        saved_flag = 1;
    }
    if (class_label.size()>0)
        menu_decode("fwd");
}

void ViosGui::discard_image(){
    menu_decode("fwd");
}

void ViosGui::build_recognizer(){
    string filename;
    int idx;
    vector < int > class_label_cnt;
    for (int i=0;i<class_label.size();i++){
        class_label_cnt.push_back(0);
        system(("rm "+train_path+class_label[i]+"/*.jpg").c_str());
    }
    for (int i=0;i<train_label.size();i++){
        for (int j=0;j<class_label.size();j++){
            if (class_label[j] == train_label[i]){
                class_label_cnt[j]+=1;
                idx = j;
                break;
            }
        }
        train_num_label.push_back(idx);
        filename = train_path + class_label[idx] + "/" + class_label[idx] + num2strdigits(class_label_cnt[idx]-1,5) + ".jpg";
        imwrite(filename.c_str(),train_img[i]);
        ftrainwrite << filename << ";" << train_num_label[i] << endl;
    }
    ftrainwrite.close();
    recognizer.eigen_recognizer = createEigenFaceRecognizer(80,recognizer.EIGEN_THRESH);
    recognizer.fisher_recognizer = createFisherFaceRecognizer(0,recognizer.FISHER_THRESH);
    recognizer.lbph_recognizer = createLBPHFaceRecognizer(1,8,8,8,recognizer.LBPH_THRESH);
    recognizer.eigen_recognizer->train(train_img, train_num_label);
    recognizer.fisher_recognizer->train(train_img, train_num_label);
    recognizer.lbph_recognizer->train(train_img, train_num_label);

    recognizer.eigen_recognizer->save(train_path + "train_eigen.xml");
    recognizer.fisher_recognizer->save(train_path + "train_fisher.xml");
    recognizer.lbph_recognizer->save(train_path + "train_lbph.xml");
}

void ViosGui::set_slider()
{
    frame_pos = ui->horizontalSlider->value();
    update_image();
}

void ViosGui::change_skip_step()
{
    QString txt = ui->frame_skip_textedit->toPlainText();
    video_step = txt.toInt();
}
void ViosGui::browse_files(){
    QString path;
    bool flag = 0;
    if (ui->mode_image->isChecked()){
        // select a directory
        directory.setNameFilters(image_filter);
        path = QFileDialog::getExistingDirectory(this, tr("Browse to add"), directory.path());
        if (directory.entryList().size()>0)
            flag = 1;
    }
    else{
        // select a file using file dialog
        directory.setNameFilters(video_filter);
        path = QFileDialog::getOpenFileName(this, tr("Browse to add"), directory.path());
        flag = directory.match(video_filter,path);
    }
    if (path!="" && flag){
        directory.setPath(path);
        input_path = path.toStdString();
        load_data();
    }
    ui->listWidget->clear();
    ui->listWidget->addItem(directory.absolutePath());
}
