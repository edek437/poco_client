/*
 * Help.cpp
 *
 *  Created on: 27 lis 2014
 *      Author: edek437
 */

#include "Help.h"
#include <iostream>

Help::Help() {
	// TODO Auto-generated constructor stub

}

void Help::execute() {
	std::cout
			<< "Options(shortcuts):\n help(h)=print this text\n"
					"quit(q)=end connection\n"
					"whoami= prints yours nick\n"
					"nick name= another client see you as name (your IP and port by default\n"
					"message(msg) name message= send to name the message (first type msg name. If you enter proper name programm will ask you to type message\n"
					"who= print who you can write to\n"
					"inbox= print new messages(chat boxes in future:)\n";
}

Help::~Help() {
	// TODO Auto-generated destructor stub
}

