/*
 * Quit.cpp
 *
 *  Created on: 27 lis 2014
 *      Author: edek437
 */

#include "Quit.h"
#include <stdlib.h>


Quit::Quit(Poco::Net::StreamSocket& sock) :
		socket(sock) {
}

void Quit::execute() {
	socket.shutdown();
	exit(0);
}
