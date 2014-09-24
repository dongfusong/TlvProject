/*
 * SimpleMessageCodec.h
 *
 *  Created on: 2014Äê9ÔÂ24ÈÕ
 *      Author: Thoughtworks
 */

#ifndef SIMPLEMESSAGECODEC_H_
#define SIMPLEMESSAGECODEC_H_
#include "codec.h"
#include <iostream>
using namespace std;
class SimpleMessageCodec : public Codec
{
public:
	typedef Codec& (*Getter)();

	void decode(_UC* buffer, size_t codecSize, _UC* msg){
		Buffer buf(buffer, codecSize);
		decode(buf, msg);
	}

	void decode(Buffer& buffer, _UC* msg){
		for (Getter* getter = getCodecs(); *getter != 0; getter++){
			Codec& codec = (*getter)();
			codec.decode(buffer, msg);
		}
	}
	virtual Getter* getCodecs()const = 0;
	virtual ~SimpleMessageCodec(){

	}
};




#endif /* SIMPLEMESSAGECODEC_H_ */
