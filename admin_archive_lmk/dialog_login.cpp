#include "dialog_login.h"
#include "ui_dialog_login.h"
#include "ENV.h"
#include <QFileDialog>
#include <QFile>
#include <QDir>
#include <QDialog>
#include <QString>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QMessageBox>
#include <QString>
#include <QTableView>
#include <QSqlTableModel>
#include <QDebug>

Dialog_login::Dialog_login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_login)
{
    ui->setupUi(this);

    //hind question button
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    connect(this,&Dialog_login::signal_for_status ,mainwindow ,&MainWindow::slot_for_status);


}

Dialog_login::~Dialog_login()
{
    delete ui;
}

void Dialog_login::on_pushButton_clicked()
{
    QString first_line_of_file;
    QString token = ui->lineEdit->text();
    // in case admin enters
    QFile inputFile("C:/LMK_ARCHIVE/admin.txt");
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);


          first_line_of_file = in.readLine();


       inputFile.close();
    }
    if( token == first_line_of_file ){
         emit signal_for_status("admin","admin");
    }else {

    qDebug()<<"button"<<token;

    QSqlDatabase db = QSqlDatabase::database();

    db.setHostName("127.0.0.1");
    db.setUserName("postgres");
    db.setPassword("elkin");
    db.setDatabaseName("postgres");
    if(db.open()){
      qDebug()<<"open";
     QSqlQuery query;

     if(query.exec("SELECT * FROM vistitors")){
         qDebug()<<"debug";
     }
     else{
         qDebug()<<"no debug";
     }
     while (query.next()) {
            QString gotten_password_from_data_base = query.value(4).toString();
            if(token == gotten_password_from_data_base){
                 // yes it already has code in data base
                QString name = query.value(3).toString();
                QString type = query.value(1).toString();
                qDebug()<<"Name:"<<name;
                emit signal_for_status(name , type);

            }

     }
    }
    else{
        qDebug()<<"NO connection";
    }
    }
}


