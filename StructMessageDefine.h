/*
 * StructMessageDefine.h
 *
 *  Created on: 2014��9��24��
 *      Author: Thoughtworks
 */

#ifndef STRUCTMESSAGEDEFINE_H_
#define STRUCTMESSAGEDEFINE_H_
#include "CodecMacroDefine.h"

struct MyStruct
{
	_UC index;
	_UL value;
};

BEGIN_STRUCT(MyStruct)
	ROS_IE(_UC, index)
	ROS_IE(_UL, value)
END_STRUCT()




#endif /* STRUCTMESSAGEDEFINE_H_ */
