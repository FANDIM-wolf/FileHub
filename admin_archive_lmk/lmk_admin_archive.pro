QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialog_adding_user.cpp \
    dialog_update_data.cpp \
    dialogdb.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    DataList.h \
    ENV.h \
    Generate_code.h \
    dialog_adding_user.h \
    dialog_update_data.h \
    dialogdb.h \
    mainwindow.h \
    token.h

FORMS += \
    dialog_adding_user.ui \
    dialog_update_data.ui \
    dialogdb.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
