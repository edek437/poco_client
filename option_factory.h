/*
 * option_factory.h
 *
 *  Created on: 2 gru 2014
 *      Author: edek437
 */

#ifndef OPTION_FACTORY_H_
#define OPTION_FACTORY_H_

#include "Option.h"
#include "Help.h"
#include "Quit.h"
#include "Nick.h"
#include "Who.h"
#include "Message.h"
#include "Receiver.h"
#include "Inbox.h"

Option *option_factory(Poco::Net::StreamSocket& socket, std::string& option,
		std::string *old, bool *up, std::vector<std::string> *db);



#endif /* OPTION_FACTORY_H_ */
