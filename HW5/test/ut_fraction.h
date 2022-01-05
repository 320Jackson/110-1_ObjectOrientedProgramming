#include "../src/fraction.h"
#include <gtest/gtest.h>

class FractionTest : public ::testing::Test {
protected:
    Fraction Preset;
    Fraction PositiveInteger;
    Fraction NegetiveInteger;
    Fraction f1, f2, f3, f4;
    void SetUp() override {    
        Preset = Fraction();
        PositiveInteger = Fraction(4);
        NegetiveInteger = Fraction(-19);
        f1 = Fraction(4, 19);
        f2 = Fraction(-4, 19);
        f3 = Fraction(4, -19);
        f4 = Fraction(-4, -19);
    }
};

TEST_F(FractionTest, Err) {
    ASSERT_THROW(Fraction(2, 0), std::string);
}

TEST_F(FractionTest, DefaultConstructor) {
    ASSERT_EQ('+', Preset.sign());
    ASSERT_EQ(0, Preset.numerator());
    ASSERT_EQ(1, Preset.denominator());
}

TEST_F(FractionTest, OneParameterConstructor) {
    ASSERT_EQ('+', PositiveInteger.sign());
    ASSERT_EQ(4, PositiveInteger.numerator());
    ASSERT_EQ(1, PositiveInteger.denominator());

    ASSERT_EQ('-', NegetiveInteger.sign());
    ASSERT_EQ(19, NegetiveInteger.numerator());
    ASSERT_EQ(1, NegetiveInteger.denominator());
}

TEST_F(FractionTest, TwoParameterConstructor) {
    ASSERT_EQ('+', f1.sign());
    ASSERT_EQ(4, f1.numerator());
    ASSERT_EQ(19, f1.denominator());

    ASSERT_EQ('-', f2.sign());
    ASSERT_EQ(4, f2.numerator());
    ASSERT_EQ(19, f2.denominator());

    ASSERT_EQ('-', f3.sign());
    ASSERT_EQ(4, f3.numerator());
    ASSERT_EQ(19, f3.denominator());

    ASSERT_EQ('+', f4.sign());
    ASSERT_EQ(4, f4.numerator());
    ASSERT_EQ(19, f4.denominator());
}

TEST_F(FractionTest, ToString) {
    ASSERT_EQ("4/19", f1.toString());
    ASSERT_EQ("-4/19", f2.toString());
    ASSERT_EQ("-4/19", f3.toString());
    ASSERT_EQ("4/19", f4.toString());

    ASSERT_EQ("0", Preset.toString());
    ASSERT_EQ("4", PositiveInteger.toString());
    ASSERT_EQ("-19", NegetiveInteger.toString());
}

TEST_F(FractionTest, OperatorAdd) {
    Fraction Ans1 = f1 + f2;
    Fraction Ans2 = f1 + f4;
    Fraction Ans3 = Preset + f1;
    Fraction Ans4 = f1 + Preset;
    Fraction Ans5 = PositiveInteger + PositiveInteger;
    Fraction Ans6 = NegetiveInteger + NegetiveInteger;
    Fraction Ans7 = PositiveInteger + NegetiveInteger;
    Fraction Ans8 = NegetiveInteger + PositiveInteger;
    Fraction Ans9 = f1 + PositiveInteger;
    Fraction Ans10 = PositiveInteger + f1;
    Fraction Ans11 = f2 + PositiveInteger;
    Fraction Ans12 = PositiveInteger + f2;

    ASSERT_EQ("0", Ans1.toString());
    ASSERT_EQ("8/19", Ans2.toString());
    ASSERT_EQ("4/19", Ans3.toString());
    ASSERT_EQ("4/19", Ans4.toString());
    ASSERT_EQ("8", Ans5.toString());
    ASSERT_EQ("-38", Ans6.toString());
    ASSERT_EQ("-15", Ans7.toString());
    ASSERT_EQ("-15", Ans8.toString());
    ASSERT_EQ("80/19", Ans9.toString());
    ASSERT_EQ("80/19", Ans10.toString());
    ASSERT_EQ("72/19", Ans11.toString());
    ASSERT_EQ("72/19", Ans12.toString());
}

TEST_F(FractionTest, OperatorSub) {
    Fraction Ans1 = f1 - f2;
    Fraction Ans2 = f1 - f4;
    Fraction Ans3 = Preset - f1;
    Fraction Ans4 = f1 - Preset;
    Fraction Ans5 = PositiveInteger - PositiveInteger;
    Fraction Ans6 = NegetiveInteger - NegetiveInteger;
    Fraction Ans7 = PositiveInteger - NegetiveInteger;
    Fraction Ans8 = NegetiveInteger - PositiveInteger;
    Fraction Ans9 = f1 - PositiveInteger;
    Fraction Ans10 = PositiveInteger - f1;
    Fraction Ans11 = f2 - PositiveInteger;
    Fraction Ans12 = PositiveInteger - f2;

    ASSERT_EQ("8/19", Ans1.toString());
    ASSERT_EQ("0", Ans2.toString());
    ASSERT_EQ("-4/19", Ans3.toString());
    ASSERT_EQ("4/19", Ans4.toString());
    ASSERT_EQ("0", Ans5.toString());
    ASSERT_EQ("0", Ans6.toString());
    ASSERT_EQ("23", Ans7.toString());
    ASSERT_EQ("-23", Ans8.toString());
    ASSERT_EQ("-72/19", Ans9.toString());
    ASSERT_EQ("72/19", Ans10.toString());
    ASSERT_EQ("-80/19", Ans11.toString());
    ASSERT_EQ("80/19", Ans12.toString());
}

TEST_F(FractionTest, OperatorDiv) {
    Fraction Ans1 = f1 / f2;
    Fraction Ans2 = f2 / f1;
    Fraction Ans3 = f1 / f4;
    Fraction Ans4 = f4 / f1;

    Fraction a(1, 2);
    Fraction b(3, 4);

    Fraction Ans5 = PositiveInteger / a;
    Fraction Ans6 = a / PositiveInteger;
    Fraction Ans7 = a / b;
    Fraction Ans8 = b / a;

    ASSERT_EQ("-1", Ans1.toString());
    ASSERT_EQ("-1", Ans2.toString());
    ASSERT_EQ("1", Ans3.toString());
    ASSERT_EQ("1", Ans4.toString());
    ASSERT_EQ("8", Ans5.toString());
    ASSERT_EQ("1/8", Ans6.toString());
    ASSERT_EQ("2/3", Ans7.toString());
    ASSERT_EQ("3/2", Ans8.toString());
}

TEST_F(FractionTest, Numerator) {
    ASSERT_EQ(4, f1.numerator());
    ASSERT_EQ(4, f2.numerator());
    ASSERT_EQ(4, f3.numerator());
    ASSERT_EQ(4, f4.numerator());
    ASSERT_EQ(0, Preset.numerator());
    ASSERT_EQ(4, PositiveInteger.numerator());
    ASSERT_EQ(19, NegetiveInteger.numerator());
}

TEST_F(FractionTest, Denominator) {
    ASSERT_EQ(19, f1.denominator());
    ASSERT_EQ(19, f2.denominator());
    ASSERT_EQ(19, f3.denominator());
    ASSERT_EQ(19, f4.denominator());
    ASSERT_EQ(1, Preset.denominator());
    ASSERT_EQ(1, PositiveInteger.denominator());
    ASSERT_EQ(1, NegetiveInteger.denominator());
}

TEST_F(FractionTest, Sign) {
    ASSERT_EQ('+', f1.sign());
    ASSERT_EQ('-', f2.sign());
    ASSERT_EQ('-', f3.sign());
    ASSERT_EQ('+', f4.sign());
    ASSERT_EQ('+', Preset.sign());
    ASSERT_EQ('+', PositiveInteger.sign());
    ASSERT_EQ('-', NegetiveInteger.sign());
}