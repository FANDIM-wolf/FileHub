QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add_user.cpp \
    add_user_in_db.cpp \
    connect_to_db.cpp \
    docs.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    DataListGroup.h \
    add_user.h \
    add_user_in_db.h \
    docs.h \
    mainwindow.h \
    token.h \
    validation.h

FORMS += \
    add_user_in_db.ui \
    form_add_user.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
