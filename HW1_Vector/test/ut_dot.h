#include "../src/dot.h"

// A single test case has the following form:
TEST(Case1, dot) {
    double d_Arr1[2] = {1, 2};
    double d_Arr2[2] = {3, 4};
    int int_dimArr = 2;
    ASSERT_NEAR(11, dot(d_Arr1, int_dimArr, d_Arr2, int_dimArr), 0.01);
}

TEST(Case2, dot) {
    double d_Arr1[2] = {1, 3};
    double d_Arr2[2] = {2, 4};
    int int_dimArr = 2;
    ASSERT_NEAR(14, dot(d_Arr2, int_dimArr, d_Arr1, int_dimArr), 0.01);
}

TEST(Case3, dot) {
    double d_Arr1[3] = {1, 3, 8};
    double d_Arr2[3] = {2, 3, 1};
    int int_dimArr = 3;
    ASSERT_NEAR(19, dot(d_Arr1, int_dimArr, d_Arr2, int_dimArr), 0.01);
}

TEST(Case4, dot) {
    double d_Arr1[3] = {2, 0, 4};
    double d_Arr2[3] = {6, 3, 7};
    int int_dimArr = 3;
    ASSERT_NEAR(40, dot(d_Arr2, int_dimArr, d_Arr1, int_dimArr), 0.01);
}

TEST(Err1, dot) {
    double d_Arr1[3] = {2, 0, 4};
    double d_Arr2[4] = {6, 3, 7, 6};
    ASSERT_THROW(dot(d_Arr1, 3, d_Arr2, 4), std::string);
}

TEST(Err2, dot) {
    double d_Arr1[3] = {2, 0, 4};
    double d_Arr2[4] = {6, 3, 7, 6};
    ASSERT_THROW(dot(d_Arr2, 4, d_Arr1, 3), std::string);
}

TEST(Err3, dot) {
    double d_Arr1[3] = {2, 0, 4};
    double d_Arr2[4] = {6, 3, 7, 6};
    ASSERT_THROW(dot(d_Arr2, -1, d_Arr1, 3), std::string);
}

TEST(Err4, dot) {
    double d_Arr1[3] = {2, 0, 4};
    double d_Arr2[4] = {6, 3, 7, 6};
    ASSERT_THROW(dot(d_Arr2, 4, d_Arr1, -1), std::string);
}