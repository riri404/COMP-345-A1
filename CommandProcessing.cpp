#pragma once
#include "CommandProcessing.h"

#include<limits>
#include<vector>
#include<string>
#include<fstream>
using namespace std;
//================================ Command ========================================================================
// Constructors
Command::Command() {
	CommandName = "Default";
	CommandEffect = "Default";
	CommandType{};
}
Command::Command(string commandInfo) : CommandName(commandInfo), CommandEffect("") {
	//type = CommandType::none;
	// initialize command type

	if (commandInfo.find("loadmap") != string::npos) {
		type = CommandType::loadmap;
	}
	else if (commandInfo.find("validatemap") != string::npos) {
		type = CommandType::validatemap;
	}
	else if (commandInfo.find("tournament") != string::npos) {
		type = CommandType::tournament;
	}
	else if (commandInfo.find("addplayer") != string::npos) {
		type = CommandType::addplayer;
	}
	else if (commandInfo.find("gamestart") != string::npos) {
		type = CommandType::gamestart;
	}
	else if (commandInfo.find("replay") != string::npos) {
		type = CommandType::replay;
	}
	else if (commandInfo.find("quit") != string::npos) {
		type = CommandType::quit;
	}
	else if (commandInfo.find("m") != string::npos) {
		type = CommandType::m;
	}
	else if (commandInfo.find("p") != string::npos) {
		type = CommandType::p;
	}
	else if (commandInfo.find("d") != string::npos) {
		type = CommandType::d;
	}
	else if (commandInfo.find("g") != string::npos) {
		type = CommandType::g;
	}
}
// Destructor
Command::~Command() {
	cout << "Destroying a command object." << endl;
}
//Assignment operator
Command& Command::operator =(const Command& other) {
	CommandName = other.CommandName;
	CommandEffect = other.CommandEffect;
	return *this;
}
Command::Command(const Command& other) {
	CommandName = other.CommandName;
	CommandEffect = other.CommandEffect;
}
//Stream insertion
ostream& operator << (ostream& out, const Command& c) {
	out << "The command is " << c.CommandName << " and the effect is " << c.CommandEffect << endl;
	return out;
}
//1.4 saveEffect() method can be used to save the effect of the command as a string in the Command object. 
void Command::saveEffect(string com) {
	CommandEffect = com;
}
// redefine the virtual method inherited from Subject class
//string Command::stringToLog() {
//	return "Current effect: " + CommandEffect;
//}

//--------------------- CommandProcessor ((target))-----------------------

//Constructors
CommandProcessor::CommandProcessor() {
	state = GameState::start;
}

CommandProcessor::CommandProcessor(const CommandProcessor& other) {
	for (auto p : other.commandObjects) {
		Command* temp = new Command(*p);
		commandObjects.push_back(temp);
	}
}
//Destructor
CommandProcessor::~CommandProcessor() {
	cout << "Destroying CommandProcessor." << endl;
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
// 1.1 The private method readCommand() reads a string from the console and
// stores the command internally in a collection of Command objects using the saveCommand() method
string CommandProcessor::readCommand() {
	string input;
	getline(cin, input);
	return input;
}
// 1.2 saves the string of the command inside the command itself
//and then puts it into the collection of commands.
void CommandProcessor::saveCommand(Command* command) {
	commandObjects.push_back(command);

	//Notify(); //5.2.1 When a command is read, it is written in the log file. When a command is executed,
	//its effect is written in the log file.

}
// 1.3 a public method to other objects such as the GameEngine or the Player. 
Command* CommandProcessor::getCommand() {
	Command* comand = new Command(readCommand());
	saveCommand(comand);
	return comand;
}
// 1.5 validate() checks if a certain command has been entered is a valid command in the current state of 
//the gane engine. if its not valid the error msg will be saved in the effect of the command.
bool CommandProcessor::validate(Command* comand) {

	if (comand->type == Command::CommandType::loadmap) {
		if (state == GameState::start || state == GameState::map_loaded) {
			return true;
		}
	}
	else if (comand->type == Command::CommandType::validatemap) {
		if (state == GameState::map_loaded) {
			return true;
		}
	}
	else if (comand->type == Command::CommandType::tournament) {
		if (state == GameState::start) {
			return true;
		}
	}
	else if (comand->type == Command::CommandType::m) {
		if (state == GameState::tournament_mode) {
			return true;
		}
	}
	else if (comand->type == Command::CommandType::p) {
		if (state == GameState::tournament_mode) {
			return true;
		}
	}
	else if (comand->type == Command::CommandType::g) {
		if (state == GameState::tournament_mode) {
			return true;
		}
	}
	else if (comand->type == Command::CommandType::d) {
		if (state == GameState::tournament_mode) {
			return true;
		}
	}
	else if (comand->type == Command::CommandType::addplayer) {
		if (state == GameState::map_validated || state == GameState::players_added) {
			return true;
		}
	}
	else if (comand->type == Command::CommandType::gamestart) {
		if (state == GameState::players_added) {
			return true;
		}
	}
	else if (comand->type == Command::CommandType::replay) {
		if (state == GameState::win) {
			return true;
		}
	}
	else if (comand->type == Command::CommandType::quit) {
		if (state == GameState::win) {
			return true;
		}
	}
	return false;
}
void CommandProcessor::setState(GameState state) {
	state = state;
}
GameState CommandProcessor::getState()const {
	return state;
}

string Command::getCommandName() {
	return CommandName;
}

// readFile the virtual method inherited from Subject class
//string CommandProcessor::stringToLog() {
//	return "Inputted command: " + commandObjects.back()->returnCommand();
//}

//================================= FileLineReader((adaptee)) =====================================================

//Constructors
FileLineReader::FileLineReader(string filepath) {
	ifstream inFile(filepath);
	if (!inFile) {
		throw "file not found exception";
	}
}
//Destructor
FileLineReader::~FileLineReader() {
	cout << "Destroying FileLineReader." << endl;
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
string FileLineReader::readLineFromFile() {
	if (!ifs.eof()) {
		string line;
		ifstream ifs;
		getline(ifs, line);
		return line;
	}

	else {
		throw "end of the file";
	}
}
//============================== FileCommandProcessorAdaptor ((adapter))=====================================================
// Constructors
FileCommandProcessorAdapter::FileCommandProcessorAdapter() {
}
FileCommandProcessorAdapter::FileCommandProcessorAdapter(string fileName) {
	flr = new FileLineReader(fileName);
}
//Destructor
FileCommandProcessorAdapter::~FileCommandProcessorAdapter() {
	cout << "Destroying FileCommandProcessorAdapter." << endl;
}
// this class is inherited from CommandProcessor, so it can overwrite the getCommand()
//and change the input source from console to file
string FileCommandProcessorAdapter::readCommand() {
	// use adaptee object to read commands from a file
	return flr->readLineFromFile();
}