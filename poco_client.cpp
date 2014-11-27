/*
 * client.cpp
 *
 *  Created on: Nov 26, 2014
 *      Author: ztp
 */

#include "Poco/Net/SocketAddress.h"
#include "Poco/Net/StreamSocket.h"
#include "Poco/StringTokenizer.h"
#include "Poco/SharedPtr.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>

class Option {
public:
	virtual void execute()=0;
	virtual ~Option() {
	}
	;
};

class Help: public Option {
public:
	void execute() {
		std::cout
				<< "Options(shortcuts):\n help(h)=print this text\n"
						"con(c)=connect to server\n"
						"quit(q)=end connection\n"
						"nick name= another client see you as name (your IP and port by default\n"
						"msg name message= send to name the message\n"
						"who= print who you can write to\n";
	}
};

class Quit: public Option {
	Poco::Net::StreamSocket& socket;
public:
	Quit(Poco::Net::StreamSocket& sock): socket(sock){}
	void execute() {
		socket.shutdown();
		exit(0);
	}
};

class Nick: public Option{
	std::string name;
	Poco::Net::StreamSocket& socket;
public:
	Nick(const std::string& in_name,Poco::Net::StreamSocket& in_socket):name(in_name), socket(in_socket){}
	void execute(){
//TODO: send request for nick change and receive confirmation
	}
};

class Message: public Option{
	Poco::StringTokenizer& tok;
	Poco::Net::StreamSocket socket;
public:
	Message(Poco::Net::StreamSocket& in_socket, Poco::StringTokenizer& in_tok): socket(in_socket), tok(in_tok) {}
	void execute(){
//TODO: change tok into a cstring message and send it
	}
};

class Who: public Option{
	Poco::Net::StreamSocket socket;
public:
	Who(Poco::Net::StreamSocket in_socket):socket(in_socket){}
	void execute(){
//TODO: send request about people connected + data about them
	}
};
//TODO: add new implemented classes to factory
Option *option_factory(Poco::Net::StreamSocket& socket, Poco::StringTokenizer& tok){
	if (tok[0]=="help"||tok[0]=="h") return new Help();
	else if(tok[0]=="quit"||tok[0]=="q") return new Quit(socket);
	else {
		std::cerr<<"Option \""<<tok[0]<<"\" doesn't exists\n";
		return NULL;
	}
}

void handle_option(std::string& option, Poco::Net::StreamSocket& socket) {
	Poco::StringTokenizer tok(option, " ",
			Poco::StringTokenizer::TOK_TRIM
					| Poco::StringTokenizer::TOK_IGNORE_EMPTY);
	Option * op=option_factory(socket,tok);
	Poco::SharedPtr<Option> pop(op);
	if(!op) return;
	op->execute();
}


int main(int argc, char** argv) {
	std::cout << "Connecting to server" << std::endl;
	Poco::Net::SocketAddress sa("localhost", 8080);
	Poco::Net::StreamSocket socket(sa);
	std::cout
			<< "Welcome to my program. If you don't know what to do press /help"
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

