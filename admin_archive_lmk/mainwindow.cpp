#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "frameshowmessage.h"
#include "dialog_adding_user.h"
#include "dialogdb.h"
// CONTINUE TO COPY YOUR CODE FROM FILE HUB REP.
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    Dialog_adding_user add_user_in_db_window;
    add_user_in_db_window.setModal(true);
    add_user_in_db_window.exec();
}


void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{


}


void MainWindow::on_pushButton_2_clicked()
{
    DialogDB dialogdb;
    dialogdb.setModal(true);
    dialogdb.exec();
}

