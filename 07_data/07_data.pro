TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS -= -std=gnu++1z
QMAKE_CXXFLAGS += -std=gnu++17

SOURCES += \
        data.cpp \
        main.cpp

HEADERS += \
    data.h
