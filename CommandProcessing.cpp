
#pragma once
#include "CommandProcessing.h"
#include "LoggingObserver.h"
#include "GameEngine.h"
#include<limits>
#include<vector>
#include<string>
#include<fstream>
#include <regex>
#include <utility>
using namespace std;

//class CommandProcessor;
//================================ Command ========================================================================

// Constructors

Command::Command() {
	CommandName = "Default";
	CommandEffect = "Default";
	type = CommandType::none;
}


Command::Command(string commandInfo) : CommandName(commandInfo), CommandEffect("no Effect") {
	regex loadMapRegex("loadmap<\\S+>");
	regex addPlayerRegex("addplayer<\\S+>");
	// initialize command type
	if( regex_match(commandInfo, loadMapRegex)){
		type = CommandType::loadmap;
	}
	else if (commandInfo=="validatemap") {
		type = CommandType::validatemap;
	}
	else if (regex_match(commandInfo, addPlayerRegex)) {
		type = CommandType::addplayer;
	}
	else if (commandInfo=="gamestart") {
		type = CommandType::gamestart;
	}
	else if (commandInfo=="replay") {
		type = CommandType::replay;
	}
	else if (commandInfo=="quit") {
		type = CommandType::quit;
	}
	else {
		type = CommandType::none;
	//	cout << "Invalid command!" << endl;
	}
}

// Destructor

Command::~Command() {
}

//Assignment operator

Command& Command::operator =(const Command& other) {
	CommandName = other.CommandName;
	CommandEffect = other.CommandEffect;
	type = other.type;
	return *this;
}

Command::Command(const Command& other) {
	CommandName = other.CommandName;
	CommandEffect = other.CommandEffect;
	type = other.type;
}

//Stream insertion

ostream& operator << (ostream& out, const Command& c) {
	out << "The command is " << c.CommandName << " and its Effect is " << c.CommandEffect << endl;
	return out;
}
string Command::GetCommandName() {
	return CommandName;
}
//  saveEffect() method can be used to save the effect of the command as a string in the Command object.
void Command::saveEffect(string effect) {
	CommandEffect = effect;
	Notify(this);              //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=>>>>>>> part 5
}
//virtual method inherited from Subject class
string Command::stringToLog() {//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=>>>>>>> part 5
	return "Command stringToLog: " + CommandEffect;
}
//-------------------------------------------------- CommandProcessor ((target))-----------------------------------------------

//Constructors
CommandProcessor::CommandProcessor(){
}
CommandProcessor::CommandProcessor(const CommandProcessor& other) {
	for (auto p : other.commandObjects) {
		Command* temp = new Command(*p);
		commandObjects.push_back(temp);
	}
}

//Destructor

CommandProcessor::~CommandProcessor() {
	//cout << "Destroying CommandProcessor." << endl;
	for (auto p : commandObjects) {
		delete p;
	}
	commandObjects.clear();
}

//Assignment operator

CommandProcessor& CommandProcessor::operator =(const CommandProcessor& other) {
	for (auto p : other.commandObjects) {
		Command* temp = new Command(*p);
		commandObjects.push_back(temp);
	}
	return *this;
}
// readCommand() reads a string from the console and
// stores the command internally in a collection of Command objects using the saveCommand() method

string CommandProcessor::readCommand() {
	cout << "Please enter a command: " << endl;
	string input;
	getline(cin, input);
	Command* command = new Command(input);
	validate(command);
	saveCommand(command);
	return input;
}

// saves the string of the command inside the command itself
// and then puts it into the collection of commands.
void CommandProcessor::saveCommand(Command* command) {
	commandObjects.push_back(command);
	Notify(this);//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=>>>>>>> part 5

}
// a public method to other objects such as the GameEngine or the Player.
Command* CommandProcessor::getCommand() {
	Command* command = new Command(readCommand());
	return command;
}
void CommandProcessor::printAllSavedCommands() {
	cout << "THE SAVED COMMANDS ARE : " << endl;
	for (Command* c : commandObjects) {
		cout << "Command Name: " << c->CommandName << " ,Command Effect: " << c->CommandEffect << endl;
	}
}
// validate() checks if a certain command has been entered is a valid command in the current state of
// the game engine. if its not valid the error msg will be saved in the effect of the command.
bool CommandProcessor::validate(Command* command) {
    	if (command->type == Command::CommandType::loadmap) {
		if (gameEnginePtr->GetState() ==   start ||gameEnginePtr->GetState() == maploaded) {
			cout << " => maploaded" << endl;
			command->saveEffect("maploaded");
			//commandObjects.push_back(command);
		return true;
		}
		else
		cout << " => Command (" + command->CommandName + ") is not a valid command in the current state of the game" << endl;
		command->saveEffect("Command (" + command->CommandName + ") is not a valid command in the current state of the game");
		//commandObjects.push_back(command);
		return false;
	}
    	else if (command->type == Command::CommandType::addplayer) {
		if (gameEnginePtr->GetState() == mapvalidated || gameEnginePtr->GetState() == playersadded) {
			//cout << " => playersadded" << endl;
			command->saveEffect("playersadded");
			//commandObjects.push_back(command);
		return true;
		}
		else
			//cout << " => Command (" + command->CommandName + ") is not a valid command in the current state of the game" << endl;
		command->saveEffect("Command (" + command->CommandName + ") is not a valid command in the current state of the game");
		//commandObjects.push_back(command);
		return false;
	}
	else if (command->type == Command::CommandType::validatemap) {
		if (gameEnginePtr->GetState() == maploaded) {
			//cout << " => mapvalidated" << endl;
			command->saveEffect("mapvalidated");
			//commandObjects.push_back(command);
		return true;
		}
		else
			//cout << " => Command (" + command->CommandName + ") is not a valid command in the current state of the game" << endl;
		command->saveEffect("Command (" + command->CommandName + ") is not a valid command in the current state of the game");
		//commandObjects.push_back(command);
		return false;
	}
	else if (command->type == Command::CommandType::gamestart) {
		if (gameEnginePtr->GetState() ==playersadded) {
			//cout << " => assignreinforcement" << endl;
			command->saveEffect("assignreinforcement");
			//commandObjects.push_back(command);
		return true;
		}
		else
			//cout << " => Command (" + command->CommandName + ") is not a valid command in the current state of the game" << endl;
		command->saveEffect("Command (" + command->CommandName + ") is not a valid command in the current state of the game");
		//commandObjects.push_back(command);
		return false;
	}
	else if (command->type == Command::CommandType::replay) {
		if (gameEnginePtr->GetState() == win) {
			//cout << " => start" << endl;
			command->saveEffect("start");
			commandObjects.push_back(command);
		return true;
		}
		else
			//cout << " => Command (" + command->CommandName + ") is not a valid command in the current state of the game" << endl;
		command->saveEffect("Command (" + command->CommandName + ") is not a valid command in the current state of the game");
		//commandObjects.push_back(command);
		return false;
	}
	else if (command->type == Command::CommandType::quit) {
		if (gameEnginePtr->GetState() == win) {
			//cout << " => exit program" << endl;
			command->saveEffect("exit program");
			//commandObjects.push_back(command);
			return true;
		}
		else
			//cout << " => Command (" + command->CommandName + ") is not a valid command in the current state of the game" << endl;
		command->saveEffect("Command (" + command->CommandName + ") is not a valid command in the current state of the game");
		//commandObjects.push_back(command);
		    return false;
	}
	if (command->CommandName != "maploaded" || command->CommandName != "validatemap" || command->CommandName != "addplayer" ||
		command->CommandName != "gamestart" || command->CommandName != "replay" || command->CommandName != "quit")
	{
		cout << "Command (" + command->CommandName + ") is not a valid command!!" << endl;
		command->saveEffect("Command (" + command->CommandName + ") is not a valid command!!");
		//commandObjects.push_back(command);
		return false;
	}
}
string CommandProcessor::stringToLog() {                      //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=>>>>>>> part 5
	return "CommandProcessor stringToLog: " + commandObjects.back()->getCommandText();
}
//================================= FileLineReader((adaptee)) =====================================================

//Constructors
FileLineReader::FileLineReader(const string& filename) {
	ifstream inFile(filename);
	this->fileName = filename; // added this
	if (!inFile) {
		cout << "File does not exist or cannot be opened.\n";
		cout << "Program will terminate.\n";
		//exit(0);
	}
	else cout << "Reading Commands from file: "+ filename << endl;
}
//Destructor
FileLineReader::~FileLineReader() {
	//cout << "Destroying FileLineReader." << endl;
}
FileLineReader::FileLineReader(const FileLineReader& other) {
	fileName = other.fileName;
}
//Assignment operator
FileLineReader& FileLineReader::operator =(const FileLineReader& other) {
	fileName = other.fileName;
	return *this;
}
//Stream insertion
ostream& operator << (ostream& out, const FileLineReader& flr) {
	out << flr.fileName << endl;
	return out;
}
// This method reads a file line by line
 void FileLineReader::readLineFromFile(string fn) {  // added the file name here as para
	ifstream ifs;     // instead of this
	ifs.open(fn);
	if (!ifs.eof()) {
		string line;
		while (getline(ifs, line)) {
			commandObjects2.push_back(line);
		}
	}ifs.close();
}
//============================== FileCommandProcessorAdapter ((adapter))=====================================================
// Constructors
FileCommandProcessorAdapter::FileCommandProcessorAdapter() {
}
FileCommandProcessorAdapter::FileCommandProcessorAdapter(FileLineReader* flr)
{ this->flrReference = flr; }

//Destructor
FileCommandProcessorAdapter::~FileCommandProcessorAdapter() {
	//cout << "Destroying FileCommandProcessorAdapter." << endl;
}
//overriding the readCommand()
string FileCommandProcessorAdapter::readCommand() {
		flrReference->readLineFromFile(flrReference->fileName);
	 for (string c : flrReference->commandObjects2) {
		 Command* command = new Command(c);
		 validate(command);
		 saveCommand(command);
}
	return "done";
}
bool FileCommandProcessorAdapter::validate(Command* command) {
	if (command->type == Command::CommandType::loadmap) {
		if (gameEnginePtr->GetState() == start || gameEnginePtr->GetState() == maploaded) {
			cout << " => maploaded" << endl;
			command->saveEffect("maploaded");
			//commandObjects.push_back(command);
			return true;
		}
		else
			cout << " => Command (" + command->CommandName + ") is not a valid command in the current state of the game" << endl;
		command->saveEffect("Command (" + command->CommandName + ") is not a valid command in the current state of the game");
		//commandObjects.push_back(command);
		return false;
	}
	else if (command->type == Command::CommandType::addplayer) {
		if (gameEnginePtr->GetState() == mapvalidated || gameEnginePtr->GetState() == playersadded) {
			//cout << " => playersadded" << endl;
			command->saveEffect("playersadded");
			//commandObjects.push_back(command);
			return true;
		}
		else
			//cout << " => Command (" + command->CommandName + ") is not a valid command in the current state of the game" << endl;
			command->saveEffect("Command (" + command->CommandName + ") is not a valid command in the current state of the game");
		//commandObjects.push_back(command);
		return false;
	}
	else if (command->type == Command::CommandType::validatemap) {
		if (gameEnginePtr->GetState() == maploaded) {
			//cout << " => mapvalidated" << endl;
			command->saveEffect("mapvalidated");
			//commandObjects.push_back(command);
			return true;
		}
		else
			//cout << " => Command (" + command->CommandName + ") is not a valid command in the current state of the game" << endl;
			command->saveEffect("Command (" + command->CommandName + ") is not a valid command in the current state of the game");
		//commandObjects.push_back(command);
		return false;
	}
	else if (command->type == Command::CommandType::gamestart) {
		if (gameEnginePtr->GetState() == playersadded) {
			//cout << " => assignreinforcement" << endl;
			command->saveEffect("assignreinforcement");
			//commandObjects.push_back(command);
			return true;
		}
		else
			//cout << " => Command (" + command->CommandName + ") is not a valid command in the current state of the game" << endl;
			command->saveEffect("Command (" + command->CommandName + ") is not a valid command in the current state of the game");
		//commandObjects.push_back(command);
		return false;
	}
	else if (command->type == Command::CommandType::replay) {
		if (gameEnginePtr->GetState() == win) {
			//cout << " => start" << endl;
			command->saveEffect("start");
			commandObjects.push_back(command);
			return true;
		}
		else
			//cout << " => Command (" + command->CommandName + ") is not a valid command in the current state of the game" << endl;
			command->saveEffect("Command (" + command->CommandName + ") is not a valid command in the current state of the game");
		//commandObjects.push_back(command);
		return false;
	}
	else if (command->type == Command::CommandType::quit) {
		if (gameEnginePtr->GetState() == win) {
			//cout << " => exit program" << endl;
			command->saveEffect("exit program");
			//commandObjects.push_back(command);
			return true;
		}
		else
			//cout << " => Command (" + command->CommandName + ") is not a valid command in the current state of the game" << endl;
			command->saveEffect("Command (" + command->CommandName + ") is not a valid command in the current state of the game");
		//commandObjects.push_back(command);
		return false;
	}
	if (command->CommandName != "maploaded" || command->CommandName != "validatemap" || command->CommandName != "addplayer" ||
		command->CommandName != "gamestart" || command->CommandName != "replay" || command->CommandName != "quit")
	{
		cout << "Command (" + command->CommandName + ") is not a valid command!!" << endl;
		command->saveEffect("Command (" + command->CommandName + ") is not a valid command!!");
		//commandObjects.push_back(command);
		return false;
	}
}
