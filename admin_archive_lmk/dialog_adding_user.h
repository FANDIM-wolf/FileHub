#ifndef DIALOG_ADDING_USER_H
#define DIALOG_ADDING_USER_H

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
namespace Ui {
class Dialog_adding_user;
}

class Dialog_adding_user : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_adding_user(QWidget *parent = nullptr);
    ~Dialog_adding_user();

private slots:
    void on_radioButton_toggled(bool checked);

    void on_pushButton_clicked();

private:
    Ui::Dialog_adding_user *ui;
    QSqlQuery *query ;
    QSqlTableModel *modal;
    int row;
};

#endif // DIALOG_ADDING_USER_H
