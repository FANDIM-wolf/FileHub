#include "dialog_update_data.h"
#include "ui_dialog_update_data.h"
#include "ENV.h"
#include "dialog_delete.h"
#include "ui_dialog_delete.h"
QString type_of_data =" ";

Dialog_update_data::Dialog_update_data(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_update_data)
{
    ui->setupUi(this);
    // hide  question  button
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    // end of hiding

}

Dialog_update_data::~Dialog_update_data()
{
    delete ui;
}

void Dialog_update_data::on_pushButton_clicked()
{
    type_of_data = "vistitors";
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

                query->prepare("select * from vistitors order by id asc ");

                query->exec();
                modal->setQuery(*query);
                ui->tableView->setModel(modal);

             }
        else{
            qDebug()<<"unconnected";
        }
        conn.close();
}


void Dialog_update_data::on_tableView_clicked(const QModelIndex &index)
{


   if (type_of_data == "vistitors"){

    int selected_code = ui->tableView->model()->data(ui->tableView->model()->index(index.row(),0)).toInt(); //click at any cell of table ,but get data of first cell.
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
    if(type_of_data =="documents"){

        int selected_code = index.row()+1;
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
                   query->prepare("SELECT * FROM documents WHERE id=? ");
                   query->bindValue(0,selected_code); // bind

                   if(query->exec()){
                               if(query->first()){

                                  QString name_of_document =query->value(1).toString();
                                  QString group_of_user = query->value(2).toString();

                                  ui->lineEdit->setText(name_of_document);
                                  ui->lineEdit_2->setText(group_of_user);



                               }

                               }
           }
           db.close();
    }

    if(type_of_data == "books"){
        int selected_code = index.row()+1;
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
                   query->prepare("SELECT * FROM books WHERE id=? ");
                   query->bindValue(0,selected_code); // bind

                   if(query->exec()){
                               if(query->first()){

                                  QString name_of_document =query->value(1).toString();
                                  QString image = query->value(2).toString();
                                  QString description = query->value(3).toString();
                                  ui->lineEdit->setText(name_of_document);
                                  ui->lineEdit_2->setText(image);
                                  ui->lineEdit_3->setText(description);



                               }

                               }
           }
           db.close();
    }


}




void Dialog_update_data::on_pushButton_2_clicked()
{
    if(type_of_data == "vistitors"){
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
                                     QMessageBox::information(this,"Внимание!","Информация о пользователе была успешно обновлена.");
                                 }
                     //close data base
                     db.close();
      }
    }
    if(type_of_data == "documents"){
        QSqlDatabase db = QSqlDatabase::database();
          db.setHostName("127.0.0.1");
          db.setUserName("postgres");
          db.setPassword("elkin");
          db.setDatabaseName("postgres");
          if(db.open()){
              QString name = ui->lineEdit->text();
              QString group_user = ui->lineEdit_2->text();


              qDebug("open");
                          query = new QSqlQuery(db);
                        //write down sql request
                        query->prepare("UPDATE documents  SET name_file=:0 , group_user=:1  WHERE id=:2 ");

                        //bind Values
                         query->bindValue(0,name);
                         query->bindValue(1,group_user);
                         query->bindValue(2,row);

                         if(query->exec()){
                                         QMessageBox::information(this,"Внимание!","Информация была успешно обновлена.");
                                     }
                         //close data base
                         db.close();
          }
    }
    if(type_of_data == "books"){
        QSqlDatabase db = QSqlDatabase::database();
          db.setHostName("127.0.0.1");
          db.setUserName("postgres");
          db.setPassword("elkin");
          db.setDatabaseName("postgres");
          if(db.open()){
              QString name = ui->lineEdit->text();
              QString image = ui->lineEdit_2->text();
              QString description = ui->lineEdit_3->text();

              qDebug("open");
                          query = new QSqlQuery(db);
                        //write down sql request
                        query->prepare("UPDATE books  SET name=:0 , image=:1 , description=:2  WHERE id=:3 ");

                        //bind Values
                         query->bindValue(0,name);
                         query->bindValue(1,image);
                         query->bindValue(2,description);
                         query->bindValue(3,row);

                         if(query->exec()){
                                         QMessageBox::information(this,"Внимание!","Информация была успешно обновлена.");
                                     }
                         //close data base
                         db.close();
          }
    }
}


void Dialog_update_data::on_pushButton_3_clicked()
{
    type_of_data ="documents";
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    QSqlDatabase conn = QSqlDatabase::database();
        conn.setHostName("127.0.0.1");
        conn.setUserName("postgres");
        conn.setPassword("elkin");
        conn.setDatabaseName("postgres");
        if(conn.open()){


            // get model
                modal = new QSqlTableModel(this,conn);
                QSqlQuery* query = new QSqlQuery(conn);
                QSqlQueryModel * modal = new QSqlQueryModel();

                query->prepare("select * from documents order by id asc ");

                query->exec();
                modal->setQuery(*query);
                ui->tableView->setModel(modal);

             }
        else{
            qDebug()<<"unconnected";
        }
        conn.close();
}


void Dialog_update_data::on_pushButton_4_clicked()
{
    type_of_data = "books";
    ui->lineEdit_4->setText("");
    QSqlDatabase conn = QSqlDatabase::database();
        conn.setHostName("127.0.0.1");
        conn.setUserName("postgres");
        conn.setPassword("elkin");
        conn.setDatabaseName("postgres");
        if(conn.open()){


            // get model
                modal = new QSqlTableModel(this,conn);
                QSqlQuery* query = new QSqlQuery(conn);
                QSqlQueryModel * modal = new QSqlQueryModel();

                query->prepare("select * from books order by id asc ");

                query->exec();
                modal->setQuery(*query);
                ui->tableView->setModel(modal);

             }
        else{
            qDebug()<<"unconnected";
        }
        conn.close();
}


void Dialog_update_data::on_pushButton_5_clicked()
{
    dialog_delete dialog_delete;
    dialog_delete.setModal(true);

    dialog_delete.exec();
}

