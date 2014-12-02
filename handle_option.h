/*
 * handle_option.h
 *
 *  Created on: 2 gru 2014
 *      Author: edek437
 */

#ifndef HANDLE_OPTION_H_
#define HANDLE_OPTION_H_

#include "option_factory.h"

void handle_option(std::string& option, Poco::Net::StreamSocket& socket,
		std::string *old, bool *up, std::vector<std::string> *db);



#endif /* HANDLE_OPTION_H_ */
