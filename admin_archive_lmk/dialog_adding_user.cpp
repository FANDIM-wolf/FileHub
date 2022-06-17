#include "dialog_adding_user.h"
#include "ui_dialog_adding_user.h"
#include "DataList.h"
#include "token.h"
#include <QFile>

Dialog_adding_user::Dialog_adding_user(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_adding_user)
{
    ui->setupUi(this);
    ui->comboBox->hide();
     ui->comboBox_2->addItem("Педагог","педагог");
     ui->comboBox_2->addItem("Студент","студент");
     ui->lineEdit_2->hide();

    // hide  question  button
   setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    // end of hiding
         Node* head = NULL;
             //released with linked list
             // create linked list and objects
             //get all groups from the file groups.txt
        QFile file("C:/LMK_ARCHIVE/groups.txt");

        int counter = 1 ; // for combobox elements
        if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
         while(!file.atEnd()){
             QString str = file.readLine();
             append(&head , str,counter);
            qDebug()<< str;
              //append(&head ,  "КСК 18-2",2);
             //append(&head ,  "КСК 18-3",3);
             // add all of them in comboBox

             ui->comboBox->addItem(str,str);
             //ui->comboBox->addItem(tr("КСК 18-3") , QVariant::fromValue(findNode( &head ,"КСК 18-3")));
         }
        }
        else{
            qDebug()<< "don't open file";
        }
}

Dialog_adding_user::~Dialog_adding_user()
{
    delete ui;
}

void Dialog_adding_user::on_radioButton_toggled(bool checked)
{
    if(ui->radioButton->isChecked()){
        checked = true;
               ui->comboBox->show();
           }
           else{
               ui->comboBox->hide();
           }
}


void Dialog_adding_user::on_pushButton_clicked()
{
    //QString course = ui_add_user_in_db->comboBox->itemData(index);
            QString group = ui->comboBox->currentData().toString();
            qDebug()<<group;
            QString name = ui->lineEdit->text();
            QString type = ui->comboBox_2->currentData().toString();
            QString token = get_random_token();
            qDebug()<<name<<type<<token;
            if(sizeof (name) >= 8 && (type == "студент" || type == "педагог")  ){

                QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
                db.setHostName("127.0.0.1");
                db.setUserName("postgres");
                db.setPassword("elkin");
                db.setDatabaseName("postgres");
                if(sizeof(group) < 0){
                    //in case we did not select a group
                    group = "null";
                }
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

