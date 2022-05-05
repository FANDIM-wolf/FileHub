#ifndef ADD_USER_IN_DB_H
#define ADD_USER_IN_DB_H

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
class add_user_in_db;
}

class add_user_in_db : public QDialog
{
    Q_OBJECT

public:
    explicit add_user_in_db(QWidget *parent = nullptr);
    ~add_user_in_db();

private slots:
    void on_lineEdit_3_cursorPositionChanged(int arg1, int arg2);

    void on_radioButton_clicked();

    void on_radioButton_released();

    void on_radioButton_toggled(bool checked);

    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_comboBox_currentTextChanged(const QString &arg1);

private:
    Ui::add_user_in_db *ui_add_user_in_db;
    QSqlDatabase db;
    QSqlQuery *query ;
    QSqlTableModel *modal;
    int row;
};

#endif // ADD_USER_IN_DB_H
