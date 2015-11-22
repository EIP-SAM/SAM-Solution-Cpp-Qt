######################################################################
# Automatically generated by qmake (2.01a) dim. nov. 22 03:09:07 2015
######################################################################

QT += testlib

TARGET = TestAFunctionality

DEFINES += SRCDIR=\\\"$$PWD/\\\"

QT       -= gui
QT       += testlib

CONFIG   -= app_bundle
CONFIG   += console \
            c++11 \
            x11

TEMPLATE = app

COMMON_ALL = $${PWD}/../../common

INCLUDEPATH += \
	$${PWD} \
	$${COMMON_ALL}/others \
	$${COMMON_ALL}/microkernel_architecture/microkernel_modules/functionalities \
	$${COMMON_ALL}/microkernel_architecture/microkernel_modules/instructions

# Input
HEADERS += \
	BasicAFunctionality.hpp \
	TestAFunctionality.hpp \
    $${COMMON_ALL}/others/struct_packed.h \
	$${COMMON_ALL}/microkernel_architecture/microkernel_modules/functionalities/AFunctionality.hpp \
    $${COMMON_ALL}/others/struct_packed.h \
    $${COMMON_ALL}/microkernel_architecture/microkernel_modules/instructions/AInstruction.hpp \
    $${COMMON_ALL}/microkernel_architecture/microkernel_modules/instructions/AInstructionBusClient.hpp


SOURCES += \
	BasicAfunctionality.cpp \
	TestAFunctionality.cpp \
	$${COMMON_ALL}/microkernel_architecture/microkernel_modules/functionalities/AFunctionality.cpp \
    $${COMMON_ALL}/microkernel_architecture/microkernel_modules/instructions/AInstruction.cpp \
    $${COMMON_ALL}/microkernel_architecture/microkernel_modules/instructions/AInstructionBusClient.cpp
