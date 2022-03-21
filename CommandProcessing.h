#pragma once



#include <iostream>
#include <fstream>
#include<vector>
#include<string>
//#include "GameEngine.h"
using namespace std;
class GameEngine; //((client))
//class CommandProcessor;//((target))
//class Command;
//class FileCommandProcessorAdapter;//((Adaptor))
//class FileLineReader;//((Adaptee))
class ILoggable;
class Observer;


//================================ Command ========================================================================

class Command //: public Iloggable, public Subject
{

public:
	enum class CommandType { loadmap, validatemap, addplayer, gamestart, replay, quit, none };
	string CommandName;
	string CommandEffect;
	CommandType type;
	//Constructor
	Command();
	Command(string commandInfo);
	Command(const Command& other);
	//Destructor
	~Command();
	void saveEffect(string command);
	//Assignment operator
	Command& operator =(const Command& other);
	//Stream insertion
	friend ostream& operator << (ostream& out, const Command& c);
	string GetCommandName();

	// forced implementation of ILoggable interface's function
	//string stringToLog();

};


//--------------------- CommandProcessor ((target))-----------------------
//reads commands from the console
class CommandProcessor// : public Iloggable, public Subject
{
private:

	void saveCommand(Command* command);// saves the string of the command inside the command itself and then puts it into the collection of commands.
public:
	//****************
	GameEngine* gameEnginePtr;

	// current game statesdf

	// getter and setter
	//void setState(GameState state);
	//GameState getState(GameState state){return state;
//	};
	//****************
	//GameState state;
	vector<Command*> commandObjects;
	//Constructor and Destructor
	CommandProcessor();
	CommandProcessor(const CommandProcessor& other);
	~CommandProcessor();
	virtual string readCommand();
	Command* getCommand();// uses readCommand() that gets a string from the user.
	bool validate(Command* comand);
	// checks if a certain command has been entered is a valid command in the current state of the gane engine.if its not valid the error msg will be saved in the effect of the command.
	//Assignment operator and Stream insertion
	CommandProcessor& operator =(const CommandProcessor& other);
	friend ostream& operator << (ostream& out, const CommandProcessor& cp);

	void printAllCommands();
	// forced implementation of ILoggable interface's function
	//string stringToLog();

};
//================================= FileLineReader((adaptee)) =====================================================

//class FileLineReader
//{
//	ifstream ifs;
//public:
//	string fileName;
//	FileLineReader();
//	FileLineReader(string fileName);
//	FileLineReader(const FileLineReader& other);
//	~FileLineReader();
//	//Assignment operator
//	FileLineReader& operator =(const FileLineReader& other);
//	//Stream insertion
//	friend ostream& operator << (ostream& out, const FileLineReader& f);
//	//Method that reads one line(command) from file
//	string readLineFromFile();
//
//
//};
//============================== FileCommandProcessorAdaptor ((adapter))=====================================================
// Adapter class implements the CommandProcessor .
// this class should be designed usnig the adaptor design pattern.
// class Command will do the same functionality of class CommandProcessor but it will
//read it sequentially from a saved file instead of the console.

//class FileCommandProcessorAdapter :public CommandProcessor
//{
//private:
//	// Reference to the Adaptee:
//	FileLineReader* flr;
//public:
//	//Constructors
//	FileCommandProcessorAdapter();
//	FileCommandProcessorAdapter(string filename);
//	FileCommandProcessorAdapter(const FileCommandProcessorAdapter& other);
//	//Destructor
//	~FileCommandProcessorAdapter();
//	virtual string readCommand();
//	void saveCommand(Command* command);
//};

