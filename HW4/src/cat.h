#ifndef CAT_H
#define CAT_H

#include <string>
#include "toy.h"

class Cat {
public:
	Cat() {}
	Cat(std::string name, double weight) {
		if(name == "") {
			throw(std::string("No name"));
		}
		if(weight < 10 || weight > 50) {
			throw(std::string("Out of range."));
		}
		_name = name;
		_weight = weight;
		_toyAmount = 0;
		_toyCollections = nullptr;
	}

	~Cat() {
		delete [] _toyCollections;
	}

	/*Copy constructor*/
	Cat(Cat const &other) {
		_name = other.getName();
		_weight = other.getWeight();
		_toyAmount = other.getToyAmount();
		_toyCollections = new Toy[_toyAmount];
		for(int Run = 0; Run < _toyAmount; Run++) {
			_toyCollections[Run] = other.getToy(Run);
		}
	}

	Cat &operator =(Cat const &other) {
		_name = other.getName();
		_toyAmount = other.getToyAmount();
		_weight = other.getWeight();
		_toyCollections = new Toy[_toyAmount];
		for(int Run = 0; Run < _toyAmount; Run++) {
			_toyCollections[Run] = other.getToy(Run);
		}
		return *this;
	}


	void addNewToy(Toy const toyName) {
		Toy *Buffer = new Toy[++_toyAmount];
		if(_toyCollections != nullptr) {
			for(int Run = 0; Run < _toyAmount - 1; Run++) {
				Buffer[Run] = _toyCollections[Run];
			}
			delete [] _toyCollections;
		}
		Buffer[_toyAmount - 1] = toyName;
		_toyCollections = Buffer;
	}

	Toy getToy(int index) const {
		if(index >= _toyAmount || index < 0) {
			throw(std::string("Out of range."));
		}
		return _toyCollections[index];
	}

	bool isHeavierThan(Cat const &other) {
		return _weight > other.getWeight();
	}

	/*Return cat name.*/
	std::string getName() const {
		return _name;
	}

	double getWeight() const {
		return _weight;
	}

	int getToyAmount() const {
		return _toyAmount;
	}
private:
	std::string _name; /*Cat name.*/
	double _weight; /*Cat weight*/
	Toy *_toyCollections; /*Toys list*/
	int _toyAmount; /*Toys number*/
};

#endif