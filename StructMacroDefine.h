/*
 * StructMacroDefine.h
 *
 *  Created on: 2014��9��24��
 *      Author: Thoughtworks
 */

#ifndef STRUCTMACRODEFINE_H_
#define STRUCTMACRODEFINE_H_

#include "macroUndefine.h"
#define BEGIN_STRUCT(name)\
	struct name{

#define ROS_IE(type, name)\
		type name;

#define END_STRUCT()\
	};


#endif /* STRUCTMACRODEFINE_H_ */
