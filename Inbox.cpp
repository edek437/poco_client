/*
 * Inbox.cpp
 *
 *  Created on: 2 gru 2014
 *      Author: edek437
 */

#include "Inbox.h"
#include <iostream>

Inbox::Inbox(std::vector<std::string> *db, bool *b): message_db(db), new_message(b) {
	// TODO Auto-generated constructor stub

}

void Inbox::execute(){
	for(std::vector<std::string>::iterator vit=message_db->begin();vit!=message_db->end();vit++){
		std::cout<<*vit<<std::endl;
	}
	*new_message=false;
}

Inbox::~Inbox() {
	// TODO Auto-generated destructor stub
}

