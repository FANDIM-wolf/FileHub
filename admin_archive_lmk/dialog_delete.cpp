#include "dialog_delete.h"
#include "ui_dialog_delete.h"

dialog_delete::dialog_delete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_delete)
{
    ui->setupUi(this);
}

dialog_delete::~dialog_delete()
{
    delete ui;
}

void dialog_delete::on_pushButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::database();
      db.setHostName("127.0.0.1");
      db.setUserName("postgres");
      db.setPassword("elkin");
      db.setDatabaseName("postgres");
      if(db.open()){
          QString name = ui->lineEdit->text();

            QSqlQuery query;

          qDebug()<<"open";


         if(query.exec("SELECT * FROM vistitors")){
             qDebug()<<"debug";
         }
         else{
             qDebug()<<"no debug";
         }
         while (query.next()) {
                QString gotten_name_from_data_base = query.value(3).toString();
                if(name == gotten_name_from_data_base){
                     // yes it already has code in data base

                    qDebug()<<"Name:"<<name;

                  QSqlQuery query_delete;
                  //write down sql request
                  query_delete.prepare("DELETE FROM vistitors WHERE name=:0 ");

                  //bind Values
                   query_delete.bindValue(0,name);

                   if(query_delete.exec()){
                                   QMessageBox::information(this,"Внимание!","Информация о пользователе была успешно обновлена.");
                               }

                }

         }




                     //close data base
                     db.close();
      }
}

