/*
 * client.cpp
 *
 *  Created on: Nov 26, 2014
 *      Author: edek437
 */

#include "Poco/Net/SocketAddress.h"
#include "Poco/Net/StreamSocket.h"
#include "Poco/SharedPtr.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
#include "Help.h"
#include "Quit.h"
#include "Nick.h"
#include "Who.h"
#include "Message.h"

std::string get_command(std::string& input){ //get command and erase it from input string
	int i=0;
	std::string output;
	while(!(input[i]==' '||input.begin()+i==input.end())){
		output.push_back(input[i]);
		i++;
	}
	if(input[i]==' ')
		input.erase(0,i+1); //erasing command part form string
	else
		input.erase(0,i);
	return output;
}

//TODO: add new implemented classes to factory
Option *option_factory(Poco::Net::StreamSocket& socket,
		std::string option) {
	std::string command=get_command(option);
	if (command == "help" || command == "h")
		return new Help();
	else if (command == "quit" || command == "q")
		return new Quit(socket);
	else if (command == "who")
		return new Who(socket);
	else if (command == "nick") {
		if(option.empty()){
			std::cout<<"Wrong use of command nick: good one is nick [name]"<<std::endl;
			return NULL;
		}
		return new Nick(option, socket);
	}
	else if (command == "msg" || command == "message"){
		if(option.empty()){
			std::cout<<"Wrong use of command message(msg): good one is msg [name] and later type message"<<std::endl;
			return NULL;
		}
		return new Message(socket,option);
	}
	else {
		std::cerr << "Option \"" << command << "\" doesn't exists\n";
		return NULL;
	}
}

void handle_option(std::string& option, Poco::Net::StreamSocket& socket) {
	Option * op = option_factory(socket, option);
	Poco::SharedPtr<Option> pop(op);
	if (!op)
		return;
	op->execute();
}

int main(int argc, char** argv) {
	std::cout << "Connecting to server" << std::endl;
	Poco::Net::SocketAddress sa("localhost", 8080);
	Poco::Net::StreamSocket socket(sa);
	std::cout
			<< "Welcome to my program. If you don't know what to do press help or h"
			<< std::endl;
//TODO: do option for client
	for (;;) {
		std::string option = "";
		std::cout << "> ";
		std::getline(std::cin, option);
		handle_option(option, socket);
	}
	return 0;
}

