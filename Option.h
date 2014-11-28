/*
 * Option.h
 *
 *  Created on: 27 lis 2014
 *      Author: edek437
 */

#ifndef OPTION_H_
#define OPTION_H_

class Option {
public:
	virtual void execute()=0;
	virtual ~Option() {};
};
#endif /* OPTION_H_ */
