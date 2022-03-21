
#pragma once
#include "CommandProcessing.h"
//#include "ILoggable.h"
//#include "Subject.h"
#include "GameEngine.h"
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
	type = CommandType::none;
}


Command::Command(string commandInfo) : CommandName(commandInfo), CommandEffect("no Effect") {
	// initialize command type
	if (commandInfo.find("loadmap") != string::npos) {
		type = CommandType::loadmap;
	}
	else if (commandInfo.find("validatemap") != string::npos) {
		type = CommandType::validatemap;
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
	else {
		type = CommandType::none;
	}  //SHOULD ADD THIS?
}

// Destructor

Command::~Command() {
	cout << "Destroying a command object." << endl;
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


//1.4 saveEffect() method can be used to save the effect of the command as a string in the Command object. 

void Command::saveEffect(string comand) {
	CommandEffect = comand;
}

// redefine the virtual method inherited from Subject class
//string Command::stringToLog() {
//	return "Current effect: " + CommandEffect;
//}

//--------------------- CommandProcessor ((target))-----------------------

//Constructors
CommandProcessor::CommandProcessor() {
	//state = GameState::maploaded;
	
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
	Command* command = new Command(input);
	saveCommand(command);
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
	Command* command = new Command(readCommand());
	//saveCommand(comand);
	return command;
}


// 1.5 validate() checks if a certain command has been entered is a valid command in the current state of 
//the game engine. if its not valid the error msg will be saved in the effect of the command.
bool CommandProcessor::validate(Command* command) {

	if (command->type == Command::CommandType::loadmap) {
		if (gameEnginePtr->GetState() ==   start || gameEnginePtr->GetState() == maploaded) {
			cout << endl << "=>loadmap <mapName> is a valid command in the current state of the game" << endl << endl;
			command->saveEffect("maploaded");
			return true;
		}
		else
			cout << endl << "=>command (" + command->CommandName + ") is not a valid command in the current state of the game" << endl << endl;
		command->saveEffect("this command (" + command->CommandName + ") is not a valid command in the current state of the game");
		    return false;
	}
	else if (command->type == Command::CommandType::validatemap) {
		if (gameEnginePtr->GetState() == maploaded) {
			cout << endl << "=>mapvalidated" << endl << endl;
			command->saveEffect("mapvalidated");
			return true;
		}
		else
			cout << endl << "=>command (" + command->CommandName + ") is not a valid command in the current state of the game" << endl << endl;
		command->saveEffect("this command (" + command->CommandName + ") is not a valid command in the current state of the game");
		    return false;

	}
	else if (command->type == Command::CommandType::addplayer) {
		if (gameEnginePtr->GetState() == mapvalidated || gameEnginePtr->GetState() == playersadded) {
			cout << endl << "=>playersadded" << endl << endl;
			command->saveEffect("playersadded");
			return true;
		}
		else
			cout << endl << "=>command (" + command->CommandName + ") is not a valid command in the current state of the game" << endl << endl;
		command->saveEffect("this command (" + command->CommandName + ") is not a valid command in the current state of the game");
		    return false;
	}
	else if (command->type == Command::CommandType::gamestart) {
		if (gameEnginePtr->GetState() ==playersadded) {
			cout << endl << "=>assignreinforcement" << endl << endl;
			command->saveEffect("assignreinforcement");
			return true;
		}
		else
			cout << endl << "=>command (" + command->CommandName + ") is not a valid command in the current state of the game" << endl << endl;
		command->saveEffect("this command (" + command->CommandName + ") is not a valid command in the current state of the game");
		    return false;
	}
	else if (command->type == Command::CommandType::replay) {
		if (gameEnginePtr->GetState() == win) {
			cout << endl << "=>start" << endl << endl;
			command->saveEffect("start");

			return true;
		}
		else
			cout << "=>command (" + command->CommandName + ") is not a valid command in the current state of the game" << endl << endl;
		command->saveEffect("this command (" + command->CommandName + ") is not a valid command in the current state of the game");
		    return false;
	}
	else if (command->type == Command::CommandType::quit) {
		if (gameEnginePtr->GetState() == win) {
			cout << endl << "=>exit program" << endl << endl;
			command->saveEffect("exit program");
			return true;
		}
		else
			cout << endl << "=>command (" + command->CommandName + ") is not a valid command in the current state of the game" << endl << endl;
		command->saveEffect("this command (" + command->CommandName + ") is not a valid command in the current state of the game");
		    return false;
	}
	if (command->CommandName != "maploaded" || command->CommandName != "validatemap" || command->CommandName != "addplayer" ||
		command->CommandName != "gamestart" || command->CommandName != "replay" || command->CommandName != "quit")
	{
		cout << endl << "=>this command (" + command->CommandName + ") is not a valid command!!" << endl << endl;
		command->saveEffect("this command (" + command->CommandName + ") is not a valid command!!");
		return false;
	}

}


void CommandProcessor::printAllCommands() {
	for (Command* c : commandObjects) {
		cout << "Command Name: " << c->CommandName << " ,Command Effect: " << c->CommandEffect << endl;
	}


}
// readFile the virtual method inherited from Subject class
//string CommandProcessor::stringToLog() {
//	return "Inputted command: " + commandObjects.back()->returnCommand();
//}

//================================= FileLineReader((adaptee)) =====================================================
//
////Constructors
//FileLineReader::FileLineReader(string filepath) {
//	ifstream inFile(filepath);
//	if (!inFile) {
//		throw "file not found exception";
//	}
//}
////Destructor
//FileLineReader::~FileLineReader() {
//	cout << "Destroying FileLineReader." << endl;
//}
//FileLineReader::FileLineReader(const FileLineReader& other) {
//	fileName = other.fileName;
//}
////Assignment operator
//FileLineReader& FileLineReader::operator =(const FileLineReader& other) {
//	fileName = other.fileName;
//	return *this;
//}
////Stream insertion
//ostream& operator << (ostream& out, const FileLineReader& flr) {
//	out << flr.fileName << endl;
//	return out;
//}
//// This method reads a file line by line
//string FileLineReader::readLineFromFile() {
//	if (!ifs.eof()) {
//		string line;
//		ifstream ifs;
//		getline(ifs, line);
//		return line;
//	}
//
//	else {
//		throw "end of the file";
//	}
//}
////============================== FileCommandProcessorAdapter ((adapter))=====================================================
//// Constructors
//FileCommandProcessorAdapter::FileCommandProcessorAdapter() {
//}
//FileCommandProcessorAdapter::FileCommandProcessorAdapter(string fileName) {
//	flr = new FileLineReader(fileName);
//}
////Destructor
//FileCommandProcessorAdapter::~FileCommandProcessorAdapter() {
//	cout << "Destroying FileCommandProcessorAdapter." << endl;
//}
//// this class is inherited from CommandProcessor, so it can overwrite the getCommand()
////and change the input source from console to file.
//void FileCommandProcessorAdapter::saveCommand(Command* command) {
//	commandObjects.push_back(command);
//}
//string FileCommandProcessorAdapter::readCommand() {
//	// use adaptee object to read commands from a file.
//	Command* command = new Command(flr->readLineFromFile());
//	saveCommand(command);
//	return flr->readLineFromFile();
//}
