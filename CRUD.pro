TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
QT -= gui
QT += sql

SOURCES += \
        main.cpp \ \
    src/connectionmanager.cpp \
    src/executor.cpp \
    src/manipulator.cpp \
    src/processor.cpp \
    src/selector.cpp

HEADERS += \
    src/connectionmanager.h \
    src/executor.h \
    src/manipulator.h \
    src/processor.h \
    src/selector.h \
    src/crudmapper.h \
    src/crudtypes.h
