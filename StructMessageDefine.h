/*
 * StructMessageDefine.h
 *
 *  Created on: 2014��9��24��
 *      Author: Thoughtworks
 */

#include "typedefine.h"

BEGIN_STRUCT(MyStruct)
	ROS_IE(_UC, index)
	ROS_IE(_UL, value)
END_STRUCT()

BEGIN_STRUCT(MyStruct1)
	ROS_IE(_UC, index)
	ROS_IE(_UL, value)
	ROS_IE(MyStruct, text)
END_STRUCT()

#if 0
BEGIN_TLV_STRUCT(MyStruct2)
	ROS_TLV_IE(_UC, index)
	ROS_TLV_IE(_UL, value)
	ROS_TLV_IE(MyStruct, text)
END_TLV_STRUCT()
#endif
