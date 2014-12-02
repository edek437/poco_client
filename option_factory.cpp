/*
 * option_factory.cpp
 *
 *  Created on: 2 gru 2014
 *      Author: edek437
 */
#include "option_factory.h"
#include "get_command.h"
#include <string>
#include <iostream>

Option *option_factory(Poco::Net::StreamSocket& socket, std::string& option,
		std::string *old, bool *up, std::vector<std::string> *db) {
	std::string command = get_command(option);
	if (command == "help" || command == "h")
		return new Help();
	else if (command == "quit" || command == "q")
		return new Quit(socket);
	else if (command == "who")
		return new Who(socket);
	else if (command == "nick") {
		if (option.empty()) {
			std::cout << "Wrong use of command nick: good one is nick [name]"
					<< std::endl;
			return NULL;
		}
		return new Nick(option, old, socket);
	} else if (command == "msg" || command == "message") {
		if (option.empty()) {
			std::cout
					<< "Wrong use of command message(msg): good one is msg [name] and later type message"
					<< std::endl;
			return NULL;
		}
		return new Message(socket, option);
	} else if (command == "inbox") {
		return new Inbox(db,up);
	} else if (command == "whoami") {
		std::cout << "I AM: " << *old << std::endl;
		return NULL;
	} else {
		std::cerr << "Option \"" << command << "\" doesn't exists\n";
		return NULL;
	}
}

