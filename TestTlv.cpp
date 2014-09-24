/*
 * TestTlv.cpp
 *
 *  Created on: 2014Äê9ÔÂ23ÈÕ
 *      Author: Thoughtworks
 */
#include <gtest/gtest.h>
#include "Codec.h"
class TestTlv: public testing::Test {
public:
	void SetUp() {

	}
	void TearDown() {

	}
protected:
};

struct Node
{
	int index;
	char nameChar;
};

class SimpleMessageCodec
{
public:
	typedef Codec& (*Getter)();

	void decode(_UC* buffer, size_t codecSize, _UC* msg){
		Buffer buf(buffer, codecSize);
		decode(buf, msg);
	}

	void decode(Buffer& buffer, _UC* msg){
		for (Getter* getter = getCodecs(); getter != 0; getter++){
			Codec& codec = (*getter)();
			codec.decode(buffer, msg);
		}
	}
	Getter* getCodecs()const{
		static Getter Codecs[] =
		{
			IE_Codec<int>::getInstance,
			0
		};
		return Codecs;
	}
};


TEST_F(TestTlv, test_function_ptr){
}

TEST_F(TestTlv, )
{
	Node node;
	_UC buf[] = {0x12,0x34,0x56,0x78,0x99};
	Buffer bufObj(buf, sizeof(buf));
	GenericCodec<int> codec;
	codec.decode(bufObj, (_UC*)&node);
	EXPECT_EQ(0x12345678, node.index);
	EXPECT_EQ(0x99, node.nameChar);
}



