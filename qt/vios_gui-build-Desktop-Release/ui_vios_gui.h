/********************************************************************************
** Form generated from reading UI file 'vios_gui.ui'
**
** Created: Sat Dec 8 16:21:23 2012
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
        radioButton = new QRadioButton(face_label);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(20, 30, 91, 22));
        textEdit_2 = new QTextEdit(face_label);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(160, 30, 121, 131));
        toolButton = new QToolButton(face_label);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(190, 160, 51, 21));
        checkBox_2 = new QCheckBox(face_label);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(120, 30, 21, 22));
        pushButton = new QPushButton(face_label);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(50, 160, 51, 27));
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
        graphicsView_processed = new QGraphicsView(selected_images);
        graphicsView_processed->setObjectName(QString::fromUtf8("graphicsView_processed"));
        graphicsView_processed->setGeometry(QRect(190, 80, 70, 70));
        sizePolicy.setHeightForWidth(graphicsView_processed->sizePolicy().hasHeightForWidth());
        graphicsView_processed->setSizePolicy(sizePolicy);
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
        h_indent->setValue(0.1);
        v_indent = new QDoubleSpinBox(selected_images);
        v_indent->setObjectName(QString::fromUtf8("v_indent"));
        v_indent->setGeometry(QRect(180, 220, 61, 21));
        v_indent->setFont(font1);
        v_indent->setMaximum(1);
        v_indent->setSingleStep(0.05);
        v_indent->setValue(0.1);
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
        both_eyes = new QRadioButton(selected_images);
        both_eyes->setObjectName(QString::fromUtf8("both_eyes"));
        both_eyes->setGeometry(QRect(180, 290, 101, 22));
        one_eye = new QRadioButton(selected_images);
        one_eye->setObjectName(QString::fromUtf8("one_eye"));
        one_eye->setGeometry(QRect(180, 310, 91, 22));
        no_eyes = new QRadioButton(selected_images);
        no_eyes->setObjectName(QString::fromUtf8("no_eyes"));
        no_eyes->setGeometry(QRect(180, 330, 91, 22));
        label_7 = new QLabel(selected_images);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(180, 270, 101, 20));
        label_7->setFont(font);
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
