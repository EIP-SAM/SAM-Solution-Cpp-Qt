#include "BasicFunctionalitiesManager.hpp"

//
// Constructor
//
BasicFunctionalitiesManager::BasicFunctionalitiesManager(QObject *parent)
    : AFunctionalitiesManager(parent)
{
}

//
// Destructor
//
BasicFunctionalitiesManager::~BasicFunctionalitiesManager()
{
}

//
// Return how many functionalities are currently running
//
int BasicFunctionalitiesManager::getNumberOfRunningFcts() const
{
    return _runningFcts.count();
}

//
// Return how many microkernel functionalities there are
//
int BasicFunctionalitiesManager::getNumberOfMicrokernelFcts() const
{
    return _microkernelFcts.count();
}

//
// Return how many internal functionalities there are
//
int BasicFunctionalitiesManager::getNumberOfInternalFcts() const
{
    return _internalFcts.count();
}

//
// Return how many external functionalities there are
//
int BasicFunctionalitiesManager::getNumberOfExternalFcts() const
{
    return _externalFcts.count();
}

//
// Instanciate the various functionalities
//
void BasicFunctionalitiesManager::_setFcts()
{
    _setMicrokernelFcts();
    _setInternalFcts();
    _setExternalFcts();
}

//
// Instanciate the microkernel functionalities, here 1 for the test
//
void BasicFunctionalitiesManager::_setMicrokernelFcts()
{
    _microkernelFcts << new BasicAFunctionality(AFunctionality::NETWORK_MANAGER, true);
}

//
// Instanciate the internal functionalities, here 2 for the test
//
void BasicFunctionalitiesManager::_setInternalFcts()
{
    _internalFcts << new BasicAFunctionality(AFunctionality::ALL, true);
}

//
// Instanciate the external functionalities, here 3 for the test
//
void BasicFunctionalitiesManager::_setExternalFcts()
{
    _externalFcts << new BasicAFunctionality(AFunctionality::GUI, true);

}
