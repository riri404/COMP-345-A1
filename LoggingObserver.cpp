#include "LoggingObserver.h"
#include "Orders.h"
#include "GameEngine.h"
#include <iostream>

Observer::Observer() {
    std::cout << "bla" << std::endl;
};

Observer::~Observer() {
    std::cout << "bla" << std::endl;
};

Subject::Subject() {
    observers = new std::list<Observer*>;
}

Subject::~Subject() {
    for (auto observer : *observers) delete observer;
    delete observers;
}

void Subject::Attach(Observer* o) {
    observers->push_back(o);
};

void Subject::Detach(Observer* o) {
    observers->remove(o);
};

void Subject::Notify(ILoggable* loggable) {
    for (auto i = observers->begin(); i != observers->end(); ++i) {
        (*i)->Update(loggable);
    }
};

LogObserver::~LogObserver() {
    logfile.close();
}

LogObserver::LogObserver(GameEngine* gameEngine) {
  logfile.open("gamelog.txt", std::ofstream::out);
  gameEngine->Attach(this);
  this->gameEngine = gameEngine;
  gameEngine->AttachToOrdersList(this);
  gameEngine->AttachToProcessor(this);
}

void LogObserver::Update(ILoggable* loggable) {
    logfile << loggable->stringToLog() << std::endl;
}

void LogObserver::Notify(vector<string>* playersWon, vector<string>* maps, vector<string>* players, int numOfGames, int maxTurns) {
    // logging tournament parameters
    logfile << "Tournament mode:" << endl;
    logfile << "M: ";
    for (auto map : *maps) logfile << map << " ";
    logfile << endl;
    logfile << "P: ";
    for (auto player : *players) logfile << player << " ";
    logfile << endl;
    logfile << "G: " << numOfGames << endl;
    logfile << "D: " << maxturns << endl << endl;
    // logging results
    logfile << "Results: " << endl;
    for (int i = 0; i < numOfGames; ++i) {
        logfile << "Game " << i + 1 << endl;
        for (int j = 0; j < maps->size(); ++ j) {
            string player = (*players)[i * maps->size() + j];
            logfile << "\t" << "Map: " << map << ", Won by " << player << endl;
        }
    }
}