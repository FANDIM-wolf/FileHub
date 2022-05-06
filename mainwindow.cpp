#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "add_user_in_db.h"
#include "connect_to_db.cpp"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    //first connect to data base
    /*
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
        db.setHostName("127.0.0.1");
        db.setUserName("postgres");
        db.setPassword("elkin");
        db.setDatabaseName("postgres");
        if(db.open())
               {
                qDebug("open");

            }
            else{
                qDebug("no open");
            }



        db.close();
        */
        //init all elements of menu
        QString val_option_1 ="users";
        QString val_option_2 ="documents";
        // add all of them in comboBox
        ui->comboBox->addItem(tr("Показать пользователей") , QVariant::fromValue(val_option_1));
        ui->comboBox->addItem(tr("Показать документы") , QVariant::fromValue(val_option_2));


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    add_user_in_db add_user_in_db_window;
    add_user_in_db_window.setModal(false);
    add_user_in_db_window.exec();
}


void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QSqlDatabase  db = create_connection_to_DataBase();
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

        db.close();
}

