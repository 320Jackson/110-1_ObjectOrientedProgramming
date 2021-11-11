#include <string>

class Cat {
public:

  Cat(std::string name, double weight) {}

  ~Cat() {}

  std::string getName() {}

  double getWeight() {}

  void addNewToy(std::string toyName) {}

  std::string getToy(int index) {}

private:
  std::string _name;
  double _weight;
  std::string * _toyCollections;
  int _toyAmount;

};
