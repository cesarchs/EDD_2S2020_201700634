QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle
QT += widgets



# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        arbolabb.cpp \
        arbolavl.cpp \
        listanivel.cpp \
        main.cpp \
        matrizdispersa.cpp \
        nodoabb.cpp \
        nodoavl.cpp \
        nodomatriz.cpp \
        nodonivel.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    arbolabb.h \
    arbolavl.h \
    listanivel.h \
    matrizdispersa.h \
    nodoabb.h \
    nodoavl.h \
    nodomatriz.h \
    nodonivel.h
