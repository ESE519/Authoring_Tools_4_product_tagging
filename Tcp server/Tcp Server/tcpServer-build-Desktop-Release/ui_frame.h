/********************************************************************************
** Form generated from reading UI file 'frame.ui'
**
** Created: Mon Feb 25 15:06:45 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAME_H
#define UI_FRAME_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frame
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *frame)
    {
        if (frame->objectName().isEmpty())
            frame->setObjectName(QString::fromUtf8("frame"));
        frame->resize(400, 300);
        menuBar = new QMenuBar(frame);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        frame->setMenuBar(menuBar);
        mainToolBar = new QToolBar(frame);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        frame->addToolBar(mainToolBar);
        centralWidget = new QWidget(frame);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        frame->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(frame);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        frame->setStatusBar(statusBar);

        retranslateUi(frame);

        QMetaObject::connectSlotsByName(frame);
    } // setupUi

    void retranslateUi(QMainWindow *frame)
    {
        frame->setWindowTitle(QApplication::translate("frame", "frame", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class frame: public Ui_frame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAME_H
