#include "../src/vector_space.h"

const double DELTA = 0.001;

// TEST example below.
// Using 'EXPECT' instead of 'ASSERT' here is because if 'ASSERT' fails,
// the delete statement will NOT be executed, which causes memory leak.
TEST(VectorTest, add_Exception0) {
    double u[2] = {4, 5};
    double v[2] = {0.2, 0.6};

    EXPECT_THROW(add(u, 0, v, 0), std::string);
}

TEST(VectorTest, add_Exception1) {
    double u[4] = {2, 3, 8, 7};
    double v[4] = {0.4, 2.3, 1.2, 3.4};

    EXPECT_THROW(add(u, 4, v, 2), std::string);
}

TEST(VectorTest, add_Case0) {
    double u[2] = {4, 5};
    double v[2] = {0.2, 0.6};

    double *result = add(u, 2, v, 2);

    EXPECT_NEAR(4.2, result[0], DELTA);
    EXPECT_NEAR(5.6, result[1], DELTA);

    delete [] result;
}

TEST(VectorTest, add_Case1) {
    double u[4] = {2, 3, 8, 7};
    double v[4] = {0.4, 2.3, 1.2, 3.4};

    double *result = add(u, 4, v, 4);

    EXPECT_NEAR(2.4, result[0], DELTA);
    EXPECT_NEAR(5.3, result[1], DELTA);
    EXPECT_NEAR(9.2, result[2], DELTA);
    EXPECT_NEAR(10.4, result[3], DELTA);

    delete [] result;
}

TEST(VectorTest, add_TA) {
    double u[3] = {1, 2, 3};
    double v[3] = {1.5, 2.5, 3.5};

    double *result = add(u, 3, v, 3);

    EXPECT_NEAR(2.5, result[0], DELTA);
    EXPECT_NEAR(4.5, result[1], DELTA);
    EXPECT_NEAR(6.5, result[2], DELTA);

    delete [] result;   // heap allocation in 'add'
}

TEST(VectorTest, scale_Case0) {
    double u[2] = {1.2, 2.8};

    double *result = scale(u, 2, 2.0);

    EXPECT_NEAR(2.4, result[0], DELTA);
    EXPECT_NEAR(5.6, result[1], DELTA);

    delete [] result;
}

TEST(VectorTest, scale_Case1) {
    double u[4] = {1.2, 2.8, 3.6, 0.5};

    double *result = scale(u, 4, 1.5);

    EXPECT_NEAR(1.8, result[0], DELTA);
    EXPECT_NEAR(4.2, result[1], DELTA);
    EXPECT_NEAR(5.4, result[2], DELTA);
    EXPECT_NEAR(0.75, result[3], DELTA);

    delete [] result;
}

TEST(VectorTest, scale_Exception0) {
    double u[4] = {1.2, 2.8, 3.6, 0.5};

    EXPECT_THROW(scale(u, 0, 1.5), std::string);
}

TEST(VectorTest, scale_TA) {
    double u[3] = {1.5, 2.5, 3.5};

    double *result = scale(u, 3, 1.2);

    EXPECT_NEAR(1.8, result[0], DELTA);
    EXPECT_NEAR(3.0, result[1], DELTA);
    EXPECT_NEAR(4.2, result[2], DELTA);

    delete [] result;  // heap allocation in 'scale'
}
