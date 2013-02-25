/********************************************************************************
** Form generated from reading UI file 'vios_gui.ui'
**
** Created: Wed Jan 16 12:23:25 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIOS_GUI_H
#define UI_VIOS_GUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGraphicsView>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListView>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViosGui
{
public:
    QWidget *centralWidget;
    QTabWidget *tabwidget;
    QWidget *face;
    QGroupBox *face_label;
    QRadioButton *radioButton;
    QTextEdit *textEdit_2;
    QToolButton *toolButton;
    QCheckBox *checkBox_2;
    QPushButton *pushButton;
    QGroupBox *selected_images;
    QGraphicsView *graphicsView_detection;
    QGraphicsView *graphicsView_processed;
    QLabel *label_2;
    QLabel *label;
    QCheckBox *show_margins;
    QListView *statistics;
    QLabel *label_3;
    QDoubleSpinBox *h_indent;
    QDoubleSpinBox *v_indent;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QRadioButton *both_eyes;
    QRadioButton *one_eye;
    QRadioButton *no_eyes;
    QLabel *label_7;
    QGraphicsView *graphicsView_frame;
    QToolButton *browse;
    QListWidget *listWidget;
    QGroupBox *menu;
    QPushButton *prev_skip_button;
    QPushButton *prev_button;
    QTextEdit *frame_skip_textedit;
    QPushButton *fwd_button;
    QPushButton *fwd_skip_button;
    QSlider *horizontalSlider;
    QRadioButton *mode_image;
    QRadioButton *mode_video;
    QWidget *object;
    QGraphicsView *obj_graphicsView;
    QGroupBox *obj_menu;
    QPushButton *obj_prev_skip_button;
    QPushButton *obj_fwd_skip_button;
    QPushButton *obj_fwd_button;
    QPushButton *obj_prev_button;
    QTextBrowser *obj_frame_skip;
    QSlider *obj_slider;
    QGroupBox *groupBox_2;
    QGraphicsView *graphics_croppedobject;
    QLabel *label_8;
    QTextEdit *obj_average_display;
    QPushButton *add_object_button;
    QPushButton *obj_avg_button;
    QListWidget *obj_list;
    QPushButton *obj_browse;
    QRadioButton *obj_image;
    QRadioButton *obj_video;
    QMenuBar *menuBar;
    QMenu *menuViOS;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ViosGui)
    {
        if (ViosGui->objectName().isEmpty())
            ViosGui->setObjectName(QString::fromUtf8("ViosGui"));
        ViosGui->resize(1000, 750);
        ViosGui->setMouseTracking(true);
        ViosGui->setAutoFillBackground(false);
        ViosGui->setStyleSheet(QString::fromUtf8("QWindow{\n"
"color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"     }\n"
"\n"
""));
        centralWidget = new QWidget(ViosGui);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8("QcentralWidget {\n"
"     background-color: rgb(130, 163, 255);\n"
"    }\n"
"\n"
""));
        tabwidget = new QTabWidget(centralWidget);
        tabwidget->setObjectName(QString::fromUtf8("tabwidget"));
        tabwidget->setGeometry(QRect(0, 0, 1000, 750));
        tabwidget->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0.265, y1:0.239, x2:1, y2:0.955, stop:0 rgba(0, 87, 244, 100), stop:1 rgba(255, 255, 255, 255));\n"
""));
        face = new QWidget();
        face->setObjectName(QString::fromUtf8("face"));
        face_label = new QGroupBox(face);
        face_label->setObjectName(QString::fromUtf8("face_label"));
        face_label->setGeometry(QRect(680, 450, 301, 191));
        face_label->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"	background-color: qlineargradient(spread:pad, x1:0.0238483, y1:0, x2:1, y2:1, stop:0 rgba(88, 95, 90, 255), stop:1 rgba(255, 255, 255, 255));\n"
"	     border: 2px solid gray;\n"
"     border-radius: 5px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
" }\n"
"\n"
" QGroupBox::title {\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #CECECE, stop: 1 #FFFFFF);\n"
" }"));
        radioButton = new QRadioButton(face_label);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(20, 30, 91, 22));
        radioButton->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 244, 244);"));
        textEdit_2 = new QTextEdit(face_label);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(160, 30, 121, 131));
        textEdit_2->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 244, 244);"));
        toolButton = new QToolButton(face_label);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(190, 160, 51, 21));
        toolButton->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius:5px;"));
        checkBox_2 = new QCheckBox(face_label);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(120, 30, 21, 22));
        checkBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 244, 244);"));
        pushButton = new QPushButton(face_label);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(50, 160, 51, 27));
        pushButton->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius:5px;"));
        selected_images = new QGroupBox(face);
        selected_images->setObjectName(QString::fromUtf8("selected_images"));
        selected_images->setGeometry(QRect(680, 40, 291, 381));
        selected_images->setContextMenuPolicy(Qt::DefaultContextMenu);
        selected_images->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #E0E0E0, stop: 1 #FFFFFF);\n"
"     border: 2px solid gray;\n"
"     border-radius: 5px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
" }\n"
"\n"
" QGroupBox::title {\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #CECECE, stop: 1 #FFFFFF);\n"
" }\n"
" "));
        selected_images->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        graphicsView_detection = new QGraphicsView(selected_images);
        graphicsView_detection->setObjectName(QString::fromUtf8("graphicsView_detection"));
        graphicsView_detection->setGeometry(QRect(10, 50, 155, 155));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView_detection->sizePolicy().hasHeightForWidth());
        graphicsView_detection->setSizePolicy(sizePolicy);
        graphicsView_detection->setMinimumSize(QSize(0, 0));
        graphicsView_detection->setMaximumSize(QSize(16777215, 16777215));
        graphicsView_detection->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 244, 244);"));
        graphicsView_processed = new QGraphicsView(selected_images);
        graphicsView_processed->setObjectName(QString::fromUtf8("graphicsView_processed"));
        graphicsView_processed->setGeometry(QRect(190, 80, 70, 70));
        sizePolicy.setHeightForWidth(graphicsView_processed->sizePolicy().hasHeightForWidth());
        graphicsView_processed->setSizePolicy(sizePolicy);
        graphicsView_processed->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 244, 244);"));
        label_2 = new QLabel(selected_images);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(180, 60, 101, 17));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 244, 244);"));
        label = new QLabel(selected_images);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 30, 101, 17));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 244, 244);"));
        show_margins = new QCheckBox(selected_images);
        show_margins->setObjectName(QString::fromUtf8("show_margins"));
        show_margins->setGeometry(QRect(10, 210, 121, 22));
        show_margins->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 244, 244);"));
        statistics = new QListView(selected_images);
        statistics->setObjectName(QString::fromUtf8("statistics"));
        statistics->setGeometry(QRect(10, 260, 161, 111));
        statistics->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 244, 244);"));
        label_3 = new QLabel(selected_images);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 240, 66, 17));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 244, 244);"));
        h_indent = new QDoubleSpinBox(selected_images);
        h_indent->setObjectName(QString::fromUtf8("h_indent"));
        h_indent->setGeometry(QRect(180, 190, 61, 21));
        QFont font1;
        font1.setPointSize(11);
        h_indent->setFont(font1);
        h_indent->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 244, 244);"));
        h_indent->setMaximum(1);
        h_indent->setSingleStep(0.05);
        h_indent->setValue(0.1);
        v_indent = new QDoubleSpinBox(selected_images);
        v_indent->setObjectName(QString::fromUtf8("v_indent"));
        v_indent->setGeometry(QRect(180, 220, 61, 21));
        v_indent->setFont(font1);
        v_indent->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 244, 244);"));
        v_indent->setMaximum(1);
        v_indent->setSingleStep(0.05);
        v_indent->setValue(0.1);
        label_4 = new QLabel(selected_images);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(250, 190, 16, 17));
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 244, 244);"));
        label_5 = new QLabel(selected_images);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(250, 220, 16, 17));
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 244, 244);"));
        label_6 = new QLabel(selected_images);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(200, 170, 51, 17));
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 244, 244);"));
        both_eyes = new QRadioButton(selected_images);
        both_eyes->setObjectName(QString::fromUtf8("both_eyes"));
        both_eyes->setGeometry(QRect(180, 290, 101, 22));
        both_eyes->setAutoFillBackground(false);
        both_eyes->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 244, 244);"));
        one_eye = new QRadioButton(selected_images);
        one_eye->setObjectName(QString::fromUtf8("one_eye"));
        one_eye->setGeometry(QRect(180, 310, 91, 22));
        one_eye->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 244, 244);"));
        no_eyes = new QRadioButton(selected_images);
        no_eyes->setObjectName(QString::fromUtf8("no_eyes"));
        no_eyes->setGeometry(QRect(180, 330, 91, 22));
        no_eyes->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 244, 244);"));
        label_7 = new QLabel(selected_images);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(180, 270, 101, 20));
        label_7->setFont(font);
        label_7->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 244, 244);"));
        graphicsView_frame = new QGraphicsView(face);
        graphicsView_frame->setObjectName(QString::fromUtf8("graphicsView_frame"));
        graphicsView_frame->setGeometry(QRect(20, 50, 640, 480));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(graphicsView_frame->sizePolicy().hasHeightForWidth());
        graphicsView_frame->setSizePolicy(sizePolicy1);
        graphicsView_frame->setMouseTracking(true);
        graphicsView_frame->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 245, 245);\n"
"border:2px solid gray;\n"
"border-radius:5px;\n"
""));
        browse = new QToolButton(face);
        browse->setObjectName(QString::fromUtf8("browse"));
        browse->setGeometry(QRect(460, 10, 23, 25));
        browse->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius:5px;"));
        listWidget = new QListWidget(face);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(20, 10, 431, 31));
        listWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 245, 245);\n"
"border:2px solid gray;\n"
"border-radius:5px;\n"
""));
        listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        menu = new QGroupBox(face);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu->setGeometry(QRect(20, 540, 631, 91));
        menu->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"	background-color: qlineargradient(spread:pad, x1:0.0238483, y1:0, x2:1, y2:1, stop:0 rgba(88, 95, 90, 255), stop:1 rgba(255, 255, 255, 255));\n"
"	     border: 2px solid gray;\n"
"     border-radius: 5px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
" }\n"
"\n"
" QGroupBox::title {\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #CECECE, stop: 1 #FFFFFF);\n"
" }"));
        prev_skip_button = new QPushButton(menu);
        prev_skip_button->setObjectName(QString::fromUtf8("prev_skip_button"));
        prev_skip_button->setGeometry(QRect(200, 60, 41, 27));
        prev_skip_button->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius:5px;"));
        prev_button = new QPushButton(menu);
        prev_button->setObjectName(QString::fromUtf8("prev_button"));
        prev_button->setGeometry(QRect(250, 60, 41, 27));
        prev_button->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius:5px;"));
        frame_skip_textedit = new QTextEdit(menu);
        frame_skip_textedit->setObjectName(QString::fromUtf8("frame_skip_textedit"));
        frame_skip_textedit->setGeometry(QRect(300, 50, 41, 31));
        frame_skip_textedit->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 245, 245);\n"
"border: 2px solid gray;\n"
"border-radius: 5px;"));
        fwd_button = new QPushButton(menu);
        fwd_button->setObjectName(QString::fromUtf8("fwd_button"));
        fwd_button->setGeometry(QRect(350, 60, 41, 27));
        fwd_button->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius:5px;"));
        fwd_skip_button = new QPushButton(menu);
        fwd_skip_button->setObjectName(QString::fromUtf8("fwd_skip_button"));
        fwd_skip_button->setGeometry(QRect(400, 60, 41, 27));
        fwd_skip_button->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius:5px;"));
        horizontalSlider = new QSlider(menu);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(30, 20, 591, 29));
        horizontalSlider->setStyleSheet(QString::fromUtf8("background-color: rgb(153, 153, 153);\n"
"border-radius:5px;"));
        horizontalSlider->setPageStep(10);
        horizontalSlider->setOrientation(Qt::Horizontal);
        mode_image = new QRadioButton(face);
        mode_image->setObjectName(QString::fromUtf8("mode_image"));
        mode_image->setGeometry(QRect(490, 10, 81, 22));
        mode_image->setStyleSheet(QString::fromUtf8("\n"
"border-radius:5px;"));
        mode_video = new QRadioButton(face);
        mode_video->setObjectName(QString::fromUtf8("mode_video"));
        mode_video->setGeometry(QRect(580, 10, 71, 22));
        mode_video->setStyleSheet(QString::fromUtf8("\n"
"border-radius:5px;"));
        tabwidget->addTab(face, QString());
        object = new QWidget();
        object->setObjectName(QString::fromUtf8("object"));
        obj_graphicsView = new QGraphicsView(object);
        obj_graphicsView->setObjectName(QString::fromUtf8("obj_graphicsView"));
        obj_graphicsView->setGeometry(QRect(20, 50, 640, 480));
        obj_graphicsView->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 245, 245);\n"
"border:2px solid gray;\n"
"border-radius:5px;\n"
""));
        obj_menu = new QGroupBox(object);
        obj_menu->setObjectName(QString::fromUtf8("obj_menu"));
        obj_menu->setGeometry(QRect(20, 540, 641, 101));
        obj_menu->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"	background-color: qlineargradient(spread:pad, x1:0.0238483, y1:0, x2:1, y2:1, stop:0 rgba(88, 95, 90, 255), stop:1 rgba(255, 255, 255, 255));\n"
"     border: 2px solid gray;\n"
"     border-radius: 5px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
" }\n"
"\n"
" QGroupBox::title {\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #CECECE, stop: 1 #FFFFFF);\n"
" }"));
        obj_prev_skip_button = new QPushButton(obj_menu);
        obj_prev_skip_button->setObjectName(QString::fromUtf8("obj_prev_skip_button"));
        obj_prev_skip_button->setGeometry(QRect(200, 60, 41, 31));
        obj_prev_skip_button->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 5px;"));
        obj_fwd_skip_button = new QPushButton(obj_menu);
        obj_fwd_skip_button->setObjectName(QString::fromUtf8("obj_fwd_skip_button"));
        obj_fwd_skip_button->setGeometry(QRect(410, 60, 41, 31));
        obj_fwd_skip_button->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 5px;"));
        obj_fwd_button = new QPushButton(obj_menu);
        obj_fwd_button->setObjectName(QString::fromUtf8("obj_fwd_button"));
        obj_fwd_button->setGeometry(QRect(360, 60, 41, 31));
        obj_fwd_button->setStyleSheet(QString::fromUtf8("border:2px solid gray;\n"
"border-radius: 5px;\n"
""));
        obj_prev_button = new QPushButton(obj_menu);
        obj_prev_button->setObjectName(QString::fromUtf8("obj_prev_button"));
        obj_prev_button->setGeometry(QRect(250, 60, 41, 31));
        obj_prev_button->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 5px;"));
        obj_frame_skip = new QTextBrowser(obj_menu);
        obj_frame_skip->setObjectName(QString::fromUtf8("obj_frame_skip"));
        obj_frame_skip->setGeometry(QRect(300, 60, 51, 31));
        obj_frame_skip->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 245, 245);\n"
"border: 2px solid gray;\n"
"border-radius: 5px;"));
        obj_slider = new QSlider(obj_menu);
        obj_slider->setObjectName(QString::fromUtf8("obj_slider"));
        obj_slider->setGeometry(QRect(10, 20, 621, 29));
        obj_slider->setStyleSheet(QString::fromUtf8("background-color: rgb(153, 153, 153);\n"
"border-radius:5px;"));
        obj_slider->setOrientation(Qt::Horizontal);
        groupBox_2 = new QGroupBox(object);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(680, 40, 301, 411));
        groupBox_2->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"	background-color: qlineargradient(spread:pad, x1:0.0238483, y1:0, x2:1, y2:1, stop:0 rgba(88, 95, 90, 255), stop:1 rgba(255, 255, 255, 255));\n"
"	     border: 2px solid gray;\n"
"     border-radius: 5px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
" }\n"
"\n"
" QGroupBox::title {\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #CECECE, stop: 1 #FFFFFF);\n"
" }"));
        graphics_croppedobject = new QGraphicsView(groupBox_2);
        graphics_croppedobject->setObjectName(QString::fromUtf8("graphics_croppedobject"));
        graphics_croppedobject->setGeometry(QRect(50, 60, 200, 200));
        graphics_croppedobject->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 245, 245);\n"
"border: 2px solid gray;\n"
"border-radius:5px;"));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(90, 40, 121, 20));
        label_8->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 244, 244);"));
        obj_average_display = new QTextEdit(groupBox_2);
        obj_average_display->setObjectName(QString::fromUtf8("obj_average_display"));
        obj_average_display->setGeometry(QRect(220, 320, 51, 41));
        obj_average_display->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 245, 245);\n"
"border:2px solid gray;\n"
"border-radius:5px;"));
        add_object_button = new QPushButton(groupBox_2);
        add_object_button->setObjectName(QString::fromUtf8("add_object_button"));
        add_object_button->setGeometry(QRect(100, 260, 101, 27));
        add_object_button->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius:5px;"));
        obj_avg_button = new QPushButton(groupBox_2);
        obj_avg_button->setObjectName(QString::fromUtf8("obj_avg_button"));
        obj_avg_button->setGeometry(QRect(40, 320, 161, 41));
        obj_avg_button->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius:5px;"));
        obj_list = new QListWidget(object);
        obj_list->setObjectName(QString::fromUtf8("obj_list"));
        obj_list->setGeometry(QRect(20, 10, 431, 21));
        obj_list->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 245, 245);\n"
"border:1px solid gray;\n"
"border-radius:4px;"));
        obj_browse = new QPushButton(object);
        obj_browse->setObjectName(QString::fromUtf8("obj_browse"));
        obj_browse->setGeometry(QRect(470, 10, 21, 21));
        obj_browse->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius:5px;"));
        obj_image = new QRadioButton(object);
        obj_image->setObjectName(QString::fromUtf8("obj_image"));
        obj_image->setGeometry(QRect(500, 10, 71, 22));
        obj_image->setStyleSheet(QString::fromUtf8("\n"
"border-radius:5px;"));
        obj_video = new QRadioButton(object);
        obj_video->setObjectName(QString::fromUtf8("obj_video"));
        obj_video->setGeometry(QRect(580, 10, 71, 22));
        obj_video->setStyleSheet(QString::fromUtf8("\n"
"border-radius:5px;"));
        tabwidget->addTab(object, QString());
        ViosGui->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ViosGui);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 25));
        menuViOS = new QMenu(menuBar);
        menuViOS->setObjectName(QString::fromUtf8("menuViOS"));
        ViosGui->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ViosGui);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ViosGui->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ViosGui);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ViosGui->setStatusBar(statusBar);

        menuBar->addAction(menuViOS->menuAction());

        retranslateUi(ViosGui);

        tabwidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(ViosGui);
    } // setupUi

    void retranslateUi(QMainWindow *ViosGui)
    {
        ViosGui->setWindowTitle(QApplication::translate("ViosGui", "ViosGui", 0, QApplication::UnicodeUTF8));
        face_label->setTitle(QApplication::translate("ViosGui", "Face Label", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("ViosGui", "Unknown", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("ViosGui", "Add", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QString());
        pushButton->setText(QApplication::translate("ViosGui", "Delete", 0, QApplication::UnicodeUTF8));
        selected_images->setTitle(QApplication::translate("ViosGui", "Detection", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ViosGui", "Cropped Face", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ViosGui", "Detected Face", 0, QApplication::UnicodeUTF8));
        show_margins->setText(QApplication::translate("ViosGui", "Show Margins", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ViosGui", "Statistics", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ViosGui", "H", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ViosGui", "V", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ViosGui", "Indent", 0, QApplication::UnicodeUTF8));
        both_eyes->setText(QApplication::translate("ViosGui", "Both Eyes", 0, QApplication::UnicodeUTF8));
        one_eye->setText(QApplication::translate("ViosGui", "One Eye", 0, QApplication::UnicodeUTF8));
        no_eyes->setText(QApplication::translate("ViosGui", "No Eyes", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("ViosGui", "Detect only if", 0, QApplication::UnicodeUTF8));
        browse->setText(QApplication::translate("ViosGui", "...", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("ViosGui", "menu", 0, QApplication::UnicodeUTF8));
        prev_skip_button->setText(QApplication::translate("ViosGui", "<<", 0, QApplication::UnicodeUTF8));
        prev_button->setText(QApplication::translate("ViosGui", "<", 0, QApplication::UnicodeUTF8));
        fwd_button->setText(QApplication::translate("ViosGui", ">", 0, QApplication::UnicodeUTF8));
        fwd_skip_button->setText(QApplication::translate("ViosGui", ">>", 0, QApplication::UnicodeUTF8));
        mode_image->setText(QApplication::translate("ViosGui", "Image", 0, QApplication::UnicodeUTF8));
        mode_video->setText(QApplication::translate("ViosGui", "Video", 0, QApplication::UnicodeUTF8));
        tabwidget->setTabText(tabwidget->indexOf(face), QApplication::translate("ViosGui", "Face Recognition", 0, QApplication::UnicodeUTF8));
        obj_menu->setTitle(QApplication::translate("ViosGui", "Menu", 0, QApplication::UnicodeUTF8));
        obj_prev_skip_button->setText(QApplication::translate("ViosGui", "<<", 0, QApplication::UnicodeUTF8));
        obj_fwd_skip_button->setText(QApplication::translate("ViosGui", ">>", 0, QApplication::UnicodeUTF8));
        obj_fwd_button->setText(QApplication::translate("ViosGui", "->", 0, QApplication::UnicodeUTF8));
        obj_prev_button->setText(QApplication::translate("ViosGui", "<-", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("ViosGui", "Object Training", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("ViosGui", "   selected object", 0, QApplication::UnicodeUTF8));
        add_object_button->setText(QApplication::translate("ViosGui", "Add object", 0, QApplication::UnicodeUTF8));
        obj_avg_button->setText(QApplication::translate("ViosGui", "Get Average color", 0, QApplication::UnicodeUTF8));
        obj_browse->setText(QApplication::translate("ViosGui", "...", 0, QApplication::UnicodeUTF8));
        obj_image->setText(QApplication::translate("ViosGui", "image", 0, QApplication::UnicodeUTF8));
        obj_video->setText(QApplication::translate("ViosGui", "video", 0, QApplication::UnicodeUTF8));
        tabwidget->setTabText(tabwidget->indexOf(object), QApplication::translate("ViosGui", "Object Detection", 0, QApplication::UnicodeUTF8));
        menuViOS->setTitle(QApplication::translate("ViosGui", "ViOS", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ViosGui: public Ui_ViosGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIOS_GUI_H
