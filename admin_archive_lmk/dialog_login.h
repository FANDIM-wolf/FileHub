#ifndef DIALOG_LOGIN_H
#define DIALOG_LOGIN_H

#include <QDialog>
#include <QString>
#include "mainwindow.h"
namespace Ui {
class Dialog_login;
}

class Dialog_login : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_login(QWidget *parent = nullptr);
    ~Dialog_login();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog_login *ui;
    MainWindow *mainwindow;
        QSqlQuery *query ;
signals:
    void signal_for_status(QString string_name , QString type);
};

#endif // DIALOG_LOGIN_H
