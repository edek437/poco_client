/*
 * Inbox.cpp
 *
 *  Created on: 2 gru 2014
 *      Author: edek437
 */

#include "Inbox.h"
#include <iostream>

Inbox::Inbox(std::vector<Person> *db, bool *b): message_db(db), new_message(b) {
	// TODO Auto-generated constructor stub

}

void Inbox::execute(){
	std::string name;
	std::vector<Person>::iterator vit;
	for(vit=message_db->begin();vit!=message_db->end();vit++){
		std::cout<<*vit<<std::endl;
	}
	std::cout<<"Which chatbox do you want to check?\n>>";
	getline(std::cin,name);
	for(vit=message_db->begin();vit!=message_db->end();vit++){
		if(vit->name==name){
			break;
		}
	}
	if (vit==message_db->end()){ //never coresponding with name before
		std::cout<<"Sorry. You don't have chatbox with "<<name<<std::endl;}
	else{
		vit->display_contents(); //another "mistake"
		vit->is_new=false;
	}
	*new_message=false;
}

Inbox::~Inbox() {
	// TODO Auto-generated destructor stub
}

