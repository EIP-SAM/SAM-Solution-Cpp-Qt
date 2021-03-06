#-------------------------------------------------
#
# Project created by QtCreator 2015-11-22T15:12:27
#
#-------------------------------------------------

TARGET = TestAInstructionBusClient

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
    $${COMMON_ALL}/microkernel_architecture/microkernel_modules/instructions/AInstructionBusClient.hpp \
    $${COMMON_ALL}/microkernel_architecture/microkernel_modules/instructions/eProgId.hpp

SOURCES += \
    $${COMMON_ALL}/microkernel_architecture/microkernel_modules/instructions/AInstruction.cpp \
    $${COMMON_ALL}/microkernel_architecture/microkernel_modules/instructions/AInstructionParameter.cpp \
    $${COMMON_ALL}/microkernel_architecture/microkernel_modules/instructions/AInstructionBusClient.cpp \
    TestAInstructionBusClient.cpp
