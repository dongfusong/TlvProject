/*
 * CodecMacroDefine.h
 *
 *  Created on: 2014Äê9ÔÂ24ÈÕ
 *      Author: Thoughtworks
 */

#ifndef CODECMACRODEFINE_H_
#define CODECMACRODEFINE_H_

#include "macroUndefine.h"
#include "SimpleMessageCodec.h"
#include "SingleIeCodec.h"


#define BEGIN_STRUCT(name)\
typedef  SingleIeCodec<name> name##MessageCodec;\
template <>\
class SingleIeCodec<name> : public SimpleMessageCodec{\
public:\
	typedef name thisType;\
	static Codec& getInstance()\
	{\
		static SingleIeCodec<name> codec;\
		return codec;\
	}\
	Getter* getCodecs()const{\
		static Getter Codecs[] =\
		{

#define ROS_IE(type, memberOfStruct)\
		OffsetCodec<type, SingleIeCodec<type>, offsetof(thisType, memberOfStruct) >::getInstance,

#define END_STRUCT()\
		0};\
		return Codecs;\
	}\
};





#endif /* CODECMACRODEFINE_H_ */
