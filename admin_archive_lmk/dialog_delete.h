#ifndef DIALOG_DELETE_H
#define DIALOG_DELETE_H


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
class dialog_delete;
}

class dialog_delete : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_delete(QWidget *parent = nullptr);
    ~dialog_delete();

private slots:
    void on_pushButton_clicked();

private:
    Ui::dialog_delete *ui;
    QSqlQuery *query ;
};

#endif // DIALOG_DELETE_H
