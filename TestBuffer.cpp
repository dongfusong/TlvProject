/*
 * TestBuffer.cpp
 *
 *  Created on: 2014Äê9ÔÂ24ÈÕ
 *      Author: Thoughtworks
 */
#include <gtest/gtest.h>
#include "buffer.h"
class TestBuffer: public testing::Test {
public:
	void SetUp() {

	}
	void TearDown() {

	}
protected:
};

TEST_F(TestBuffer, test_buffer_alloc)
{
	_UC buf[] = {0x12,0x34,0x56,0x78};
	Buffer buffer(buf, sizeof(buf));
	EXPECT_EQ(buf, buffer.alloc(2));
	EXPECT_EQ((buf + 2), buffer.alloc(2));
}



