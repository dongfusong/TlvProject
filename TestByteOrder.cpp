/*
 * TestByteOrder.cpp
 *
 *  Created on: 2014Äê9ÔÂ24ÈÕ
 *      Author: Thoughtworks
 */
#include <gtest/gtest.h>
#include "ByteOrder.h"

class TestByteOrder: public testing::Test {
public:
	void SetUp() {

	}
	void TearDown() {

	}
protected:
};

TEST_F(TestByteOrder, can_byte_order_ul)
{
	_UC buf[] = {
			0x12,0x34,0x56,0x78
	};
	_UL value = 0;
	ByteOrder::ntoh(buf, (_UC*)&value, sizeof(buf));
	EXPECT_EQ(0x12345678, value);
}



