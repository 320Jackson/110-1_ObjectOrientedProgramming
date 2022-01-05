#include "../src/gcd.h"
#include <gtest/gtest.h>

TEST(TestGCD, PositiveGCD) {
    ASSERT_EQ(10, gcd(10, 30));
    ASSERT_EQ(10, gcd(30, 10));
    ASSERT_EQ(5, gcd(25, 35));
    ASSERT_EQ(5, gcd(35, 25));
    ASSERT_EQ(1, gcd(28, 39));
    ASSERT_EQ(1, gcd(39, 28));
    ASSERT_EQ(4, gcd(76, 24));
    ASSERT_EQ(4, gcd(24, 76));
}

TEST(TestGCD, NegtiveGCD) {
    ASSERT_EQ(10, gcd(-10, -30));
    ASSERT_EQ(10, gcd(-30, -10));
    ASSERT_EQ(5, gcd(-25, -35));
    ASSERT_EQ(5, gcd(-35, -25));
    ASSERT_EQ(1, gcd(-28, -39));
    ASSERT_EQ(1, gcd(-39, -28));
    ASSERT_EQ(4, gcd(-76, -24));
    ASSERT_EQ(4, gcd(-24, -76));
}

TEST(TestGCD, NegtivePositiveGCD) {
    ASSERT_EQ(10, gcd(-10, 30));
    ASSERT_EQ(10, gcd(-30, 10));
    ASSERT_EQ(5, gcd(-25, 35));
    ASSERT_EQ(5, gcd(-35, 25));
    ASSERT_EQ(1, gcd(-28, 39));
    ASSERT_EQ(1, gcd(-39, 28));
    ASSERT_EQ(4, gcd(-76, 24));
    ASSERT_EQ(4, gcd(-24, 76));
}

TEST(TestGCD, PositiveNegtiveGCD) {
    ASSERT_EQ(10, gcd(10, -30));
    ASSERT_EQ(10, gcd(30, -10));
    ASSERT_EQ(5, gcd(25, -35));
    ASSERT_EQ(5, gcd(35, -25));
    ASSERT_EQ(1, gcd(28, -39));
    ASSERT_EQ(1, gcd(39, -28));
    ASSERT_EQ(4, gcd(76, -24));
    ASSERT_EQ(4, gcd(24, -76));
}