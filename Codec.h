/*
 * Codec.h
 *
 *  Created on: 2014Äê9ÔÂ24ÈÕ
 *      Author: Thoughtworks
 */

#ifndef CODEC_H_
#define CODEC_H_
#include "Buffer.h"
#include "byteOrder.h"

class Codec
{
public:
	void decode(Buffer& buffer, _UC* msg)
	{
		_UC* beginPtr = buffer.alloc(getCodecSize());
		ByteOrder::ntoh(beginPtr, msg, getCodecSize());
	}
	virtual ~Codec(){

	}
	virtual size_t getCodecSize()const = 0;
};

template<typename T>
class GenericCodec : public Codec{
public:
	size_t getCodecSize()const
	{
		return sizeof(T);
	}
};


template <typename T>
class IE_Codec : public GenericCodec<T>{
public:
	static Codec& getInstance(){
		static IE_Codec codec;
		return codec;
	}
};




#endif /* CODEC_H_ */
