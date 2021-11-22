#include "../src/cat.h"

#include <gtest/gtest.h>

TEST(CatTest, getWeight0) {
    Cat Meow0("KKA", 7.25);
    Cat Meow1("KKB", 1.2);

    EXPECT_NEAR(7.25, Meow0.getWeight(), 0.001);
    EXPECT_NEAR(1.2, Meow1.getWeight(), 0.001);
}


TEST(CatTest, getWeight1) {
    Cat Meow0("KAA", 16.25);
    Cat Meow1("KAB", 14.2);

    EXPECT_NEAR(16.25, Meow0.getWeight(), 0.001);
    EXPECT_NEAR(14.2, Meow1.getWeight(), 0.001);
}

TEST(CatTest, getName0) {
    Cat Meow0("KKA", 7.25);
    Cat Meow1("KKB", 1.2);

    EXPECT_EQ("KKA", Meow0.getName());
    EXPECT_EQ("KKB", Meow1.getName());
}


TEST(CatTest, getName1) {
    Cat Meow0("KAA", 16.25);
    Cat Meow1("KAB", 14.2);

    EXPECT_EQ("KAA", Meow0.getName());
    EXPECT_EQ("KAB", Meow1.getName());
}

TEST(CatTest, addToys0) {
    Cat Meow("KKA", 14.2);
    Meow.addNewToy("Ball");
    Meow.addNewToy("Computer");

    EXPECT_EQ("Ball", Meow.getToy(0));
    EXPECT_EQ("Computer", Meow.getToy(1));
}

TEST(CatTest, addToys1) {
    Cat Meow("KKA", 14.2);
    Meow.addNewToy("Bicycle");
    Meow.addNewToy("Phone");

    EXPECT_EQ("Bicycle", Meow.getToy(0));
    EXPECT_EQ("Phone", Meow.getToy(1));
}

TEST(CatTest, All0) {
    Cat Meow("KKA", 14.2);
    Meow.addNewToy("Bicycle");
    Meow.addNewToy("Phone");

    EXPECT_EQ("KKA", Meow.getName());
    EXPECT_NEAR(14.2, Meow.getWeight(), 0.001);
    EXPECT_EQ("Bicycle", Meow.getToy(0));
    EXPECT_EQ("Phone", Meow.getToy(1));
}

TEST(CatTest, All1) {
    Cat Meow("KKB", 17.12);
    Meow.addNewToy("Raspberry pi");
    Meow.addNewToy("Computer");

    EXPECT_EQ("KKB", Meow.getName());
    EXPECT_NEAR(17.12, Meow.getWeight(), 0.001);
    EXPECT_EQ("Raspberry pi", Meow.getToy(0));
    EXPECT_EQ("Computer", Meow.getToy(1));
}
