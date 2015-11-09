#ifndef MAIN_CONTROLLER_HPP_
# define MAIN_CONTROLLER_HPP_

# include <QCoreApplication>
# include "FunctionalitiesManager.hpp"
# include "InstructionBus.hpp"

class MainController : QObject
{
    Q_OBJECT

private:
    QCoreApplication _qtCore;
    FunctionalitiesManager _fctsManager;
    InstructionBus _instructionBus;

public:
    MainController(int &, char **);
    ~MainController();

    int run();
    InstructionBus &getInstructionBus();
};

# ifndef __MAIN_CONTROLLER_NO_GLOBAL_DECL

extern MainController *mainController;

# endif // !__MAIN_CONTROLLER_NO_GLOBAL_DECL

#endif // !MAIN_CONTROLLER_HPP_
