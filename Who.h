/*
 * Who.h
 *
 *  Created on: 27 lis 2014
 *      Author: edek437
 */

#ifndef WHO_H_
#define WHO_H_

#include "Option.h"
#include "Poco/Net/StreamSocket.h"

class Who: public Option {
	Poco::Net::StreamSocket socket;
public:
	Who(Poco::Net::StreamSocket in_socket);
	void execute();
	~Who();
};

#endif /* WHO_H_ */
