#ifndef CONNECT_TO_DATA_BASE_H
#define CONNECT_TO_DATA_BASE_H

#include <QDialog>
#include <QDebug>
#include <QString>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QMessageBox>
#include <QString>
#include <QTableView>
#include <QSqlTableModel>


QSqlDatabase create_connection_to_DataBase(){
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

       return db;
}



#endif // CONNECT_TO_DATA_BASE_H
