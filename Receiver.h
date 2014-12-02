/*
 * Receiver.h
 *
 *  Created on: 1 gru 2014
 *      Author: edek437
 */

#ifndef RECEIVER_H_
#define RECEIVER_H_

#include "Poco/Runnable.h"
#include "Poco/Net/StreamSocket.h"
#include "Poco/Mutex.h"
#include "Person.h"

class Receiver : public Poco::Runnable{
	Poco::Net::StreamSocket socket;
	Poco::Mutex *mutex;
	bool* update;
	std::string *old_name;
	std::vector<Person> *message_db;
public:
	Receiver(Poco::Net::StreamSocket& sock, Poco::Mutex *mut, bool* up,std::string *old,std::vector<Person> *db);
	void run();
	virtual ~Receiver();
};

#endif /* RECEIVER_H_ */
