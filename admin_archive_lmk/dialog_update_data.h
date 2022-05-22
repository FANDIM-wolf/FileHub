#ifndef DIALOG_UPDATE_DATA_H
#define DIALOG_UPDATE_DATA_H

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
class Dialog_update_data;
}

class Dialog_update_data : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_update_data(QWidget *parent = nullptr);
    ~Dialog_update_data();

private slots:
    void on_pushButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Dialog_update_data *ui;
    QSqlQuery *query ;
    QSqlTableModel *modal;
    QSqlDatabase conn;
    int row;
};

#endif // DIALOG_UPDATE_DATA_H
