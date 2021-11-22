#ifndef CAT_H
#define CAT_H

#include <string>

class Cat {
public:
	Cat(std::string name, double weight);
	~Cat();

	/*Return cat name.*/
	std::string getName() {
		return _name;
	}

	double getWeight() {
		return _weight;
	}

	void addNewToy(std::string toyName) {
		std::string *Buffer = new std::string[++_toyAmount];
		if(_toyCollections != nullptr) {
			for(int Run = 0; Run < _toyAmount - 1; Run++) {
				Buffer[Run] = _toyCollections[Run];
			}
		}
		Buffer[_toyAmount - 1] = toyName;
		delete [] _toyCollections;
		_toyCollections = Buffer;
	}

	std::string getToy(int index) {
		if(index < _toyAmount) {
			return _toyCollections[index];
		}
		else {
			return "Out of range.";
		}
	}

private:
	std::string _name; /*Cat name.*/
	double _weight; /*Cat weight*/
	std::string *_toyCollections; /*Toys list*/
	int _toyAmount; /*Toys number*/
};

/*Constructor.*/
Cat::Cat(std::string name, double weight) {
	_name = name;
	_weight = weight;
	_toyAmount = 0;
	_toyCollections = nullptr;
}

/*Destructor.*/
Cat::~Cat() {
	delete [] _toyCollections;
}

#endif