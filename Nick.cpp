/*
 * Nick.cpp
 *
 *  Created on: 27 lis 2014
 *      Author: edek437
 */

#include "Nick.h"
#include <iostream>

Nick::Nick(const std::string& in_name, Poco::Net::StreamSocket& in_socket) :
		new_name(in_name), socket(in_socket) {
}

void Nick::execute() {
//TODO: send request for nick change and receive confirmation
	std::string command="nick "+old_name+new_name;
	char answer[1024];
	socket.sendBytes((char*)command.c_str(), command.size());
	int rec=socket.receiveBytes(answer,sizeof(answer));
	answer[rec]='\0';
	std::cout<<answer<<std::endl;
	old_name=new_name;
}

std::string Nick::old_name="default";

Nick::~Nick() {
	// TODO Auto-generated destructor stub
}

