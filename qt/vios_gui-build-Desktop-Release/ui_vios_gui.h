/********************************************************************************
** Form generated from reading UI file 'vios_gui.ui'
**
** Created: Sun Dec 9 23:30:10 2012
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
#include <QtGui/QGridLayout>
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
    QTextEdit *label_editor;
    QPushButton *delete_button;
    QWidget *gridLayoutWidget;
    QGridLayout *label_grid;
    QPushButton *add_button;
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
    QPushButton *select_button;
    QPushButton *discard_button;
    QPushButton *train_button;
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
    QMenuBar *menuBar;
    QMenu *menuViOS;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ViosGui)
    {
        if (ViosGui->objectName().isEmpty())
            ViosGui->setObjectName(QString::fromUtf8("ViosGui"));
        ViosGui->resize(1000, 750);
        ViosGui->setAutoFillBackground(false);
        ViosGui->setStyleSheet(QString::fromUtf8("QWindow{\n"
"color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"     }\n"
"\n"
""));
        centralWidget = new QWidget(ViosGui);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabwidget = new QTabWidget(centralWidget);
        tabwidget->setObjectName(QString::fromUtf8("tabwidget"));
        tabwidget->setGeometry(QRect(0, 0, 1000, 750));
        face = new QWidget();
        face->setObjectName(QString::fromUtf8("face"));
        face_label = new QGroupBox(face);
        face_label->setObjectName(QString::fromUtf8("face_label"));
        face_label->setGeometry(QRect(680, 440, 301, 191));
        face_label->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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
" }"));
        label_editor = new QTextEdit(face_label);
        label_editor->setObjectName(QString::fromUtf8("label_editor"));
        label_editor->setGeometry(QRect(160, 30, 121, 131));
        delete_button = new QPushButton(face_label);
        delete_button->setObjectName(QString::fromUtf8("delete_button"));
        delete_button->setGeometry(QRect(90, 160, 51, 27));
        gridLayoutWidget = new QWidget(face_label);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 30, 141, 131));
        label_grid = new QGridLayout(gridLayoutWidget);
        label_grid->setSpacing(6);
        label_grid->setContentsMargins(11, 11, 11, 11);
        label_grid->setObjectName(QString::fromUtf8("label_grid"));
        label_grid->setContentsMargins(0, 0, 0, 0);
        add_button = new QPushButton(face_label);
        add_button->setObjectName(QString::fromUtf8("add_button"));
        add_button->setGeometry(QRect(190, 160, 51, 21));
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
        graphicsView_detection->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView_detection->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView_processed = new QGraphicsView(selected_images);
        graphicsView_processed->setObjectName(QString::fromUtf8("graphicsView_processed"));
        graphicsView_processed->setGeometry(QRect(190, 80, 70, 70));
        sizePolicy.setHeightForWidth(graphicsView_processed->sizePolicy().hasHeightForWidth());
        graphicsView_processed->setSizePolicy(sizePolicy);
        graphicsView_processed->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView_processed->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        label_2 = new QLabel(selected_images);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(180, 60, 101, 17));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        label = new QLabel(selected_images);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 30, 101, 17));
        label->setFont(font);
        show_margins = new QCheckBox(selected_images);
        show_margins->setObjectName(QString::fromUtf8("show_margins"));
        show_margins->setGeometry(QRect(10, 210, 121, 22));
        statistics = new QListView(selected_images);
        statistics->setObjectName(QString::fromUtf8("statistics"));
        statistics->setGeometry(QRect(10, 260, 161, 111));
        label_3 = new QLabel(selected_images);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 240, 66, 17));
        label_3->setFont(font);
        h_indent = new QDoubleSpinBox(selected_images);
        h_indent->setObjectName(QString::fromUtf8("h_indent"));
        h_indent->setGeometry(QRect(180, 190, 61, 21));
        QFont font1;
        font1.setPointSize(11);
        h_indent->setFont(font1);
        h_indent->setMaximum(1);
        h_indent->setSingleStep(0.05);
        h_indent->setValue(0.3);
        v_indent = new QDoubleSpinBox(selected_images);
        v_indent->setObjectName(QString::fromUtf8("v_indent"));
        v_indent->setGeometry(QRect(180, 220, 61, 21));
        v_indent->setFont(font1);
        v_indent->setMaximum(1);
        v_indent->setSingleStep(0.05);
        v_indent->setValue(0.3);
        label_4 = new QLabel(selected_images);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(250, 190, 16, 17));
        label_4->setFont(font1);
        label_5 = new QLabel(selected_images);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(250, 220, 16, 17));
        label_6 = new QLabel(selected_images);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(200, 170, 51, 17));
        label_6->setFont(font);
        select_button = new QPushButton(selected_images);
        select_button->setObjectName(QString::fromUtf8("select_button"));
        select_button->setGeometry(QRect(180, 270, 91, 27));
        discard_button = new QPushButton(selected_images);
        discard_button->setObjectName(QString::fromUtf8("discard_button"));
        discard_button->setGeometry(QRect(180, 300, 91, 27));
        train_button = new QPushButton(selected_images);
        train_button->setObjectName(QString::fromUtf8("train_button"));
        train_button->setGeometry(QRect(180, 340, 98, 27));
        graphicsView_frame = new QGraphicsView(face);
        graphicsView_frame->setObjectName(QString::fromUtf8("graphicsView_frame"));
        graphicsView_frame->setGeometry(QRect(20, 50, 640, 480));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(graphicsView_frame->sizePolicy().hasHeightForWidth());
        graphicsView_frame->setSizePolicy(sizePolicy1);
        graphicsView_frame->setMouseTracking(true);
        browse = new QToolButton(face);
        browse->setObjectName(QString::fromUtf8("browse"));
        browse->setGeometry(QRect(430, 10, 23, 25));
        listWidget = new QListWidget(face);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(30, 10, 391, 20));
        listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        menu = new QGroupBox(face);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu->setGeometry(QRect(20, 540, 631, 80));
        menu->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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
" }"));
        prev_skip_button = new QPushButton(menu);
        prev_skip_button->setObjectName(QString::fromUtf8("prev_skip_button"));
        prev_skip_button->setGeometry(QRect(200, 50, 41, 27));
        prev_button = new QPushButton(menu);
        prev_button->setObjectName(QString::fromUtf8("prev_button"));
        prev_button->setGeometry(QRect(250, 50, 41, 27));
        frame_skip_textedit = new QTextEdit(menu);
        frame_skip_textedit->setObjectName(QString::fromUtf8("frame_skip_textedit"));
        frame_skip_textedit->setGeometry(QRect(300, 40, 41, 31));
        fwd_button = new QPushButton(menu);
        fwd_button->setObjectName(QString::fromUtf8("fwd_button"));
        fwd_button->setGeometry(QRect(350, 50, 41, 27));
        fwd_skip_button = new QPushButton(menu);
        fwd_skip_button->setObjectName(QString::fromUtf8("fwd_skip_button"));
        fwd_skip_button->setGeometry(QRect(400, 50, 41, 27));
        horizontalSlider = new QSlider(menu);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(30, 20, 591, 29));
        horizontalSlider->setPageStep(10);
        horizontalSlider->setOrientation(Qt::Horizontal);
        mode_image = new QRadioButton(face);
        mode_image->setObjectName(QString::fromUtf8("mode_image"));
        mode_image->setGeometry(QRect(460, 10, 71, 22));
        mode_video = new QRadioButton(face);
        mode_video->setObjectName(QString::fromUtf8("mode_video"));
        mode_video->setGeometry(QRect(540, 10, 71, 22));
        tabwidget->addTab(face, QString());
        object = new QWidget();
        object->setObjectName(QString::fromUtf8("object"));
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

        tabwidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ViosGui);
    } // setupUi

    void retranslateUi(QMainWindow *ViosGui)
    {
        ViosGui->setWindowTitle(QApplication::translate("ViosGui", "ViosGui", 0, QApplication::UnicodeUTF8));
        face_label->setTitle(QApplication::translate("ViosGui", "Face Label", 0, QApplication::UnicodeUTF8));
        delete_button->setText(QApplication::translate("ViosGui", "Delete", 0, QApplication::UnicodeUTF8));
        add_button->setText(QApplication::translate("ViosGui", "Add", 0, QApplication::UnicodeUTF8));
        selected_images->setTitle(QApplication::translate("ViosGui", "Detection", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ViosGui", "Cropped Face", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ViosGui", "Detected Face", 0, QApplication::UnicodeUTF8));
        show_margins->setText(QApplication::translate("ViosGui", "Show Margins", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ViosGui", "Statistics", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ViosGui", "H", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ViosGui", "V", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ViosGui", "Indent", 0, QApplication::UnicodeUTF8));
        select_button->setText(QApplication::translate("ViosGui", "Select", 0, QApplication::UnicodeUTF8));
        discard_button->setText(QApplication::translate("ViosGui", "Discard", 0, QApplication::UnicodeUTF8));
        train_button->setText(QApplication::translate("ViosGui", "Train", 0, QApplication::UnicodeUTF8));
        browse->setText(QApplication::translate("ViosGui", "...", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("ViosGui", "menu", 0, QApplication::UnicodeUTF8));
        prev_skip_button->setText(QApplication::translate("ViosGui", "<<", 0, QApplication::UnicodeUTF8));
        prev_button->setText(QApplication::translate("ViosGui", "<", 0, QApplication::UnicodeUTF8));
        fwd_button->setText(QApplication::translate("ViosGui", ">", 0, QApplication::UnicodeUTF8));
        fwd_skip_button->setText(QApplication::translate("ViosGui", ">>", 0, QApplication::UnicodeUTF8));
        mode_image->setText(QApplication::translate("ViosGui", "Image", 0, QApplication::UnicodeUTF8));
        mode_video->setText(QApplication::translate("ViosGui", "Video", 0, QApplication::UnicodeUTF8));
        tabwidget->setTabText(tabwidget->indexOf(face), QApplication::translate("ViosGui", "Face Recognition", 0, QApplication::UnicodeUTF8));
        tabwidget->setTabText(tabwidget->indexOf(object), QApplication::translate("ViosGui", "Object Detection", 0, QApplication::UnicodeUTF8));
        menuViOS->setTitle(QApplication::translate("ViosGui", "ViOS", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ViosGui: public Ui_ViosGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIOS_GUI_H
