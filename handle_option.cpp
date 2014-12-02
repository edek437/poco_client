/*
 * handle_option.cpp
 *
 *  Created on: 2 gru 2014
 *      Author: edek437
 */

#include "handle_option.h"
#include "Poco/SharedPtr.h"

void handle_option(std::string& option, Poco::Net::StreamSocket& socket,
		std::string *old, bool *up, std::vector<std::string> *db) {
	Option * op = option_factory(socket, option, old, up, db);
	Poco::SharedPtr<Option> pop(op);
	if (!op)
		return;
	op->execute();
}
