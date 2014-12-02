/*
 * Message.cpp
 *
 *  Created on: 27 lis 2014
 *      Author: edek437
 */

#include "Message.h"
#include <iostream>
#include "Poco/Net/SocketAddress.h"
#include <sstream>
#include <algorithm>

Message::Message(const Poco::Net::StreamSocket& in_socket, std::string str,std::vector<Person> *db,std::string *in_old) :
		socket(in_socket), name(str), message_db(db), old(in_old) {
}

void Message::execute() {
//step 1. checking on server if nick is avaible
	std::string message;
	bool confirmation;
	std::string command="msg "+name;
	std::string b;
	bool is_available;
	std::cout<<"checking on server if client available\n";
	socket.sendBytes((char *) command.c_str(), command.size());
	socket.receiveBytes((bool *) &is_available, sizeof(bool));
	is_available ? b="TRUE" : b="FALSE";
	std::cout<<"Received: "<<b<<std::endl;
	if (is_available) {
		std::cout <<name<< " is avaible. Please type your message\n>> ";
		getline(std::cin,message);
		std::string message1="msg2 <receiver>"+name+"</receiver><sender>"+*old+"</sender><message>"+message+"</message>";
		socket.sendBytes((char*)message1.c_str(),message1.size());
		socket.receiveBytes((bool*)&confirmation,sizeof(bool));
		confirmation ? b="TRUE" : b="FALSE";
		std::cout<<"Message send to server: "<<b<<std::endl;
		std::vector<Person>::iterator vit=std::find_if(message_db->begin(),message_db->end(),[&name](const Person& p)->bool{return p.name==name;});
		std::string formated_chatbox=*old+":"+message;
		if(vit==message_db->end()){
			message_db->push_back(Person(name,formated_chatbox));
		}
		else{
			vit->chatbox.push_back(formated_chatbox);
		}
	} else {
		std::cout <<name<< " is not available\n";
	}
}

Message::~Message() {
	// TODO Auto-generated destructor stub
}

