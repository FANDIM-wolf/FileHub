#include "dialogdb.h"
#include "ui_dialogdb.h"

DialogDB::DialogDB(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDB)
{
    ui->setupUi(this);
    //init all elements of menu
            QString val_option_1 ="users";
            QString val_option_2 ="documents";
            // add all of them in comboBox
            ui->comboBox->addItem(tr("Показать пользователей") , QVariant::fromValue(val_option_1));
            ui->comboBox->addItem(tr("Показать документы") , QVariant::fromValue(val_option_2));
}

DialogDB::~DialogDB()
{
    delete ui;
}

void DialogDB::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("postgres");
    db.setPassword("elkin");
    db.setDatabaseName("postgres");
    if(db.open()){
    QString current_selected_option = ui->comboBox->currentData().toString();
        qDebug()<<current_selected_option;
        // get model
            modal = new QSqlTableModel(this,db);
            QSqlQuery* query = new QSqlQuery(db);
            QSqlQueryModel * modal = new QSqlQueryModel();
            if(current_selected_option == "users"){
            query->prepare("select * from vistitors ");
            }
            if(current_selected_option == "documents"){
            query->prepare("select * from documents ");
            }
            query->exec();
            modal->setQuery(*query);
            ui->tableView->setModel(modal);

         }
}

