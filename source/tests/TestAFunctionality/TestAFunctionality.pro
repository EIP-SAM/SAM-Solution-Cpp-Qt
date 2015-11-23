######################################################################
# Automatically generated by qmake (3.0) dim. nov. 22 22:57:51 2015
######################################################################

TARGET = TestAFunctionality

DEFINES += SRCDIR=\\\"$$PWD/\\\"

QT	+= \
	testlib \
	network

TEMPLATE = app

CONFIG	-= app_bundle
CONFIG	+= \
	console \
	c++11

COMMON_ALL = $${PWD}/../../common

SERVER_ALL = $${PWD}/../../server

INCLUDEPATH += \
	$${SERVER_ALL}/microkernel_architecture/microkernel_modules/main_controller \
	$${SERVER_ALL}/microkernel_architecture/microkernel_modules/functionalities_manager \
	$${SERVER_ALL}/microkernel_architecture/microkernel_modules/network_manager \
	$${COMMON_ALL}/microkernel_architecture/main_controller \
	$${COMMON_ALL}/others \
	$${COMMON_ALL}/qt_custom_extensions \
	$${COMMON_ALL}/microkernel_architecture/microkernel_modules/main_controller \
	$${COMMON_ALL}/microkernel_architecture/microkernel_modules/instructions \
	$${COMMON_ALL}/microkernel_architecture/microkernel_modules/functionalities

# Input
HEADERS += \
	$${SERVER_ALL}/microkernel_architecture/microkernel_modules/main_controller/MainController.hpp \
	$${SERVER_ALL}/microkernel_architecture/microkernel_modules/functionalities_manager/FunctionalitiesManager.hpp \
	$${SERVER_ALL}/microkernel_architecture/microkernel_modules/network_manager/NetworkServerManager.hpp \
	$${SERVER_ALL}/microkernel_architecture/microkernel_modules/network_manager/NetworkClient.hpp \
	$${COMMON_ALL}/microkernel_architecture/main_controller/AMainController.hpp \
	$${COMMON_ALL}/others/struct_packed.h \
	$${COMMON_ALL}/qt_custom_extensions/_QFile.hpp \
	$${COMMON_ALL}/qt_custom_extensions/_QTcpServer.hpp \
	$${COMMON_ALL}/microkernel_architecture/microkernel_modules/instructions/AInstruction.hpp \
	$${COMMON_ALL}/microkernel_architecture/microkernel_modules/instructions/InstructionBuffer.hpp \
	$${COMMON_ALL}/microkernel_architecture/microkernel_modules/instructions/InstructionBus.hpp \
	$${COMMON_ALL}/microkernel_architecture/microkernel_modules/instructions/AInstructionBusClient.hpp \
	$${COMMON_ALL}/microkernel_architecture/microkernel_modules/instructions/AInstructionParameter.hpp \
	$${COMMON_ALL}/microkernel_architecture/microkernel_modules/functionalities/AFunctionality.hpp \
	$${COMMON_ALL}/microkernel_architecture/microkernel_modules/functionalities/AFunctionalitiesManager.hpp \
	$${COMMON_ALL}/microkernel_architecture/microkernel_modules/instructions/eProgId.hpp \
	BasicAFunctionality.hpp \
	TestAFunctionality.hpp

SOURCES += \
	$${SERVER_ALL}/microkernel_architecture/microkernel_modules/main_controller/MainController.cpp \
	$${SERVER_ALL}/microkernel_architecture/microkernel_modules/functionalities_manager/FunctionalitiesManager.cpp \
	$${SERVER_ALL}/microkernel_architecture/microkernel_modules/network_manager/NetworkServerManager.cpp \
	$${SERVER_ALL}/microkernel_architecture/microkernel_modules/network_manager/NetworkClient.cpp \
	$${COMMON_ALL}/qt_custom_extensions/_QFile.cpp \
	$${COMMON_ALL}/qt_custom_extensions/_QTcpServer.cpp \
	$${COMMON_ALL}/microkernel_architecture/main_controller/AMainController.cpp \
	$${COMMON_ALL}/microkernel_architecture/microkernel_modules/instructions/AInstruction.cpp \
	$${COMMON_ALL}/microkernel_architecture/microkernel_modules/instructions/InstructionBuffer.cpp \
	$${COMMON_ALL}/microkernel_architecture/microkernel_modules/instructions/InstructionBus.cpp \
	$${COMMON_ALL}/microkernel_architecture/microkernel_modules/instructions/AInstructionBusClient.cpp \
	$${COMMON_ALL}/microkernel_architecture/microkernel_modules/instructions/AInstructionParameter.cpp \
	$${COMMON_ALL}/microkernel_architecture/microkernel_modules/functionalities/AFunctionality.cpp \
	$${COMMON_ALL}/microkernel_architecture/microkernel_modules/functionalities/AFunctionalitiesManager.cpp \
	BasicAFunctionality.cpp \
	TestAFunctionality.cpp
