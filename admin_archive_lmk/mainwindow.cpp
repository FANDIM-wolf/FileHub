#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog_adding_user.h"
#include "dialogdb.h"
#include "Generate_code.h"
#include "dialog_update_data.h"
#include "dialog_login.h"
#include "ENV.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::status = false; // as we did not sign in system
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
        db.setHostName("127.0.0.1");
        db.setUserName("postgres");
        db.setPassword("elkin");
        db.setDatabaseName("postgres");
        if(db.open()){
         QSqlQuery* query = new QSqlQuery(db);
        //write down data about user who has signed in
         QDateTime dateTime = dateTime.currentDateTime();
        QString dateTimeString = dateTime.toString("yyyy-MM-dd hh:mm:ss");
        int code = get_code_for_row();
        query->prepare("INSERT INTO dates (id,date) VALUES (:id,:date)");
        query->bindValue(":id",code);
        query->bindValue(":date",dateTimeString);
        if(query->exec()){
            qDebug()<<"Time is written"<<dateTimeString;
        }
        else{
            qDebug()<<dateTimeString<<code;
        }
        }

        ui->label_2->hide();
        ui->pushButton_3->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    Dialog_adding_user add_user_in_db_window;
    add_user_in_db_window.setModal(true);
    if(status == true){
    add_user_in_db_window.exec();
    }
    else{
        QMessageBox::information(this,"Информация!","Вы не вошли в систему.");
    }
}


void MainWindow::on_pushButton_2_clicked()
{

    Dialogdb dialogdb;
    dialogdb.setModal(true);
    if( status == true){
    dialogdb.exec();
    }
    else{
        QMessageBox::information(this,"Информация!","Вы не вошли в систему.");
    }
}


void MainWindow::on_pushButton_3_clicked()
{

    Dialog_update_data dialog_update_data;
      dialog_update_data.setModal(true);
      if(status == true){
      dialog_update_data.exec();
      }
      else{
          QMessageBox::information(this,"Информация!","Вы не вошли в систему.");
      }
}


void MainWindow::on_pushButton_4_clicked()
{
    Dialog_login dialog_login;
    dialog_login.setModal(true);

    dialog_login.exec();




}

void MainWindow::slot_for_status(QString string_name ,QString type)
{    qDebug()<<string_name<<"name";
     qDebug()<<type<<"type";
     ui->label_2->setText(string_name);
     ui->pushButton_4->hide();
     ui->label_2->show();
     if(string_name=="admin" ||(type=="admin" || type == "педагог")){
          ui->pushButton_3->show();
      }
     MainWindow::status =true;
}



