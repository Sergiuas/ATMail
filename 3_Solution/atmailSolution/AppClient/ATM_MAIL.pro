QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    interface.cpp \
    main.cpp \
    mainwindow.cpp \
    registerwindow.cpp

HEADERS += \
    interface.h \
    mainwindow.h \
    registerwindow.h

FORMS += \
    interface.ui \
    mainwindow.ui \
    registerwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imagini.qrc

DISTFILES += \
    Resources/Autentificare_off.png \
    Resources/Autentificare_on.png \
    Resources/Confirma.png \
    Resources/ContinuaBtn.png \
    Resources/ContinuaBtnOn.png \
    Resources/Email.png \
    Resources/InapoiBtn.png \
    Resources/InapoiBtnOn.png \
    Resources/Inregistrare_off.png \
    Resources/Inregistrare_on.png \
    Resources/Logo.png \
    Resources/Nume.png \
    Resources/Parola.png \
    Resources/Prenume.png \
    Resources/RegisterForm.png \
    Resources/RegisterFormbk.png \
    Resources/bg.jpg \
    Resources/hide.png \
    Resources/hideBAK.png \
    Resources/hideWhite.png \
    Resources/mail_icon.png \
    Resources/show.png \
    Resources/showBAK.png \
    Resources/showWhite.png
