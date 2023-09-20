#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "about.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();    

private slots:
    void on_menu_about_triggered();

    void on_menu_exit_triggered();

    void on_btn_addProg_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    About* about;
    QMovie mo_main;
};
#endif // MAINWINDOW_H
