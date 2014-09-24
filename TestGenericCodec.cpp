/*
 * TestGenericCodec.cpp
 *
 *  Created on: 2014Äê9ÔÂ24ÈÕ
 *      Author: Thoughtworks
 */

#include <gtest/gtest.h>
#include "codec.h"
class TestGenericCodec: public testing::Test {
public:
	void SetUp() {

	}
	void TearDown() {

	}
protected:
};

TEST_F(TestGenericCodec, can_decode_ul)
{
	_UC buf[] = {0x12,0x34,0x56,0x78};
	Buffer bufObj(buf, sizeof(buf));
	GenericCodec<_UL> codec;
	_UL value = 0;
	codec.decode(bufObj, (_UC*)&value);
	EXPECT_EQ(0x12345678, value);
}
struct MyStruct{
	_UC index;
	_UL value;
};
TEST_F(TestGenericCodec, test_offsetCodec){
	_UC buf[] = {
			     	 0x12,0x34,0x56,0x78//_UL
				};
	Buffer bufObj(buf, sizeof(buf));
	MyStruct structVal;

	OffsetCodec<_UL, GenericCodec<_UL>, offsetof(MyStruct, value) > codec;
	codec.decode(bufObj, (_UC*)&structVal);
	EXPECT_EQ(0x12345678, structVal.value);
}
