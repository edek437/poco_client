/*
 * Nick.h
 *
 *  Created on: 27 lis 2014
 *      Author: edek437
 */

#ifndef NICK_H_
#define NICK_H_

#include "Option.h"
#include <string>
#include "Poco/Net/StreamSocket.h"

class Nick: public Option {
	std::string name;
	Poco::Net::StreamSocket socket;
public:
	Nick(const std::string& in_name, Poco::Net::StreamSocket& in_socket);
	void execute();
	~Nick();
};
#endif /* NICK_H_ */