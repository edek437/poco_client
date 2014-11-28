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

void Help::execute(){
	std::cout
			<< "Options(shortcuts):\n help(h)=print this text\n"
					"con(c)=connect to server\n"
					"quit(q)=end connection\n"
					"nick name= another client see you as name (your IP and port by default\n"
					"msg name message= send to name the message\n"
					"who= print who you can write to\n";
}

Help::~Help() {
	// TODO Auto-generated destructor stub
}

