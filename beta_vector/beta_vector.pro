TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += pvs-studio
SOURCES += main.cpp \
          fraction.cpp

HEADERS += \
    beta_vector.h \
    fraction.h
