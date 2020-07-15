QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    secondwindow.cpp

HEADERS += \
    mainwindow.h \
    secondwindow.h

FORMS += \
    mainwindow.ui \
    secondwindow.ui
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../DataBase/release/ -lDataBase
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../DataBase/debug/ -lDataBase

INCLUDEPATH += $$PWD/../DataBase
DEPENDPATH += $$PWD/../DataBase

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../DataBase/release/libDataBase.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../DataBase/debug/libDataBase.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../DataBase/release/DataBase.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../DataBase/debug/DataBase.lib

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../PasswordGenerator/release/ -lPasswordGenerator
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../PasswordGenerator/debug/ -lPasswordGenerator

INCLUDEPATH += $$PWD/../PasswordGenerator
DEPENDPATH += $$PWD/../PasswordGenerator

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../PasswordGenerator/release/libPasswordGenerator.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../PasswordGenerator/debug/libPasswordGenerator.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../PasswordGenerator/release/PasswordGenerator.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../PasswordGenerator/debug/PasswordGenerator.lib

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../UsernameGenerator/release/ -lUsernameGenerator
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../UsernameGenerator/debug/ -lUsernameGenerator

INCLUDEPATH += $$PWD/../UsernameGenerator
DEPENDPATH += $$PWD/../UsernameGenerator

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../UsernameGenerator/release/libUsernameGenerator.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../UsernameGenerator/debug/libUsernameGenerator.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../UsernameGenerator/release/UsernameGenerator.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../UsernameGenerator/debug/UsernameGenerator.lib
