/*
 * Buffer.h
 *
 *  Created on: 2014Äê9ÔÂ24ÈÕ
 *      Author: Thoughtworks
 */

#ifndef BUFFER_H_
#define BUFFER_H_
#include "typedefine.h"

class Buffer
{
public:
	Buffer(_UC* ptr, size_t size):_ptr(ptr),_size(size){

	}
	_UC* alloc(size_t size){
		_UC* result = _ptr;
		_ptr += size;
		return result;
	}
private:
	_UC* _ptr;
	size_t _size;
};



#endif /* BUFFER_H_ */
