/*
 * SingleIeCodec.h
 *
 *  Created on: 2014Äê9ÔÂ24ÈÕ
 *      Author: Thoughtworks
 */

#ifndef SINGLEIECODEC_H_
#define SINGLEIECODEC_H_
template<typename T>
class SingleIeCodec
{
};

#define _IMPL_SINGLEIE_CODEC(type)\
template<>\
class SingleIeCodec<type> : public GenericCodec<type>{};\


_IMPL_SINGLEIE_CODEC(_UC)
_IMPL_SINGLEIE_CODEC(_US)
_IMPL_SINGLEIE_CODEC(_UL)

#endif /* SINGLEIECODEC_H_ */
