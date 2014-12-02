/*
 * Message.cpp
 *
 *  Created on: 27 lis 2014
 *      Author: edek437
 */

#include "Message.h"
#include <iostream>
#include "Poco/Net/SocketAddress.h"
#include <sstream>

Message::Message(const Poco::Net::StreamSocket& in_socket, std::string str) :
		socket(in_socket), name(str) {
}

void Message::execute() {
//step 1. checking on server if nick is avaible
	std::string message;
	bool confirmation;
	std::string command="msg "+name;
	std::string b;
	bool is_available;
	std::cout<<"checking on server if client available\n";
	socket.sendBytes((char *) command.c_str(), command.size());
	socket.receiveBytes((bool *) &is_available, sizeof(bool));
	is_available ? b="TRUE" : b="FALSE";
	std::cout<<"Received: "<<b<<std::endl;
	if (is_available) {
		std::cout <<name<< " is avaible. Please type your message\n>> ";
		getline(std::cin,message);
		message="msg2 "+name+":"+message;
		std::cout<<"Sending: "<<message<<std::endl;
		socket.sendBytes((char*)message.c_str(),message.size());
		std::cout<<"message sent"<<std::endl;
		socket.receiveBytes((bool*)&confirmation,sizeof(bool));
		confirmation ? b="TRUE" : b="FALSE";
		std::cout<<"Message send to server: "<<b<<std::endl;
	} else {
		std::cout <<name<< " is not available\n";
	}
}

Message::~Message() {
	// TODO Auto-generated destructor stub
}

