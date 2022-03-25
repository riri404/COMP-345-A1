#pragma once
#include <iostream>
#include <string>
#include "CommandProcessing.h"
#include "GameEngine.h"
using namespace std;
void CommandProcessorDriver() {
   
    CommandProcessor commandProcessorObj;
    commandProcessorObj.gameEnginePtr = new GameEngine();
    FileCommandProcessorAdapter* adaptor;
  
    cout << "Type >>play<< to use the (-console)" << endl;
    cout << "Or type the >>file name<< that you want to use (-file)." << endl;
    string userChoice;
    cout << endl;
    getline(cin, userChoice);
    //-----------------------------------------------------
    // 
        //************ READING FROM CONSOLE readCommand();************************ 
    if (userChoice == "play") {
        cout << "-----------------------------------------------" << endl;
        cout << ">> testing readCommand() Method FROM CONSOLE <<" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "The Current Game State Is: >>START<<" << endl;
        commandProcessorObj.gameEnginePtr->SetState(start);
        commandProcessorObj.readCommand();
        cout << "The Current Game State Is: >>MAPLOADED<<" << endl;
        commandProcessorObj.gameEnginePtr->SetState(maploaded);
        commandProcessorObj.readCommand();
        cout << "The Current Game State Is: >>WIN<<" << endl;
        commandProcessorObj.gameEnginePtr->SetState(win);
        commandProcessorObj.readCommand();
        commandProcessorObj.printAllSavedCommands();
        cout << endl;
    }
        //************ READING FROM FILE readCommand();****************************
    else {
        FileLineReader* fileLineReaderObj = new FileLineReader(userChoice + ".txt");//"commands.txt
        adaptor = new FileCommandProcessorAdapter(fileLineReaderObj);
        cout << "--------------------------------------------" << endl;
        cout << ">> testing readCommand() Method FROM file <<" << endl;
        cout << "--------------------------------------------" << endl;
       
        adaptor->gameEnginePtr = new GameEngine();
        adaptor->gameEnginePtr->SetState(start); 
      //  commandProcessorObj.gameEnginePtr = adaptor->gameEnginePtr;

       // cout << endl << "command processor engine" << commandProcessorObj.gameEnginePtr << endl;
       // cout << endl << "command processor engine" << adaptor.gameEnginePtr << endl;

        adaptor->readCommand();
        adaptor->printAllSavedCommands();
        cout << endl;
    }
         //*************** TESTING validate() METHOD ********************* here
    cout << "-------------------------------" << endl;
    cout << ">> TESTING validate() METHOD <<"<< endl;
    cout << "-------------------------------" << endl;
    cout << endl;
    cout << "State of game: START  ,Entered Command: LOADMAP<JJ> (should work)" << endl;
    commandProcessorObj.gameEnginePtr->SetState(start);
    Command command0("loadmap<JJ>");
    commandProcessorObj.validate(&command0);
    cout << endl;

    cout << "State: WIN ,Entered Command: LOADMAP<JJ> (not a valid command in the current state, should NOT work)" << endl;
    commandProcessorObj.gameEnginePtr->SetState(win);
    Command command1("loadmap<JJ>");
    commandProcessorObj.validate(&command1);
    cout << endl;

    cout << "State: WIN  ,Entered Command: FALAFEL (INVALID COMMAND should NOT work)" << endl;
    commandProcessorObj.gameEnginePtr->SetState(win);
    Command command2("falafel");
    commandProcessorObj.validate(&command2);
    cout << "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
}