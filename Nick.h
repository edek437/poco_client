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
	std::string *old_name;
	std::string new_name;
	Poco::Net::StreamSocket socket;
public:
	Nick(const std::string& in_name,std::string *old, Poco::Net::StreamSocket& in_socket);
	void execute();
	~Nick();
};


#endif /* NICK_H_ */
