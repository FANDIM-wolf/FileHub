#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "add_user_in_db.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
        db.setHostName("127.0.0.1");
        db.setUserName("postgres");
        db.setPassword("elkin");
        db.setDatabaseName("postgres");
        if(db.open())
               {
                qDebug("open");

            }
            else{
                qDebug("no open");
            }



        db.close();

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    add_user_in_db add_user_in_db_window;
    add_user_in_db_window.setModal(false);
    add_user_in_db_window.exec();
}

