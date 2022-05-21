#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QString>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QMessageBox>
#include <QString>
#include <QTableView>
#include <QSqlTableModel>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool status;

public slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void slot_for_status(QString string_name);

private:
    Ui::MainWindow *ui;
    QSqlQuery *query ;
        QSqlDatabase db;
        //QSqlQuery *query ;
                QSqlTableModel *modal;
};
#endif // MAINWINDOW_H
