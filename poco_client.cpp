/*
 * client.cpp
 *
 *  Created on: Nov 26, 2014
 *      Author: edek437
 */

#include "Poco/Net/SocketAddress.h"
#include "Poco/Net/StreamSocket.h"
#include "Poco/Exception.h"
#include "Poco/SharedPtr.h"
#include "Poco/Thread.h"
#include <iostream>
#include <vector>
#include <string>
#include "handle_option.h"


int main(int argc, char** argv) {
	std::string serv_ip;
	if(argc==1)  serv_ip="localhost";
	else serv_ip=argv[0];
//TODO: improve this to chatbox with each person separately
//	std::vector<Person>, where struct Person {std::string name; std::vector<std::string> messagebox; FILE* file;}
	std::vector<std::string> message_db;
	bool if_new = false;
	std::cout << "Connecting to server" << std::endl;
	try {
		Poco::Net::SocketAddress sa(serv_ip, 8080);
		Poco::Net::StreamSocket socket(sa);
		std::string old_name = socket.address().toString();
		Poco::Mutex mutex;
		std::cout
				<< "Welcome to my program. If you don't know what to do press help or h"
				<< std::endl;
		Receiver rec(socket, &mutex, &if_new, &old_name, &message_db);
		Poco::Thread thread;
		thread.start(rec);
		for (;;) {
			std::string option = "";
			std::cout << "> ";
			std::getline(std::cin, option);
			mutex.lock();
			handle_option(option, socket, &old_name, &if_new, &message_db);
			if (if_new)
				std::cout
						<< "New messages waiting for you. Type inbox to read them.\n";
			mutex.unlock();
		}
		thread.join();
	} catch (Poco::Exception& e) {
		std::cout << "Sorry.Server is currently unavailable" << std::endl;
		return 0;
	}
	return 0;
}

