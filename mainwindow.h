#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSystemTrayIcon>
#include <QMenu>
#include <QCheckBox>

#include <QDialog>
#include <QComboBox>
#include <QLabel>
#include <QGroupBox>
#include <QApplication>
namespace Ui {
    class MainWindow;
}
class MainWindow : public QDialog
{
    Q_OBJECT
public:
    MainWindow();
    ~MainWindow();
    void init ();
protected:
     void closeEvent(QCloseEvent *event);

 private slots:
     void setIcon();
     void iconActivated(QSystemTrayIcon::ActivationReason reason);
     void showMessage();
     void messageClicked();
     void on_pushButton_clicked();

 private:
    void createIconGroupBox();
    void createMessageGroupBox();
    void createActions();
    void createTrayIcon();

    QGroupBox *iconGroupBox;
    QLabel *iconLabel;
    QComboBox *iconComboBox;
    QCheckBox *showIconCheckBox;
    QComboBox *typeComboBox;

    QAction *minimizeAction;
    QAction *maximizeAction;
    QAction *restoreAction;
    QAction *quitAction;
    QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;

    Ui::MainWindow * ui;
    QApplication * qapp;
};

#endif // MAINWINDOW_H
