/*
 * Nick.cpp
 *
 *  Created on: 27 lis 2014
 *      Author: edek437
 */

#include "Nick.h"
#include <iostream>

Nick::Nick(const std::string& in_name, Poco::Net::StreamSocket& in_socket) : new_name(in_name),
		socket(in_socket) {

}

void Nick::execute() {
//TODO: send request for nick change and receive confirmation
	std::string command="nick <old_name>"+old_name+"</old_name><new_name>"+new_name+"</new_name>";
	bool odp;
	bool *odpowiedz=&odp;
	socket.sendBytes((char*)command.c_str(), command.size());
	int rec=socket.receiveBytes((bool*)odpowiedz, sizeof(bool));
	if(odp){
		std::cout<<"name changed\n";
		old_name=new_name;
	}else
		std::cout<<"name already taken\n";
}

std::string Nick::old_name="default";

Nick::~Nick() {
	// TODO Auto-generated destructor stub
}

