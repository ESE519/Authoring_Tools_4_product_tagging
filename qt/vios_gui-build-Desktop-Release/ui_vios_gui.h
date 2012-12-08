/********************************************************************************
** Form generated from reading UI file 'vios_gui.ui'
**
** Created: Fri Dec 7 16:10:16 2012
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
    QCheckBox *checkBox;
    QListView *listView;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *doubleSpinBox_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QLabel *label_7;
    QGroupBox *face_label;
    QRadioButton *radioButton;
    QTextEdit *textEdit_2;
    QToolButton *toolButton;
    QGroupBox *menu;
    QPushButton *prev_skip_button;
    QPushButton *prev_button;
    QTextEdit *frame_skip_textedit;
    QPushButton *fwd_button;
    QPushButton *fwd_skip_button;
    QSlider *horizontalSlider;
    QPushButton *pushButton_5;
    QTextEdit *tmp_textEdit;
    QPushButton *tmp_pushButton;
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
        selected_images->setGeometry(QRect(660, 40, 291, 381));
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
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(graphicsView_detection->sizePolicy().hasHeightForWidth());
        graphicsView_detection->setSizePolicy(sizePolicy1);
        graphicsView_detection->setMinimumSize(QSize(0, 0));
        graphicsView_detection->setMaximumSize(QSize(16777215, 16777215));
        graphicsView_processed = new QGraphicsView(selected_images);
        graphicsView_processed->setObjectName(QString::fromUtf8("graphicsView_processed"));
        graphicsView_processed->setGeometry(QRect(190, 80, 70, 70));
        sizePolicy1.setHeightForWidth(graphicsView_processed->sizePolicy().hasHeightForWidth());
        graphicsView_processed->setSizePolicy(sizePolicy1);
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
        checkBox = new QCheckBox(selected_images);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(10, 210, 121, 22));
        listView = new QListView(selected_images);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(10, 260, 161, 111));
        label_3 = new QLabel(selected_images);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 240, 66, 17));
        doubleSpinBox = new QDoubleSpinBox(selected_images);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(180, 190, 61, 21));
        QFont font1;
        font1.setPointSize(11);
        doubleSpinBox->setFont(font1);
        doubleSpinBox_2 = new QDoubleSpinBox(selected_images);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
        doubleSpinBox_2->setGeometry(QRect(180, 220, 61, 21));
        doubleSpinBox_2->setFont(font1);
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
        radioButton_2 = new QRadioButton(selected_images);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(180, 290, 101, 22));
        radioButton_3 = new QRadioButton(selected_images);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setGeometry(QRect(180, 310, 91, 22));
        radioButton_4 = new QRadioButton(selected_images);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));
        radioButton_4->setGeometry(QRect(180, 330, 91, 22));
        label_7 = new QLabel(selected_images);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(180, 270, 101, 20));
        label_7->setFont(font);
        face_label = new QGroupBox(centralWidget);
        face_label->setObjectName(QString::fromUtf8("face_label"));
        face_label->setGeometry(QRect(660, 440, 301, 191));
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
        toolButton = new QToolButton(face_label);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(190, 150, 61, 31));
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
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(40, 10, 98, 27));
        tmp_textEdit = new QTextEdit(centralWidget);
        tmp_textEdit->setObjectName(QString::fromUtf8("tmp_textEdit"));
        tmp_textEdit->setGeometry(QRect(490, 0, 461, 21));
        tmp_pushButton = new QPushButton(centralWidget);
        tmp_pushButton->setObjectName(QString::fromUtf8("tmp_pushButton"));
        tmp_pushButton->setGeometry(QRect(960, 0, 31, 27));
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
        checkBox->setText(QApplication::translate("ViosGui", "Show Margins", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ViosGui", "Statistics", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ViosGui", "H", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ViosGui", "V", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ViosGui", "Indent", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("ViosGui", "Both Eyes", 0, QApplication::UnicodeUTF8));
        radioButton_3->setText(QApplication::translate("ViosGui", "One Eye", 0, QApplication::UnicodeUTF8));
        radioButton_4->setText(QApplication::translate("ViosGui", "No Eyes", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("ViosGui", "Detect only if", 0, QApplication::UnicodeUTF8));
        face_label->setTitle(QApplication::translate("ViosGui", "Face Label", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("ViosGui", "RadioButton", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("ViosGui", "Browse", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("ViosGui", "menu", 0, QApplication::UnicodeUTF8));
        prev_skip_button->setText(QApplication::translate("ViosGui", "<<", 0, QApplication::UnicodeUTF8));
        prev_button->setText(QApplication::translate("ViosGui", "<", 0, QApplication::UnicodeUTF8));
        fwd_button->setText(QApplication::translate("ViosGui", ">", 0, QApplication::UnicodeUTF8));
        fwd_skip_button->setText(QApplication::translate("ViosGui", ">>", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("ViosGui", "Undo", 0, QApplication::UnicodeUTF8));
        tmp_pushButton->setText(QApplication::translate("ViosGui", "L", 0, QApplication::UnicodeUTF8));
        menuViOS->setTitle(QApplication::translate("ViosGui", "ViOS", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ViosGui: public Ui_ViosGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIOS_GUI_H
