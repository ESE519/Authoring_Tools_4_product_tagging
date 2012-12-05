/********************************************************************************
** Form generated from reading UI file 'vios_gui.ui'
**
** Created: Wed Dec 5 17:42:11 2012
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
#include <QtGui/QGraphicsView>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViosGui
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView_frame;
    QListWidget *listWidget;
    QToolButton *browse;
    QGroupBox *selected_images;
    QGraphicsView *graphicsView_detection;
    QGraphicsView *graphicsView_processed;
    QLabel *label_2;
    QLabel *label;
    QGroupBox *face_label;
    QRadioButton *radioButton;
    QTextEdit *textEdit_2;
    QGroupBox *menu;
    QPushButton *frame_prev;
    QPushButton *prev;
    QTextEdit *frame_skip;
    QPushButton *fwd;
    QPushButton *frame_fwd;
    QSlider *horizontalSlider;
    QPushButton *pushButton_5;
    QMenuBar *menuBar;
    QMenu *menuViOS;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ViosGui)
    {
        if (ViosGui->objectName().isEmpty())
            ViosGui->setObjectName(QString::fromUtf8("ViosGui"));
        ViosGui->resize(1000, 700);
        ViosGui->setAutoFillBackground(false);
        ViosGui->setStyleSheet(QString::fromUtf8("QWindow{\n"
"color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"     }\n"
"\n"
""));
        centralWidget = new QWidget(ViosGui);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        graphicsView_frame = new QGraphicsView(centralWidget);
        graphicsView_frame->setObjectName(QString::fromUtf8("graphicsView_frame"));
        graphicsView_frame->setGeometry(QRect(10, 50, 640, 480));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView_frame->sizePolicy().hasHeightForWidth());
        graphicsView_frame->setSizePolicy(sizePolicy);
        graphicsView_frame->setMouseTracking(true);
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(170, 10, 281, 21));
        browse = new QToolButton(centralWidget);
        browse->setObjectName(QString::fromUtf8("browse"));
        browse->setGeometry(QRect(460, 10, 23, 25));
        selected_images = new QGroupBox(centralWidget);
        selected_images->setObjectName(QString::fromUtf8("selected_images"));
        selected_images->setGeometry(QRect(660, 30, 291, 381));
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
        graphicsView_detection->setGeometry(QRect(50, 60, 200, 200));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(graphicsView_detection->sizePolicy().hasHeightForWidth());
        graphicsView_detection->setSizePolicy(sizePolicy1);
        graphicsView_processed = new QGraphicsView(selected_images);
        graphicsView_processed->setObjectName(QString::fromUtf8("graphicsView_processed"));
        graphicsView_processed->setGeometry(QRect(110, 300, 70, 70));
        sizePolicy1.setHeightForWidth(graphicsView_processed->sizePolicy().hasHeightForWidth());
        graphicsView_processed->setSizePolicy(sizePolicy1);
        label_2 = new QLabel(selected_images);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(100, 270, 91, 17));
        label = new QLabel(selected_images);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 30, 101, 17));
        face_label = new QGroupBox(centralWidget);
        face_label->setObjectName(QString::fromUtf8("face_label"));
        face_label->setGeometry(QRect(660, 440, 301, 171));
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
        radioButton->setGeometry(QRect(20, 30, 116, 22));
        textEdit_2 = new QTextEdit(face_label);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(160, 20, 121, 131));
        menu = new QGroupBox(centralWidget);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu->setGeometry(QRect(10, 540, 631, 80));
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
        frame_prev = new QPushButton(menu);
        frame_prev->setObjectName(QString::fromUtf8("frame_prev"));
        frame_prev->setGeometry(QRect(150, 50, 41, 27));
        prev = new QPushButton(menu);
        prev->setObjectName(QString::fromUtf8("prev"));
        prev->setGeometry(QRect(200, 50, 41, 27));
        frame_skip = new QTextEdit(menu);
        frame_skip->setObjectName(QString::fromUtf8("frame_skip"));
        frame_skip->setGeometry(QRect(260, 40, 41, 31));
        fwd = new QPushButton(menu);
        fwd->setObjectName(QString::fromUtf8("fwd"));
        fwd->setGeometry(QRect(320, 50, 41, 27));
        frame_fwd = new QPushButton(menu);
        frame_fwd->setObjectName(QString::fromUtf8("frame_fwd"));
        frame_fwd->setGeometry(QRect(370, 50, 41, 27));
        horizontalSlider = new QSlider(menu);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(30, 20, 591, 29));
        horizontalSlider->setPageStep(10);
        horizontalSlider->setOrientation(Qt::Horizontal);
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(40, 10, 98, 27));
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

        QMetaObject::connectSlotsByName(ViosGui);
    } // setupUi

    void retranslateUi(QMainWindow *ViosGui)
    {
        ViosGui->setWindowTitle(QApplication::translate("ViosGui", "ViosGui", 0, QApplication::UnicodeUTF8));
        browse->setText(QApplication::translate("ViosGui", "...", 0, QApplication::UnicodeUTF8));
        selected_images->setTitle(QApplication::translate("ViosGui", "Detection", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ViosGui", "Cropped Face", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ViosGui", "Detected Face", 0, QApplication::UnicodeUTF8));
        face_label->setTitle(QApplication::translate("ViosGui", "Face Label", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("ViosGui", "RadioButton", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("ViosGui", "menu", 0, QApplication::UnicodeUTF8));
        frame_prev->setText(QApplication::translate("ViosGui", "<<", 0, QApplication::UnicodeUTF8));
        prev->setText(QApplication::translate("ViosGui", "<", 0, QApplication::UnicodeUTF8));
        fwd->setText(QApplication::translate("ViosGui", ">", 0, QApplication::UnicodeUTF8));
        frame_fwd->setText(QApplication::translate("ViosGui", ">>", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("ViosGui", "Undo", 0, QApplication::UnicodeUTF8));
        menuViOS->setTitle(QApplication::translate("ViosGui", "ViOS", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ViosGui: public Ui_ViosGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIOS_GUI_H
