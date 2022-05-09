#include "dialog_update_data.h"
#include "ui_dialog_update_data.h"

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
    int selected_code = index.row()+1;
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

