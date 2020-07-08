QT -= gui
QT += xml xlsx

CONFIG += c++11 console
CONFIG -= app_bundle

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
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \    
    main.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../usr/local/lib/release/ -lzippp_static
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../usr/local/lib/debug/ -lzippp_static
else:unix: LIBS += -L/usr/local/lib/ -lzippp_static

INCLUDEPATH += /usr/local/include
DEPENDPATH += /usr/local/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../usr/local/lib/release/libzippp_static.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../usr/local/lib/debug/libzippp_static.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../usr/local/lib/release/zippp_static.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../usr/local/lib/debug/zippp_static.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../../../../usr/local/lib/libzippp_static.a

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += libzip

## QXlsx code for Application Qt project
#QXLSX_PARENTPATH=./QXlsx/         # current QXlsx path is . (. means curret directory)
#QXLSX_HEADERPATH=./QXlsx/header/  # current QXlsx header path is ./header/
#QXLSX_SOURCEPATH=./QXlsx/source/  # current QXlsx source path is ./source/
#include(./QXlsx/QXlsx.pri)
