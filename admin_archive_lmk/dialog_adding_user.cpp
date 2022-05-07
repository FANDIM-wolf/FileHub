#include "dialog_adding_user.h"
#include "ui_dialog_adding_user.h"
#include "DataList.h"
#include "token.h"
Dialog_adding_user::Dialog_adding_user(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_adding_user)
{
    ui->setupUi(this);
     ui->comboBox->hide();
     Node* head = NULL;
         //released with linked list
         // create linked list and objects
         append(&head , "КСК 18-1",1);
         append(&head ,  "КСК 18-2",2);
         append(&head ,  "КСК 18-3",3);
         // add all of them in comboBox
         ui->comboBox->addItem(tr("КСК 18-1") , QVariant::fromValue(findNode( &head ,"КСК 18-1")));
         ui->comboBox->addItem(tr("КСК 18-2") , QVariant::fromValue(findNode( &head ,"КСК 18-2")));
         ui->comboBox->addItem(tr("КСК 18-3") , QVariant::fromValue(findNode( &head ,"КСК 18-3")));
}

Dialog_adding_user::~Dialog_adding_user()
{
    delete ui;
}

void Dialog_adding_user::on_pushButton_clicked()
{
    //QString course = ui_add_user_in_db->comboBox->itemData(index);
        QString group = ui->comboBox->currentData().toString();
        qDebug()<<group;
        QString name = ui->lineEdit->text();
        QString type = ui->lineEdit_2->text();
        QString token = get_random_token();
        qDebug()<<name<<type<<token;
        if(sizeof (name) >= 8 && (type == "студент" || type == "педагог")  ){
            QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
            db.setHostName("127.0.0.1");
            db.setUserName("postgres");
            db.setPassword("elkin");
            db.setDatabaseName("postgres");
            QMessageBox::warning(this,"Login", "Данные  верны");
            if(db.open())
                      {
                       qDebug("open");
                       query = new QSqlQuery(db);
                      //write down sql request
                      query->prepare("INSERT INTO vistitors (name,group_user,type,token) VALUES (:name,:group,:type,:token)");
                       //bind Values
                       query->bindValue(":name",name);
                       query->bindValue(":group",group);
                       query->bindValue(":type",type);
                       query->bindValue(":token",token);
                       //exec sql request
                       query->exec();
                       //close data base
                  db.close();
                   }
                   else{
                       qDebug("no open");
                   }
        }
        else{
            QMessageBox::warning(this,"Login", "Данные не верны");
        }
}


void Dialog_adding_user::on_radioButton_toggled(bool checked)
{
    if(ui->radioButton->isChecked()){
           ui->comboBox->show();
       }
       else{
           ui->comboBox->hide();
       }
}

