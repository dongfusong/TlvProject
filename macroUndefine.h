/*
 * macroUndefine.h
 *
 *  Created on: 2014Äê9ÔÂ24ÈÕ
 *      Author: Thoughtworks
 */

#ifdef BEGIN_STRUCT(name)
#undef BEGIN_STRUCT(name)
#endif


#ifdef ROS_IE(type, memberOfStruct)
#undef ROS_IE(type, memberOfStruct)
#endif


#ifdef END_STRUCT()
#undef END_STRUCT()
#endif
