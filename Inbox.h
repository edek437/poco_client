/*
 * Inbox.h
 *
 *  Created on: 2 gru 2014
 *      Author: edek437
 */

#ifndef INBOX_H_
#define INBOX_H_

#include "Option.h"
#include <vector>
#include <string>

class Inbox: public Option {
	std::vector<std::string> *message_db;
	bool *new_message;
public:
	Inbox(std::vector<std::string> *message_db, bool *new_message);
	void execute();
	virtual ~Inbox();
};

#endif /* INBOX_H_ */
