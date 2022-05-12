#include "dialog_update_data.h"
#include "ui_dialog_update_data.h"
#include "ENV.h"
Dialog_update_data::Dialog_update_data(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_update_data)
{
    ui->setupUi(this);

}

Dialog_update_data::~Dialog_update_data()
{
    delete ui;
}

void Dialog_update_data::on_tableView_clicked(const QModelIndex &index)
{
    int selected_code = index.row()+CORRECTING_ROW;
    row = selected_code;
    qDebug()<<row;
    QSqlDatabase db = QSqlDatabase::database();
    db.setHostName("127.0.0.1");
    db.setUserName("postgres");
    db.setPassword("elkin");
    db.setDatabaseName("postgres");
    if(db.open()){
            query = new QSqlQuery(db);
                       //write down sql request
            query->prepare("SELECT * FROM vistitors WHERE id=? ");
            query->bindValue(0,selected_code); // bind

            if(query->exec()){
                        if(query->first()){
                           QString type = query->value(1).toString();
                           QString group_user =query->value(2).toString();
                           QString name = query->value(3).toString();
                           QString token = query->value(4).toString();
                           ui->lineEdit->setText(type);
                           ui->lineEdit_2->setText(group_user);
                           ui->lineEdit_3->setText(name);
                           ui->lineEdit_4->setText(token);

                        }

                        }
    }
    db.close();
}


void Dialog_update_data::on_pushButton_3_clicked()
{
    QSqlDatabase conn = QSqlDatabase::addDatabase("QPSQL");
    conn.setHostName("127.0.0.1");
    conn.setUserName("postgres");
    conn.setPassword("elkin");
    conn.setDatabaseName("postgres");
    if(conn.open()){


        // get model
            modal = new QSqlTableModel(this,conn);
            QSqlQuery* query = new QSqlQuery(conn);
            QSqlQueryModel * modal = new QSqlQueryModel();

            query->prepare("select * from vistitors ");

            query->exec();
            modal->setQuery(*query);
            ui->tableView->setModel(modal);

         }
    conn.close();
}


void Dialog_update_data::on_pushButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::database();
    db.setHostName("127.0.0.1");
    db.setUserName("postgres");
    db.setPassword("elkin");
    db.setDatabaseName("postgres");
    if(db.open()){
        QString type = ui->lineEdit->text();
        QString group_user = ui->lineEdit_2->text();
        QString name = ui->lineEdit_3->text();
        QString token = ui->lineEdit_4->text();
        qDebug("open");
                    query = new QSqlQuery(db);
                  //write down sql request
                  query->prepare("UPDATE vistitors  SET name=:0 , token=:1 , group_user=:2 , type=:3 WHERE id=:4 ");

                  //bind Values
                   query->bindValue(0,name);
                   query->bindValue(1,token);
                   query->bindValue(2,group_user);
                   query->bindValue(3,type);
                   query->bindValue(4,row);
                   if(query->exec()){
                                   QMessageBox::information(this,"Информация!","Информация о пользователе была успешно обновлена.");
                               }
                   //close data base
                   db.close();
    }
}

