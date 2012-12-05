/********************************************************************************
** Form generated from reading UI file 'facerec.ui'
**
** Created: Mon Dec 3 21:00:53 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FACEREC_H
#define UI_FACEREC_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_facerec
{
public:
    QWidget *centralWidget;
    QRadioButton *penny;
    QRadioButton *sheldon;
    QLabel *picture2;
    QLabel *picture3;
    QRadioButton *leonard;
    QRadioButton *howard;
    QRadioButton *raj;
    QPushButton *frame_prev;
    QPushButton *frame_fwd;
    QPushButton *forward;
    QPushButton *previous;
    QLineEdit *lineEdit;
    QLabel *picture1;
    QLineEdit *browse;
    QSlider *horizontalSlider;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *facerec)
    {
        if (facerec->objectName().isEmpty())
            facerec->setObjectName(QString::fromUtf8("facerec"));
        facerec->resize(632, 452);
        facerec->setMouseTracking(true);
        facerec->setWindowOpacity(0.1);
        facerec->setAutoFillBackground(true);
        centralWidget = new QWidget(facerec);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        penny = new QRadioButton(centralWidget);
        penny->setObjectName(QString::fromUtf8("penny"));
        penny->setGeometry(QRect(390, 270, 71, 25));
        sheldon = new QRadioButton(centralWidget);
        sheldon->setObjectName(QString::fromUtf8("sheldon"));
        sheldon->setGeometry(QRect(390, 290, 81, 25));
        picture2 = new QLabel(centralWidget);
        picture2->setObjectName(QString::fromUtf8("picture2"));
        picture2->setGeometry(QRect(410, 20, 171, 131));
        picture3 = new QLabel(centralWidget);
        picture3->setObjectName(QString::fromUtf8("picture3"));
        picture3->setGeometry(QRect(450, 170, 101, 81));
        leonard = new QRadioButton(centralWidget);
        leonard->setObjectName(QString::fromUtf8("leonard"));
        leonard->setGeometry(QRect(510, 270, 81, 25));
        howard = new QRadioButton(centralWidget);
        howard->setObjectName(QString::fromUtf8("howard"));
        howard->setGeometry(QRect(510, 290, 91, 25));
        raj = new QRadioButton(centralWidget);
        raj->setObjectName(QString::fromUtf8("raj"));
        raj->setGeometry(QRect(390, 310, 116, 22));
        frame_prev = new QPushButton(centralWidget);
        frame_prev->setObjectName(QString::fromUtf8("frame_prev"));
        frame_prev->setGeometry(QRect(30, 340, 60, 25));
        frame_fwd = new QPushButton(centralWidget);
        frame_fwd->setObjectName(QString::fromUtf8("frame_fwd"));
        frame_fwd->setGeometry(QRect(300, 340, 60, 25));
        forward = new QPushButton(centralWidget);
        forward->setObjectName(QString::fromUtf8("forward"));
        forward->setGeometry(QRect(230, 340, 60, 25));
        previous = new QPushButton(centralWidget);
        previous->setObjectName(QString::fromUtf8("previous"));
        previous->setGeometry(QRect(100, 340, 60, 25));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(170, 340, 51, 31));
        picture1 = new QLabel(centralWidget);
        picture1->setObjectName(QString::fromUtf8("picture1"));
        picture1->setGeometry(QRect(30, 50, 331, 241));
        browse = new QLineEdit(centralWidget);
        browse->setObjectName(QString::fromUtf8("browse"));
        browse->setGeometry(QRect(20, 0, 281, 27));
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(30, 310, 331, 29));
        horizontalSlider->setOrientation(Qt::Horizontal);
        facerec->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(facerec);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 632, 25));
        facerec->setMenuBar(menuBar);
        mainToolBar = new QToolBar(facerec);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        facerec->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(facerec);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        facerec->setStatusBar(statusBar);

        retranslateUi(facerec);
        QObject::connect(frame_fwd, SIGNAL(clicked()), picture1, SLOT(update()));
        QObject::connect(frame_prev, SIGNAL(clicked()), picture1, SLOT(update()));
        QObject::connect(forward, SIGNAL(clicked()), picture1, SLOT(update()));
        QObject::connect(previous, SIGNAL(clicked()), picture1, SLOT(update()));
        QObject::connect(lineEdit, SIGNAL(editingFinished()), picture1, SLOT(clear()));
        QObject::connect(browse, SIGNAL(editingFinished()), picture1, SLOT(deleteLater()));
        QObject::connect(penny, SIGNAL(clicked()), picture2, SLOT(update()));
        QObject::connect(raj, SIGNAL(clicked()), picture2, SLOT(update()));
        QObject::connect(howard, SIGNAL(clicked()), picture2, SLOT(update()));
        QObject::connect(leonard, SIGNAL(clicked()), picture2, SLOT(update()));
        QObject::connect(sheldon, SIGNAL(clicked()), picture2, SLOT(update()));

        QMetaObject::connectSlotsByName(facerec);
    } // setupUi

    void retranslateUi(QMainWindow *facerec)
    {
        facerec->setWindowTitle(QApplication::translate("facerec", "facerec", 0, QApplication::UnicodeUTF8));
        penny->setText(QApplication::translate("facerec", "penny", 0, QApplication::UnicodeUTF8));
        sheldon->setText(QApplication::translate("facerec", "sheldon", 0, QApplication::UnicodeUTF8));
        picture2->setText(QApplication::translate("facerec", "picture 2", 0, QApplication::UnicodeUTF8));
        picture3->setText(QApplication::translate("facerec", "picture3", 0, QApplication::UnicodeUTF8));
        leonard->setText(QApplication::translate("facerec", "leonard", 0, QApplication::UnicodeUTF8));
        howard->setText(QApplication::translate("facerec", "howard", 0, QApplication::UnicodeUTF8));
        raj->setText(QApplication::translate("facerec", "Raj", 0, QApplication::UnicodeUTF8));
        frame_prev->setText(QApplication::translate("facerec", "<<", 0, QApplication::UnicodeUTF8));
        frame_fwd->setText(QApplication::translate("facerec", ">>", 0, QApplication::UnicodeUTF8));
        forward->setText(QApplication::translate("facerec", "->", 0, QApplication::UnicodeUTF8));
        previous->setText(QApplication::translate("facerec", "<-", 0, QApplication::UnicodeUTF8));
        picture1->setText(QApplication::translate("facerec", "picture1", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class facerec: public Ui_facerec {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FACEREC_H
