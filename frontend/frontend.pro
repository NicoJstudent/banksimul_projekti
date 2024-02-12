QT += core gui
QT +=network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aftermenu.cpp \
    balance.cpp \
    confirmation.cpp \
    environment.cpp \
    login.cpp \
    main.cpp \
    mainmenu.cpp \
    mainwindow.cpp \
    nosto.cpp \
    othersum.cpp \
    signout.cpp \
    transactions.cpp

    transactions.cpp

HEADERS += \
    aftermenu.h \
    balance.h \
    confirmation.h \
    environment.h \
    login.h \
    mainmenu.h \
    mainwindow.h \
    nosto.h \
    othersum.h \
    signout.h \
    transactions.h

    transactions.h

FORMS += \
    aftermenu.ui \
    balance.ui \
    confirmation.ui \
    login.ui \
    mainmenu.ui \
    mainwindow.ui \
    nosto.ui \
    othersum.ui \
    signout.ui \
    transactions.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
