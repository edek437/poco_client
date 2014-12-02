/*
 * Receiver.cpp
 *
 *  Created on: 1 gru 2014
 *      Author: edek437
 */

#include "Receiver.h"
#include "Poco/Thread.h"
#include <iostream>
#include <string>
#include <sstream>
#include <boost/regex.hpp>

Receiver::Receiver(Poco::Net::StreamSocket& sock, Poco::Mutex *mut, bool *up,
		std::string *old, std::vector<std::string> *db) :
		socket(sock), mutex(mut), update(up), old_name(old), message_db(db) {
}

void Receiver::run() {
	for (;;) {
		sleep(10);
		mutex->lock();
		char message[1024];
		std::string request = "new " + *old_name;
		socket.sendBytes((char*) request.c_str(), request.size());
		int rec = socket.receiveBytes((char *) message, sizeof(message) - 1);
		message[rec] = '\0';
		std::string answer(message);
		if (answer == "No messages") {
			mutex->unlock();
		} else {
			*update = true;
			message_db->push_back(answer);
			mutex->unlock();
		}
	}

}

Receiver::~Receiver() {
	// TODO Auto-generated destructor stub
}

