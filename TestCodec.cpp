/*
 * TestTlv.cpp
 *
 *  Created on: 2014Äê9ÔÂ23ÈÕ
 *      Author: Thoughtworks
 */
#include <gtest/gtest.h>
#include "MessageCodec.h"

class TestCodec: public testing::Test {
public:
	void SetUp() {

	}
	void TearDown() {

	}
protected:
};


TEST_F(TestCodec, can_decode_single_struct)
{
	MyStruct structValue;
	_UC buf[] = {
			0x99,//index
			0x12,0x34,0x56,0x78//value
	};
	Buffer bufObj(buf, sizeof(buf));
	MyStructMessageCodec codec;
	codec.decode(bufObj, (_UC*)&structValue);
	EXPECT_EQ(0x99, structValue.index);
	EXPECT_EQ(0x12345678, structValue.value);
}

TEST_F(TestCodec, can_decode_nest_struct)
{
	MyStruct1 structValue;
	_UC buf[] = {
			0x99,//index
			0x12,0x34,0x56,0x78,//value
//////////////////////////////////////////// --- myStruct
			0x99,//index
			0x12,0x34,0x56,0x78//value
	};
	Buffer bufObj(buf, sizeof(buf));
	MyStruct1MessageCodec codec;
	codec.decode(bufObj, (_UC*)&structValue);
	EXPECT_EQ(0x99, structValue.index);
	EXPECT_EQ(0x12345678, structValue.value);

	EXPECT_EQ(0x99, structValue.text.index);
	EXPECT_EQ(0x12345678, structValue.text.value);
}

