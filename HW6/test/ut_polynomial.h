#include "../src/polynomial.h"

#include <gtest/gtest.h>

class PolynomialTest : public::testing::Test {
protected:
    Polynomial p01, p11;
    void SetUp() override {
        std::vector<Term> PolynomialTerms(3);
        PolynomialTerms[0] = Term(-3, 2);
        PolynomialTerms[1] = Term(-3, 0);
        PolynomialTerms[2] = Term(6, 3);
        p01 = Polynomial(PolynomialTerms, 3);

        std::vector<Term> PolynomialTerms1(5);
        PolynomialTerms1[0] = Term(-1, 1);
        PolynomialTerms1[1] = Term(2, 3);
        PolynomialTerms1[2] = Term(-5, 2);
        PolynomialTerms1[3] = Term(3, 4);
        PolynomialTerms1[4] = Term(7, 0);
        p11 = Polynomial(PolynomialTerms1, 4);
    }
};

TEST(PolynomialConstructorTest, Constructor) {
    std::vector<Term> terms(3);
    terms[0] = Term(-3, 2);
    terms[1] = Term(3, 0);
    terms[2] = Term(6, 3);
    Polynomial p1(terms, 3);
    ASSERT_EQ(p1.degree(), 3);
    ASSERT_EQ(p1.term(0).coefficient(), 3);
    ASSERT_EQ(p1.term(1).coefficient(), 0);
    ASSERT_EQ(p1.term(2).coefficient(), -3);
    ASSERT_EQ(p1.term(3).coefficient(), 6);

    ASSERT_EQ(p1.term(0).exponent(), 0);
    ASSERT_EQ(p1.term(1).exponent(), 1);
    ASSERT_EQ(p1.term(2).exponent(), 2);
    ASSERT_EQ(p1.term(3).exponent(), 3);
}

TEST(PolynomialConstructorTest, ConstructorWithZeroLSB) {
    std::vector<Term> terms(3);
    terms[0] = Term(-3, 2);
    terms[1] = Term(3, 4);
    terms[2] = Term(6, 3);
    Polynomial p1(terms, 4);
    ASSERT_EQ(p1.degree(), 4);
    ASSERT_EQ(p1.term(0).coefficient(), 0);
    ASSERT_EQ(p1.term(1).coefficient(), 0);
    ASSERT_EQ(p1.term(2).coefficient(), -3);
    ASSERT_EQ(p1.term(3).coefficient(), 6);
    ASSERT_EQ(p1.term(4).coefficient(), 3);

    ASSERT_EQ(p1.term(0).exponent(), 0);
    ASSERT_EQ(p1.term(1).exponent(), 1);
    ASSERT_EQ(p1.term(2).exponent(), 2);
    ASSERT_EQ(p1.term(3).exponent(), 3);
    ASSERT_EQ(p1.term(4).exponent(), 4);
}

TEST(PolynomialConstructorTest, ConstructorException) {
    std::vector<Term> t2(3);
    t2[0] = Term(3, 2);
    t2[1] = Term(3, 2);
    t2[2] = Term(1, 0);
    ASSERT_THROW(Polynomial(t2, 2), std::string);
}

TEST_F(PolynomialTest, OperaterAdd) {
    Polynomial pAdd = p01 + p11;
    ASSERT_EQ(pAdd.degree(), 4);
    ASSERT_EQ(pAdd.term(0).coefficient(), 4);
    ASSERT_EQ(pAdd.term(1).coefficient(), -1);
    ASSERT_EQ(pAdd.term(2).coefficient(), -8);
    ASSERT_EQ(pAdd.term(3).coefficient(), 8);
    ASSERT_EQ(pAdd.term(4).coefficient(), 3);

    ASSERT_EQ(pAdd.term(0).exponent(), 0);
    ASSERT_EQ(pAdd.term(1).exponent(), 1);
    ASSERT_EQ(pAdd.term(2).exponent(), 2);
    ASSERT_EQ(pAdd.term(3).exponent(), 3);
    ASSERT_EQ(pAdd.term(4).exponent(), 4);
}

TEST_F(PolynomialTest, OperaterMultiplyTerm) {
    Term t(2, 2);
    Polynomial pMul = p01 * t;
    ASSERT_EQ(pMul.degree(), 5);
    ASSERT_EQ(pMul.term(0).coefficient(), 0);
    ASSERT_EQ(pMul.term(1).coefficient(), 0);
    ASSERT_EQ(pMul.term(2).coefficient(), -6);
    ASSERT_EQ(pMul.term(3).coefficient(), 0);
    ASSERT_EQ(pMul.term(4).coefficient(), -6);
    ASSERT_EQ(pMul.term(5).coefficient(), 12);

    ASSERT_EQ(pMul.term(0).exponent(), 0);
    ASSERT_EQ(pMul.term(1).exponent(), 1);
    ASSERT_EQ(pMul.term(2).exponent(), 2);
    ASSERT_EQ(pMul.term(3).exponent(), 3);
    ASSERT_EQ(pMul.term(4).exponent(), 4);
    ASSERT_EQ(pMul.term(5).exponent(), 5);
}

TEST_F(PolynomialTest, OperaterMultiply) {
    Polynomial pMul = p01 * p11;
    ASSERT_EQ(pMul.degree(), 7);
    ASSERT_EQ(pMul.term(0).coefficient(), -21);
    ASSERT_EQ(pMul.term(1).coefficient(), 3);
    ASSERT_EQ(pMul.term(2).coefficient(), -6);
    ASSERT_EQ(pMul.term(3).coefficient(), 39);
    ASSERT_EQ(pMul.term(4).coefficient(), 0);
    ASSERT_EQ(pMul.term(5).coefficient(), -36);
    ASSERT_EQ(pMul.term(6).coefficient(), 3);
    ASSERT_EQ(pMul.term(7).coefficient(), 18);

    ASSERT_EQ(pMul.term(0).exponent(), 0);
    ASSERT_EQ(pMul.term(1).exponent(), 1);
    ASSERT_EQ(pMul.term(2).exponent(), 2);
    ASSERT_EQ(pMul.term(3).exponent(), 3);
    ASSERT_EQ(pMul.term(4).exponent(), 4);
    ASSERT_EQ(pMul.term(5).exponent(), 5);
    ASSERT_EQ(pMul.term(6).exponent(), 6);
    ASSERT_EQ(pMul.term(7).exponent(), 7);
}