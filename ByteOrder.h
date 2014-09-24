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
	static void ntoh(const _UC* src, size_t sizeOfSrc,_UC* dest, size_t sizeOfDest){
		assert(sizeOfDest <= sizeOfSrc);
		for (int i = 0; i < sizeOfDest; i++)
			dest[sizeOfDest - i - 1] = *(src + i);
	}
};

#endif /* BYTEORDER_H_ */
