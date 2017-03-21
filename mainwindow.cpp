#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QFileInfo>
#include <QPixmap>

MainWindow::MainWindow():QDialog(NULL, Qt::Tool), ui(new Ui::MainWindow){

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked(){

}

void MainWindow::init()
{
    createActions();
    createTrayIcon();
    connect(trayIcon, SIGNAL(messageClicked()), this, SLOT(messageClicked()));
    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));

    setIcon();
    trayIcon->show();
    //hide();
    ui->setupUi(this);
    QFileInfo  f = QFileInfo (":/res/resourses/LogoSQ.png");
    qDebug() << f.exists();
    ui->logo_pv->setPixmap(QPixmap(":/res/resourses/Logo-PV.png"));
    ui->logo_sq->setPixmap(QPixmap(":/res/resourses/LogoSQ.png"));
}

void MainWindow::closeEvent(QCloseEvent *event)
 {
     if (trayIcon->isVisible()) {
         QMessageBox::information(this, tr("Systray"),
                                  tr("Este progrma continuara ejecutandose "
                                     "Para cerrar el programa "
                                     "escoja <b>Cerrar</b> en el menu "
                                     "haciendo click derecho en el icono"));
         hide();
         //event->ignore();
     }
 }

//SLOTS

void MainWindow::setIcon()
 {

     QIcon icon = QIcon(":/res/resourses/logo.png");
     trayIcon->setIcon(icon);
     setWindowIcon(icon);

     trayIcon->setToolTip("Impresoras en red del punto de venta");
 }

 void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason)
 {
     switch (reason) {
     case QSystemTrayIcon::Trigger:
     case QSystemTrayIcon::DoubleClick:
        qDebug() << "doble click";
        show();
         break;
     case QSystemTrayIcon::MiddleClick:
         showMessage();
         break;
     default:
         ;
     }
 }

 void MainWindow::showMessage()
 {
     qDebug() << "mensage?";
 }

 void MainWindow::messageClicked()
 {
     qDebug() << "click";
 }


void MainWindow::createActions()
{
    minimizeAction = new QAction(tr("Mi&nimize"), this);
    connect(minimizeAction, SIGNAL(triggered()), this, SLOT(hide()));

    maximizeAction = new QAction(tr("Ma&ximize"), this);
    connect(maximizeAction, SIGNAL(triggered()), this, SLOT(showMaximized()));

    restoreAction = new QAction(tr("&Restore"), this);
    connect(restoreAction, SIGNAL(triggered()), this, SLOT(showNormal()));

    quitAction = new QAction(tr("&Cerrar"), this);
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
}



void MainWindow::createTrayIcon()
{
    trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(minimizeAction);
    trayIconMenu->addAction(maximizeAction);
    trayIconMenu->addAction(restoreAction);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(quitAction);

    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setContextMenu(trayIconMenu);
}
