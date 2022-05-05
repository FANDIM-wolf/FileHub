#include "add_user_in_db.h"
#include "ui_add_user_in_db.h"
#include "DataListGroup.h"
#include "token.h"
add_user_in_db::add_user_in_db(QWidget *parent) :
    QDialog(parent),
    ui_add_user_in_db(new Ui::add_user_in_db)
{

   ui_add_user_in_db->setupUi(this);
    ui_add_user_in_db->comboBox->hide();

    Node* head = NULL;
    //released with linked list
    // create linked list and objects
    append(&head , "КСК 18-1",1);
    append(&head ,  "КСК 18-2",2);
    append(&head ,  "КСК 18-3",3);
    // add all of them in comboBox
    ui_add_user_in_db->comboBox->addItem(tr("КСК 18-1") , QVariant::fromValue(findNode( &head ,"КСК 18-1")));
    ui_add_user_in_db->comboBox->addItem(tr("КСК 18-2") , QVariant::fromValue(findNode( &head ,"КСК 18-2")));
    ui_add_user_in_db->comboBox->addItem(tr("КСК 18-3") , QVariant::fromValue(findNode( &head ,"КСК 18-3")));
    //QString group; // to keep data about group of student
    //QString type;
    //QString name;

}

add_user_in_db::~add_user_in_db()
{
    delete ui_add_user_in_db;
}

void add_user_in_db::on_lineEdit_3_cursorPositionChanged(int arg1, int arg2)
{

}


void add_user_in_db::on_radioButton_clicked()
{

}


void add_user_in_db::on_radioButton_released()
{
    //ui_add_user_in_db->lineEdit_3->show();
}


void add_user_in_db::on_radioButton_toggled(bool checked)
{
   if(ui_add_user_in_db->radioButton->isChecked()){
       ui_add_user_in_db->comboBox->show();
   }
   else{
       ui_add_user_in_db->comboBox->hide();
   }

}


void add_user_in_db::on_pushButton_clicked()
{
    //QString course = ui_add_user_in_db->comboBox->itemData(index);
    QString group = ui_add_user_in_db->comboBox->currentData().toString();
    qDebug()<<group;
    QString name = ui_add_user_in_db->lineEdit->text();
    QString type = ui_add_user_in_db->lineEdit_2->text();
    QString random = get_random_token();
    qDebug()<<name<<type<<random;
    if(sizeof (name) >= 8 && (type == "студент" || type == "педагог")){
        QMessageBox::warning(this,"Login", "Данные  верны");
    }
    else{
        QMessageBox::warning(this,"Login", "Данные не верны");
    }

}


void add_user_in_db::on_comboBox_currentIndexChanged(const QString &arg1)
{
    //const QString group = ui_add_user_in_db->comboBox->currentData().toString();
}


void add_user_in_db::on_comboBox_currentTextChanged(const QString &arg1)
{

}

