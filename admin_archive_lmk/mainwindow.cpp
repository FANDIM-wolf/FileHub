#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog_adding_user.h"
#include "dialogdb.h"
#include "Generate_code.h"
#include "dialog_update_data.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
        db.setHostName("127.0.0.1");
        db.setUserName("postgres");
        db.setPassword("elkin");
        db.setDatabaseName("postgres");
        if(db.open()){
         QSqlQuery* query = new QSqlQuery(db);
        //write down data about user who has signed in
        QDateTime date = QDateTime::currentDateTime();
        QString date_time = date.toString("yyyy.MM.dd");
        int code = get_code_for_row();
        query->prepare("INSERT INTO dates (id,date) VALUES (:id,:date)");
        query->bindValue(":id",code);
        query->bindValue(":date",date_time);
        if(query->exec()){
            qDebug()<<"Time is written";
        }
        else{
            qDebug()<<date_time<<code;
        }
        }

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


void MainWindow::on_pushButton_2_clicked()
{
    Dialogdb dialogdb;
    dialogdb.setModal(true);
    dialogdb.exec();
}


void MainWindow::on_pushButton_3_clicked()
{
    Dialog_update_data dialog_update_data;
      dialog_update_data.setModal(true);
      dialog_update_data.exec();
}

