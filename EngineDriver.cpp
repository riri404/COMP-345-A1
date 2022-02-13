#include <iostream>
#include "GameEngine.h"

int main()
{
    std::cout << "Starting main\n";
    Engine *engine;
    engine = new Engine;
    engine->StartupPhase();
}