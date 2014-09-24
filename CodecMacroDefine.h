/*
 * CodecMacroDefine.h
 *
 *  Created on: 2014Äê9ÔÂ24ÈÕ
 *      Author: Thoughtworks
 */

#ifndef CODECMACRODEFINE_H_
#define CODECMACRODEFINE_H_

#include "SimpleMessageCodec.h"
#include "macroUndefine.h"

#define BEGIN_STRUCT(name)\
class name##MessageCodec : public SimpleMessageCodec{\
public:\
	typedef name thisType;\
	Getter* getCodecs()const{\
		static Getter Codecs[] =\
		{

#define ROS_IE(type, memberOfStruct)\
		IE_Codec<type, offsetof(thisType, memberOfStruct)>::getInstance,

#define END_STRUCT()\
		0};\
		return Codecs;\
	}\
};





#endif /* CODECMACRODEFINE_H_ */
