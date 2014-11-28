/*
 * Message.cpp
 *
 *  Created on: 27 lis 2014
 *      Author: edek437
 */

#include "Message.h"

Message::Message(Poco::Net::StreamSocket& in_socket, std::string str) :
		socket(in_socket), message(str) {
}

void Message::execute() {
//TODO: change tok into a cstring message and send it
}

Message::~Message() {
	// TODO Auto-generated destructor stub
}

