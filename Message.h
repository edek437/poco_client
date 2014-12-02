/*
 * Message.h
 *
 *  Created on: 27 lis 2014
 *      Author: edek437
 */

#ifndef MESSAGE_H_
#define MESSAGE_H_

#include "Option.h"
#include "Person.h"
#include "Poco/Net/StreamSocket.h"

class Message: public Option {
	Poco::Net::StreamSocket socket;
	std::string name;
	std::vector<Person> *message_db;
	std::string *old;
public:
	Message(const Poco::Net::StreamSocket& in_socket, std::string str,std::vector<Person> *db,std::string *in_old);
	void execute();
	~Message();
};

#endif /* MESSAGE_H_ */
