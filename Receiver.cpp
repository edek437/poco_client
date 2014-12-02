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
#include <algorithm>
#include <boost/regex.hpp>

Receiver::Receiver(Poco::Net::StreamSocket& sock, Poco::Mutex *mut, bool *up,
		std::string *old, std::vector<Person> *db) :
		socket(sock), mutex(mut), update(up), old_name(old), message_db(db) {
}

void Receiver::run() {
	boost::regex exp("(.*):(.*)");
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
			std::string name=boost::regex_replace(answer,exp,"\\1");
			std::vector<Person>::iterator vit;
			for(vit=message_db->begin();vit!=message_db->end();vit++){
				if(vit->name==name){ //thank you eclipse. Wasted 1,5h to repair this "mistake"
					break;
				}
			}
			if (vit==message_db->end()){ //never coresponding with name before
				message_db->push_back(Person(name,answer)); //thank you eclipse. Wasted 1,5h to repair this "mistake"
			}
			else{
				vit->chatbox.push_back(answer); //another "mistake"
				vit->is_new=true;
			}
			mutex->unlock();
		}
	}

}

Receiver::~Receiver() {
	// TODO Auto-generated destructor stub
}

