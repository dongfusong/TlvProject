/*
 * TestByteOrder.cpp
 *
 *  Created on: 2014Äê9ÔÂ24ÈÕ
 *      Author: Thoughtworks
 */
#include <gtest/gtest.h>
#include "ByteOrder.h"
#include <iostream>
using namespace std;
class TestByteOrder: public testing::Test {
public:
	void SetUp() {

	}
	void TearDown() {

	}
protected:
};

TEST_F(TestByteOrder, can_byte_order_us)
{
	_UC buf[] = {
			0x12,0x34,0x56,0x78
	};
	_UL value = 0;
	ByteOrder::ntoh(buf, sizeof(buf), (_UC*)&value, sizeof(value));
	EXPECT_EQ(0x12345678, value);
}

TEST_F(TestByteOrder, can_byte_order_uc)
{
	_UC buf[] = {
			0x12
	};
	_UC value = 0;
	ByteOrder::ntoh(buf, sizeof(buf), (_UC*)&value, sizeof(value));
	EXPECT_EQ(0x12, value);
}



