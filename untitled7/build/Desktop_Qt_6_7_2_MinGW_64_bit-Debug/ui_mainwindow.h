/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *open;
    QAction *save;
    QAction *saveas;
    QAction *newtxt;
    QAction *exit;
    QAction *copy;
    QAction *paste;
    QAction *laststep;
    QAction *cut;
    QAction *tool;
    QAction *status;
    QAction *content;
    QWidget *centralwidget;
    QTextEdit *textEdit;
    QListWidget *listWidget_1;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(771, 471);
        open = new QAction(MainWindow);
        open->setObjectName("open");
        open->setMenuRole(QAction::MenuRole::NoRole);
        save = new QAction(MainWindow);
        save->setObjectName("save");
        save->setMenuRole(QAction::MenuRole::NoRole);
        saveas = new QAction(MainWindow);
        saveas->setObjectName("saveas");
        saveas->setMenuRole(QAction::MenuRole::NoRole);
        newtxt = new QAction(MainWindow);
        newtxt->setObjectName("newtxt");
        newtxt->setMenuRole(QAction::MenuRole::NoRole);
        exit = new QAction(MainWindow);
        exit->setObjectName("exit");
        exit->setMenuRole(QAction::MenuRole::NoRole);
        copy = new QAction(MainWindow);
        copy->setObjectName("copy");
        copy->setMenuRole(QAction::MenuRole::NoRole);
        paste = new QAction(MainWindow);
        paste->setObjectName("paste");
        paste->setMenuRole(QAction::MenuRole::NoRole);
        laststep = new QAction(MainWindow);
        laststep->setObjectName("laststep");
        laststep->setMenuRole(QAction::MenuRole::NoRole);
        cut = new QAction(MainWindow);
        cut->setObjectName("cut");
        cut->setMenuRole(QAction::MenuRole::NoRole);
        tool = new QAction(MainWindow);
        tool->setObjectName("tool");
        tool->setMenuRole(QAction::MenuRole::NoRole);
        status = new QAction(MainWindow);
        status->setObjectName("status");
        status->setMenuRole(QAction::MenuRole::NoRole);
        content = new QAction(MainWindow);
        content->setObjectName("content");
        content->setMenuRole(QAction::MenuRole::NoRole);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(190, 0, 571, 311));
        listWidget_1 = new QListWidget(centralwidget);
        listWidget_1->setObjectName("listWidget_1");
        listWidget_1->setGeometry(QRect(0, 0, 181, 311));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 771, 17));
        menu = new QMenu(menuBar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName("menu_2");
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName("menu_3");
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menu->addAction(newtxt);
        menu->addAction(open);
        menu->addAction(save);
        menu->addAction(saveas);
        menu->addAction(exit);
        menu_2->addAction(cut);
        menu_2->addAction(copy);
        menu_2->addAction(paste);
        menu_2->addAction(laststep);
        menu_3->addAction(tool);
        menu_3->addAction(status);
        menu_3->addAction(content);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        open->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
#if QT_CONFIG(shortcut)
        open->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        save->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
#if QT_CONFIG(shortcut)
        save->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        saveas->setText(QCoreApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272", nullptr));
#if QT_CONFIG(shortcut)
        saveas->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        newtxt->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272", nullptr));
#if QT_CONFIG(shortcut)
        newtxt->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        exit->setText(QCoreApplication::translate("MainWindow", "\345\205\263\351\227\255", nullptr));
#if QT_CONFIG(shortcut)
        exit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+W", nullptr));
#endif // QT_CONFIG(shortcut)
        copy->setText(QCoreApplication::translate("MainWindow", "\345\244\215\345\210\266", nullptr));
#if QT_CONFIG(shortcut)
        copy->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        paste->setText(QCoreApplication::translate("MainWindow", "\347\262\230\350\264\264", nullptr));
#if QT_CONFIG(shortcut)
        paste->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        laststep->setText(QCoreApplication::translate("MainWindow", "\344\270\212\344\270\200\346\255\245", nullptr));
#if QT_CONFIG(shortcut)
        laststep->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        cut->setText(QCoreApplication::translate("MainWindow", "\345\211\252\345\210\207", nullptr));
#if QT_CONFIG(shortcut)
        cut->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        tool->setText(QCoreApplication::translate("MainWindow", "\345\267\245\345\205\267\346\240\217", nullptr));
        status->setText(QCoreApplication::translate("MainWindow", "\347\212\266\346\200\201\346\240\217", nullptr));
        content->setText(QCoreApplication::translate("MainWindow", "\347\233\256\345\275\225", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\350\247\206\345\233\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
