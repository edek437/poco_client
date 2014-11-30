/*
 * Message.cpp
 *
 *  Created on: 27 lis 2014
 *      Author: edek437
 */

#include "Message.h"
#include <iostream>
#include "Poco/Net/SocketAddress.h"
#include "boost/regex.hpp"
#include <sstream>

Message::Message(const Poco::Net::StreamSocket& in_socket, std::string str) :
		socket(in_socket), name(str) {
}

void Message::execute() {
//step 1. checking on server if nick is avaible
	std::string message;
	char confirmation[1024];
	std::string command="msg "+name;
	char destination[128];
	std::cout<<"checking on server if client avaible\n";
	socket.sendBytes((char *) command.c_str(), command.size());
	int rec=socket.receiveBytes((char *) destination, sizeof(destination));
	destination[rec]='\0';
	std::stringstream ss;
	ss<<destination;
	const std::string cdestination=ss.str();
	std::cout<<"Received: "<<cdestination<<std::endl;
	boost::regex exp("0.0.0.0:\\d+");
	if (!boost::regex_match(cdestination,exp)) {
		std::cout <<name<< " is avaible. Please type your name\n>> ";
		return; //for now
		getline(std::cin,message);
		std::cout<<"Sending: "<<message<<std::endl;
		Poco::Net::StreamSocket dest_sock = Poco::Net::StreamSocket(Poco::Net::SocketAddress(cdestination));
		dest_sock.sendBytes((char*)message.c_str(),message.size());
		dest_sock.receiveBytes((char*)confirmation,sizeof(confirmation));
		std::cout<<confirmation<<std::endl;
	} else {
		std::cout <<name<< " is not avaible\n";
		return;
	}
}

Message::~Message() {
	// TODO Auto-generated destructor stub
}

