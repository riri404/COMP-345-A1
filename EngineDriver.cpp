#include <iostream>
#include "GameEngine.h"

void EngineDriver()
{
    Engine* engine;
    engine = new Engine;
    engine->StartGame();
}