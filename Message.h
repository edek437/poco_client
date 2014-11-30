/*
 * Message.h
 *
 *  Created on: 27 lis 2014
 *      Author: edek437
 */

#ifndef MESSAGE_H_
#define MESSAGE_H_

#include "Option.h"
#include "Poco/Net/StreamSocket.h"

class Message: public Option {
	Poco::Net::StreamSocket socket;
	std::string name;

public:
	Message(const Poco::Net::StreamSocket& in_socket, std::string str);
	void execute();
	~Message();
};

#endif /* MESSAGE_H_ */
