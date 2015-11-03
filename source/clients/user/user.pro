################################
##                            ##
## SAM-Solution : User Client ##
##                            ##
################################

QT += \
    qml \
    quick \
    network \
    widgets

TEMPLATE = app

COMMON_ALL = $${PWD}/../../common
COMMON_CLIENTS = $${PWD}/../common

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment
include(deployment.pri)

RESOURCES += \
    qml.qrc

INCLUDEPATH += \
    $${COMMON_ALL}/microkernel_architecture/microkernel_modules/instructions \
    $${COMMON_ALL}/microkernel_architecture/microkernel_modules/functionalities \
    $${COMMON_CLIENTS}/microkernel_architecture/microkernel_modules/network_manager \
    microkernel_architecture/microkernel_modules/functionalities_manager \
    microkernel_architecture/microkernel_modules/main_controller \
    microkernel_architecture/internal_fcts_modules/gui/gui_controller

HEADERS += \
    $${COMMON_ALL}/microkernel_architecture/microkernel_modules/instructions/ANetworkInstruction.hpp \
    $${COMMON_ALL}/microkernel_architecture/microkernel_modules/instructions/AInstructionModel.hpp \
    $${COMMON_ALL}/microkernel_architecture/microkernel_modules/functionalities/AFunctionality.hpp \
    $${COMMON_ALL}/microkernel_architecture/microkernel_modules/functionalities/AFunctionalitiesManager.hpp \
    $${COMMON_CLIENTS}/microkernel_architecture/microkernel_modules/network_manager/NetworkClientManager.hpp \
    microkernel_architecture/microkernel_modules/main_controller/MainController.hpp \
    microkernel_architecture/microkernel_modules/functionalities_manager/FunctionalitiesManager.hpp \
    microkernel_architecture/internal_fcts_modules/gui/gui_controller/GUIController.hpp

SOURCES += \
    $${COMMON_ALL}/microkernel_architecture/microkernel_modules/instructions/ANetworkInstruction.cpp \
    $${COMMON_ALL}/microkernel_architecture/microkernel_modules/instructions/AInstructionModel.cpp \
    $${COMMON_ALL}/microkernel_architecture/microkernel_modules/functionalities/AFunctionality.cpp \
    $${COMMON_ALL}/microkernel_architecture/microkernel_modules/functionalities/AFunctionalitiesManager.cpp \
    $${COMMON_CLIENTS}/microkernel_architecture/microkernel_modules/network_manager/NetworkClientManager.cpp \
    microkernel_architecture/main.cpp \
    microkernel_architecture/microkernel_modules/main_controller/MainController.cpp \
    microkernel_architecture/microkernel_modules/functionalities_manager/FunctionalitiesManager.cpp \
    microkernel_architecture/internal_fcts_modules/gui/gui_controller/GUIController.cpp
