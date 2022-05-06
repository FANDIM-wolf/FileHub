#include "add_user_in_db.h";

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
