/*
 * Quit.h
 *
 *  Created on: 27 lis 2014
 *      Author: edek437
 */

#ifndef QUIT_H_
#define QUIT_H_

#include "Option.h"
#include "Poco/Net/StreamSocket.h"


class Quit: public Option {
	Poco::Net::StreamSocket socket;
public:
	Quit(Poco::Net::StreamSocket& sock);
	void execute();
};

#endif /* QUIT_H_ */
