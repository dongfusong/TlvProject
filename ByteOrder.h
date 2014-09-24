/*
 * ByteOrder.h
 *
 *  Created on: 2014Äê9ÔÂ24ÈÕ
 *      Author: Thoughtworks
 */

#ifndef BYTEORDER_H_
#define BYTEORDER_H_
#include "typedefine.h"
class ByteOrder
{
public:
	static void ntoh(const _UC* src, _UC* dest, size_t size){
		dest[0] = 0x12;
		dest[1] = 0x12;
		dest[2] = 0x12;
		dest[3] = 0x12;
	}
};

#endif /* BYTEORDER_H_ */
