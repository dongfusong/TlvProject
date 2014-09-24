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
	virtual void decode(Buffer& buffer, _UC* msg) = 0;
	virtual ~Codec(){

	}
};
class IntCodec : public Codec
{
public:
	void decode(Buffer& buffer, _UC* msg)
	{
		_UC* beginPtr = buffer.alloc(getCodecSize());
		ByteOrder::ntoh(beginPtr, getCodecSize(), msg, getTypeSize());
	}
	virtual size_t getCodecSize()const = 0;
	virtual size_t getTypeSize()const = 0;
};


template<typename T, size_t CODEC_SIZE = sizeof(T)>
class GenericCodec : public IntCodec{
public:
	static Codec& getInstance(){
		static GenericCodec codec;
		return codec;
	}

	size_t getCodecSize()const
	{
		return CODEC_SIZE;
	}
	size_t getTypeSize()const{
		return sizeof(T);
	}
};


template<typename T, typename CODEC, size_t offset = 0>
class OffsetCodec : public Codec
{
public:
	static Codec& getInstance()
	{
		static OffsetCodec codec;
		return codec;
	}
	void decode(Buffer& buffer, _UC* msg)
	{
		CODEC::getInstance().decode(buffer, msg + offset);
	}
};


#endif /* CODEC_H_ */
