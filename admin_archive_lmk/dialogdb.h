#ifndef DIALOGDB_H
#define DIALOGDB_H

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
class DialogDB;
}

class DialogDB : public QDialog
{
    Q_OBJECT

public:
    explicit DialogDB(QWidget *parent = nullptr);
    ~DialogDB();

private slots:
    void on_comboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::DialogDB *ui;
    QSqlDatabase db;
    QSqlQuery *query ;
    QSqlTableModel *modal;
    int row;
};

#endif // DIALOGDB_H
