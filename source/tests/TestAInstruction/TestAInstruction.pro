#-------------------------------------------------
#
# Project created by QtCreator 2015-11-12T09:23:56
#
#-------------------------------------------------

TARGET = TestAInstruction

DEFINES += SRCDIR=\\\"$$PWD/\\\"

QT       -= gui
QT       += testlib

CONFIG   -= app_bundle
CONFIG   += console \
            c++11

TEMPLATE = app

COMMON_ALL = $${PWD}/../../common

INCLUDEPATH += \
    $${COMMON_ALL}/others \
    $${COMMON_ALL}/microkernel_architecture/microkernel_modules/instructions

HEADERS += \
    $${COMMON_ALL}/others/struct_packed.h \
    $${COMMON_ALL}/microkernel_architecture/microkernel_modules/instructions/AInstruction.hpp \
    $${COMMON_ALL}/microkernel_architecture/microkernel_modules/instructions/AInstructionParameter.hpp \
    $${COMMON_ALL}/microkernel_architecture/microkernel_modules/instructions/eProgId.hpp \
    FooBarInstruction.hpp

SOURCES += \
    $${COMMON_ALL}/microkernel_architecture/microkernel_modules/instructions/AInstruction.cpp \
    $${COMMON_ALL}/microkernel_architecture/microkernel_modules/instructions/AInstructionParameter.cpp \
    FooBarInstruction.cpp \
    TestAInstruction.cpp
