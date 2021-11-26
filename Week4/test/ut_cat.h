#include "../src/cat.h"

#include <gtest/gtest.h>

TEST(Test0, ToyGetName) {
    Toy T("Bus model");
    ASSERT_EQ("Bus model", T.getName());
}

TEST(Test1, CatConstructor) {
    ASSERT_THROW(Cat C("", 20), std::string);
    ASSERT_THROW(Cat C("KKA", 60), std::string);
    ASSERT_THROW(Cat C1("KKB", 9), std::string);
}

TEST(Test2, Copy) {
    Cat Origin("KKA-1016", 35);
    Origin.addNewToy(Toy("Car"));
    Origin.addNewToy(Toy("Doll"));

    Cat C1(Origin);
    Cat C2;
    C2 = Origin;

    C1.addNewToy(Toy("Com"));
    C2.addNewToy(Toy("Org"));

    ASSERT_EQ(C1.getName(), Origin.getName());
    ASSERT_EQ(C2.getName(), Origin.getName());
    ASSERT_EQ(C1.getWeight(), Origin.getWeight());
    ASSERT_EQ(C2.getWeight(), Origin.getWeight());
    ASSERT_EQ(C1.getToy(0).getName(), "Car");
    ASSERT_EQ(C2.getToy(1).getName(), "Doll");
    ASSERT_THROW(Origin.getToy(2), std::string);
    ASSERT_EQ(C1.getToy(2).getName(), "Com");
    ASSERT_EQ(C2.getToy(2).getName(), "Org");
}

TEST(Test3, AddToy) {
    Cat C("KKA-1020", 33);
    C.addNewToy(Toy("3014"));
    C.addNewToy(Toy("2376"));
    C.addNewToy(Toy("3260"));

    ASSERT_EQ(C.getToy(0).getName(), "3014");
    ASSERT_EQ(C.getToy(1).getName(), "2376");
    ASSERT_EQ(C.getToy(2).getName(), "3260");
    ASSERT_THROW(C.getToy(3), std::string);
}

TEST(Test4, getToy) {
    Cat C("KKA-1020", 33);
    std::string NameList[3] = {"3014", "2376", "3260"};
    Toy List[3];

    for(int Run = 0; Run < 3; Run++) {
        List[Run].setName(NameList[Run]);
        C.addNewToy(List[Run]);
    }

    ASSERT_EQ(C.getName(), "KKA-1020");
    ASSERT_NEAR(C.getWeight(), 33, 0.001);
    for(int Run = 0; Run < 3; Run++) {
        ASSERT_EQ(C.getToy(Run).getName(), List[Run].getName());
    }
}

TEST(Test5, isHavior) {
    Cat C1("KKA-1016", 35);
    Cat C2("KKA-1020", 45);

    ASSERT_EQ(C1.isHeavierThan(C2), false);
    ASSERT_EQ(C2.isHeavierThan(C1), true);
}

TEST(Test6, All) {
    Cat Origin("KKA-1016", 35);
    Origin.addNewToy(Toy("Car"));
    Origin.addNewToy(Toy("Doll"));

    Cat C1(Origin);
    Cat C2;
    C2 = Origin;

    C1.addNewToy(Toy("Com"));
    C2.addNewToy(Toy("Org"));

    ASSERT_EQ(C1.getName(), Origin.getName());
    ASSERT_EQ(C2.getName(), Origin.getName());
    ASSERT_EQ(C1.getWeight(), Origin.getWeight());
    ASSERT_EQ(C2.getWeight(), Origin.getWeight());
    ASSERT_EQ(C1.getToy(0).getName(), "Car");
    ASSERT_EQ(C2.getToy(1).getName(), "Doll");
    ASSERT_THROW(Origin.getToy(2), std::string);
    ASSERT_EQ(C1.getToy(2).getName(), "Com");
    ASSERT_EQ(C2.getToy(2).getName(), "Org");
    ASSERT_EQ(C1.isHeavierThan(C2), false);
    ASSERT_EQ(Origin.isHeavierThan(C1), false);
}