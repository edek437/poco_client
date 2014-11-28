/*
 * client.cpp
 *
 *  Created on: Nov 26, 2014
 *      Author: edek437
 */

#include "Poco/Net/SocketAddress.h"
#include "Poco/Net/StreamSocket.h"
#include "Poco/StringTokenizer.h"
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

std::string token_to_string(Poco::StringTokenizer& tok) {
	std::string message="";
	for (unsigned int it = 1; it < tok.count(); it++) { //because tok[0] is command and rest is message
		message+=tok[it];
		message+=" ";
	}
	if(message.size()!=0)
		message.substr(0,message.size()-1);
	return message;
}

//TODO: add new implemented classes to factory
Option *option_factory(Poco::Net::StreamSocket& socket,
		Poco::StringTokenizer& tok) {
	if (tok[0] == "help" || tok[0] == "h")
		return new Help();
	else if (tok[0] == "quit" || tok[0] == "q")
		return new Quit(socket);
	else if (tok[0]=="who")
		return new Who(socket);
	else {
		std::cerr << "Option \"" << tok[0] << "\" doesn't exists\n";
		return NULL;
	}
}

void handle_option(std::string& option, Poco::Net::StreamSocket& socket) {
	Poco::StringTokenizer tok(option, " ",
			Poco::StringTokenizer::TOK_TRIM
					| Poco::StringTokenizer::TOK_IGNORE_EMPTY);
	Option * op = option_factory(socket, tok);
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

