#ifndef TOY_H
#define TOY_H
#include <string>

class Toy {
public:
    /*Constructor with parameter*/
    Toy() {}

    Toy(std::string name) {
        ToyName = name;
    }

    void setName(std::string Name) {
        ToyName = Name;
    }

    std::string getName() const {
        return ToyName;
    }

private:
    std::string ToyName;
};

#endif