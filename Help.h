/*
 * Help.h
 *
 *  Created on: 27 lis 2014
 *      Author: edek437
 */

#ifndef HELP_H_
#define HELP_H_

#include "Option.h"

class Help: public Option {
public:
	Help();
	void execute();
	~Help();
};

#endif /* HELP_H_ */
