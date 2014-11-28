/*
 * Who.cpp
 *
 *  Created on: 27 lis 2014
 *      Author: edek437
 */

#include "Who.h"
#include <string>
#include <iostream>
#include <string.h>

Who::Who(Poco::Net::StreamSocket in_socket) :
		socket(in_socket) {
}

void Who::execute() {
//TODO: send request about people connected + data about them
//TODO: make it more safe (what if we get more than 1024 bytes?)
	char command[]="who";
	char * answer[1024];
	socket.sendBytes((char*)command, strlen(command));
	int rec=socket.receiveBytes(answer,sizeof(answer));
	answer[rec]='\0';
	std::cout<<answer<<std::endl;
}

Who::~Who() {
	// TODO Auto-generated destructor stub
}

