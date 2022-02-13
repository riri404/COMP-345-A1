#include <iostream>
#include "GameEngine.h"

void EngineDriver()
{
    std::cout << "Starting main\n";
    Engine *engine;
    engine = new Engine;
    engine->StartupPhase();
}