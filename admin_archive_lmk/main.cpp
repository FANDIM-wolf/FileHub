#include "mainwindow.h"
#include <QSplashScreen>
#include <QApplication>
#include <QTimer>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    a.setWindowIcon(QIcon("C:/LMK_ARCHIVE/logo.ico"));
    QSplashScreen *splash = new QSplashScreen;
        splash->setPixmap(QPixmap("C:/LMK_ARCHIVE/display.png"));
        splash->show();
        QTimer::singleShot(2500,splash,SLOT(close()));
            QTimer::singleShot(2500,&w,SLOT(show()));
    //w.show();
    return a.exec();
}
