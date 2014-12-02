/*
 * Person.h
 *
 *  Created on: 2 gru 2014
 *      Author: edek437
 */

#ifndef PERSON_H_
#define PERSON_H_

#include <string>
#include <vector>
#include <sstream>
#include <iostream>

struct Person{
	std::string name;
	std::vector<std::string> chatbox;
	bool is_new;

	Person(std::string& in_name, std::string& in_message, bool b=true): name(in_name), is_new(b){
		chatbox.push_back(in_message);
	}

	friend std::ostream &operator << (std::ostream& ost, const Person& P){
		std::string new_message;
		P.is_new ? new_message="NEW MESSAGE":new_message="nothing new";
		ost<<P.name+": "+new_message;
		return ost;
	}

	void display_contents(){
		std::stringstream ss;
		for(std::vector<std::string>::iterator vit=chatbox.begin();vit!=chatbox.end();vit++){
			ss<<*vit<<"\n";
		}
		std::cout<<ss.str()<<std::endl;
	}
};



#endif /* PERSON_H_ */
