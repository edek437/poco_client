/*
 * client.cpp
 *
 *  Created on: Nov 26, 2014
 *      Author: edek437
 */

#include "Poco/Net/SocketAddress.h"
#include "Poco/Net/StreamSocket.h"
#include "Poco/Exception.h"
#include "Poco/SharedPtr.h"
#include "Poco/Thread.h"
#include <iostream>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <string>
#include "Help.h"
#include "Quit.h"
#include "Nick.h"
#include "Who.h"
#include "Message.h"
#include "Receiver.h"
#include "Inbox.h"

//TODO: clean this mess (take functions away from main)

std::string get_command(std::string& input) { //get command and erase it from input string
	int i = 0;
	std::string output;
	while (!(input[i] == ' ' || input.begin() + i == input.end())) {
		output.push_back(input[i]);
		i++;
	}
	if (input[i] == ' ')
		input.erase(0, i + 1); //erasing command part form string
	else
		input.erase(0, i);
	return output;
}

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

void handle_option(std::string& option, Poco::Net::StreamSocket& socket,
		std::string *old, bool *up, std::vector<std::string> *db) {
	Option * op = option_factory(socket, option, old, up, db);
	Poco::SharedPtr<Option> pop(op);
	if (!op)
		return;
	op->execute();
}

int main(int argc, char** argv) {
	bool if_new = false;
//TODO: improve this to chatbox with each person separately
//	std::vector<Person>, where struct Person {std::string name; std::vector<std::string> messagebox; FILE* file;}
	std::vector<std::string> message_db;
	std::cout << "Connecting to server" << std::endl;
	try {
		Poco::Net::SocketAddress sa("localhost", 8080);
		Poco::Net::StreamSocket socket(sa);
		std::string old_name = socket.address().toString();
		Poco::Mutex mutex;
		std::cout
				<< "Welcome to my program. If you don't know what to do press help or h"
				<< std::endl;
		Receiver rec(socket, &mutex, &if_new, &old_name, &message_db);
		Poco::Thread thread;
		thread.start(rec);
		for (;;) {
			std::string option = "";
			std::cout << "> ";
			std::getline(std::cin, option);
			mutex.lock();
			handle_option(option, socket, &old_name, &if_new, &message_db);
			if (if_new)
				std::cout
						<< "New messages waiting for you. Type inbox to read them.\n";
			mutex.unlock();
		}
		thread.join();
	} catch (Poco::Exception& e) {
		std::cout << "Sorry.Server is currently unavailable" << std::endl;
		return 0;
	}
	return 0;
}

