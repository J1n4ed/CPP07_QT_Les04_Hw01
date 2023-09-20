#include "./headers/mainwindow.h"
#include "./ui_mainwindow.h"
#include "./headers/about.h"
#include <QThread>
#include <QtGui>

bool glob_state = false;
int glob_value = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    about = new About(this);

    QPixmap pix(":/images/error");
    mo_main.setFileName(":/images/error");
    ui->lb_image->setMovie(&mo_main);
    mo_main.start();

    ui->rb_frst->setText("Радио КНПК 1");
    ui->rb_secnd->setText("Радиор КНПК 2");
    ui->rb_frst->setChecked(true);

   for (int i = 0; i < 5; ++i)
   {
       ui->cb_select->addItem("Воробышек №" + QString::number(i+1)+ ".");
   }

   ui->btn_addProg->setText("Кнопке");
   ui->btn_addProg->setCheckable(true);
   ui->btn_addProg->setStyleSheet("QPushButton{background-color:green;} QPushButton:checked{background-color:red;}");

   ui->pb_progress->setMaximum(100);
   ui->pb_progress->setMinimum(0);
   ui->pb_progress->setValue(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_menu_about_triggered()
{
    about->show();
}


void MainWindow::on_menu_exit_triggered()
{
    this->close();
}

void MainWindow::on_btn_addProg_toggled(bool checked)
{
    if (ui->pb_progress->value() == 100)
    {
        ui->pb_progress->setValue(0);
    }
    else
    {
        int val = ui->pb_progress->value() + 10;
        ui->pb_progress->setValue(val);
    }
}

