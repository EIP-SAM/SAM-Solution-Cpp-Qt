#include "TestAFunctionalitiesManager.hpp"
#include <iostream>

//
// Constructor
//
TestAFunctionalitiesManager::TestAFunctionalitiesManager() : _mainController(NULL)
{
}

//
// Test init function
//
void TestAFunctionalitiesManager::_testInit()
{   
    ac = 1;
    av = NULL;
    _mainController = new MainController(ac, av);
    BasicFunctionalitiesManager &fctsManager = _mainController->getFctsManager();
    InstructionBus &instructionBus = _mainController->getInstructionBus();

    instructionBus.init();
    QTest::qWait(100);
    bool fctsManagerInitValue = fctsManager.init();
    QTest::qWait(100);

    QCOMPARE(fctsManagerInitValue, true);
    QCOMPARE(fctsManager.getNumberOfMicrokernelFcts(), 1);
    QCOMPARE(fctsManager.getNumberOfInternalFcts(), 1);
    QCOMPARE(fctsManager.getNumberOfExternalFcts(), 1);
    QTest::qWait(100);
    QCOMPARE(fctsManager.getNumberOfRunningFcts(), 3);

    QSignalSpy readyToDeleteSpy(&fctsManager, SIGNAL(readyToDelete()));
    fctsManager.shutdown();
}

//
// Test shutDown function
//
void TestAFunctionalitiesManager::_testShutdown()
{
    BasicFunctionalitiesManager &fctsManager = _mainController->getFctsManager();

    fctsManager.init();
    QTest::qWait(100);

    QSignalSpy readyToDeleteSpy(&fctsManager, SIGNAL(readyToDelete()));

    fctsManager.shutdown();
    QTest::qWait(500);
    QCOMPARE(readyToDeleteSpy.count(), 1);
    QCOMPARE(fctsManager.getNumberOfRunningFcts(), 0);
}

//
// Test loadLibrary function
//
void TestAFunctionalitiesManager::_testLoadLibrary()
{
    
}

//
// Test getFunctionalityType
//

void TestAFunctionalitiesManager::_testGetFunctionalityType()
{
    _mainController = new MainController(ac, av);
    BasicFunctionalitiesManager &fctsManager = _mainController->getFctsManager();

    fctsManager.init();
    QTest::qWait(500);
    
    AFunctionality::eType result = AFunctionality::INVALID;

    result = fctsManager.getFunctionalityType(AFunctionality::eClientId::NETWORK_MANAGER);
    QCOMPARE(result, AFunctionality::MICROKERNEL);
    
    result = fctsManager.getFunctionalityType(AFunctionality::eClientId::INVALID);
    QCOMPARE(result, AFunctionality::INVALID);
    
    QTest::qWait(500);
    fctsManager.shutdown();
    QTest::qWait(1000);

    delete _mainController;
}

QTEST_GUILESS_MAIN(TestAFunctionalitiesManager);
