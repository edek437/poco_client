/*
 * Nick.cpp
 *
 *  Created on: 27 lis 2014
 *      Author: edek437
 */

#include "Nick.h"

Nick::Nick(const std::string& in_name, Poco::Net::StreamSocket& in_socket) :
		name(in_name), socket(in_socket) {
}

void Nick::execute() {
//TODO: send request for nick change and receive confirmation
}

Nick::~Nick() {
	// TODO Auto-generated destructor stub
}

