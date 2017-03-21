/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QLabel *logo_pv;
    QLabel *logo_sq;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;

    void setupUi(QDialog *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(444, 443);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setGeometry(QRect(0, 0, 156, 309));
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setGeometry(QRect(0, 0, 4, 12));
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setGeometry(QRect(0, 0, 3, 18));
        logo_pv = new QLabel(MainWindow);
        logo_pv->setObjectName(QStringLiteral("logo_pv"));
        logo_pv->setGeometry(QRect(130, 20, 171, 311));
        logo_sq = new QLabel(MainWindow);
        logo_sq->setObjectName(QStringLiteral("logo_sq"));
        logo_sq->setGeometry(QRect(10, 340, 100, 100));
        label = new QLabel(MainWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 400, 201, 20));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label_2 = new QLabel(MainWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(120, 380, 201, 20));
        label_2->setFont(font);
        pushButton = new QPushButton(MainWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(324, 390, 91, 23));

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QDialog *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Impresoras en red", 0));
        logo_pv->setText(QString());
        logo_sq->setText(QString());
        label->setText(QApplication::translate("MainWindow", "www.scriptquo.com.co", 0));
        label_2->setText(QApplication::translate("MainWindow", "Powered by: ScripQuo", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Ver Impresoras", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
