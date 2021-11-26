#include <gtest/gtest.h>
#include "../src/binary.h"

TEST(Binary_constructor, Sample1){
    int bits[8]={1,0,1,0,1,0,1,0};
    Binary a(bits, 8);
    ASSERT_EQ("10101010",a.toString());
}

TEST(Binary_constructor, Sample2){
	int ab[6]={1,1,1,0,1,0};
	Binary a(ab,6);
	Binary b(a);
	ASSERT_EQ("111010",a.toString());
	ASSERT_EQ("111010",b.toString());
}

TEST(Binary_right_shift, Sample3){
	int ab[4]={1,1,1,0};
	Binary a(ab, 4);
	a>>2;
	ASSERT_EQ("0011",a.toString());
	a>>4;
	ASSERT_EQ("0000",a.toString());
}

TEST(Binary_right_shift, Sample4){
	Binary a;
	ASSERT_ANY_THROW(a>>1);
}

TEST(Binary_left_shift, Sample5){
	int ab[4]={1,1,1,0};
	Binary a(ab, 4);
	a<<2;
	ASSERT_EQ("1000",a.toString());
	a<<4;
	ASSERT_EQ("0000",a.toString());
}

TEST(Binary_to_integer, Sample6) {
	int ab[4]={1,1,1,0};
	Binary a(ab, 4);
	ASSERT_EQ(14, a.toInt());
}

TEST(Binary_Resize, Sample7){
	int ab[4]={1,1,1,0};
	Binary a(ab, 4);
	a.resize(8);
	ASSERT_EQ("00001110",a.toString());
}

TEST(SetBit, Sample8) {
	int ab[4]={1,1,1,0};
	Binary a(ab, 4);
	a.resize(8);

	a.setBit(2, 1);
	a.setBit(5, 0);
	ASSERT_EQ("00101010",a.toString());
}
