#ifndef FRACTION_H
#define FRACTION_H
#include <string>
#include "gcd.h"

class Fraction {
public:
	// default value is +0/1
	// i.e., _sign='+', _numerator=0, _denominator=1
	Fraction() {
		init(0, 1);
	}

	// default value is an integer (denominator=1)
	// e.g., Fraction f(-3) has its _sign='-', _numerator=3, _denominator=1
	Fraction(int num) {
		init(num, 1);
	}

	// hint: use gcd
	// throw exception when the denominator is 0
	Fraction(int numerator, int denominator) {
		if(denominator == 0) {
			throw std::string("Division zero error.");
		}
		int GCD = gcd(numerator, denominator);
		init(numerator / GCD, denominator / GCD);
	}

	// get the numerator of the fraction
	int numerator() const {
		return _numerator;
	}

	// get the denominator of the fraction
	int denominator() const {
		return _denominator;
	}

	// get positive or negative sign of the fraction
	char sign() const {
		return _sign;
	}

	// display the fraction by string
	std::string toString() const {
		std::string Output = "";
		if(_sign == '-') {
			Output += _sign;
		}
		if(_denominator != 1) {
			Output += std::to_string(_numerator) + "/" + std::to_string(_denominator);
		}
		else {
			Output += std::to_string(_numerator);
		}
		return Output;
	}

	// addition of two Fractions
	Fraction operator+(Fraction const & f) const {
		int denominator, f_denominator;
		int numerator, f_numerator;
		f_denominator = f.denominator();
		f_numerator = f.numerator() * _denominator;
		
		denominator = _denominator * f_denominator;
		numerator = _numerator * f_denominator; 
		if(f.sign() == '-') {
			f_numerator = -f_numerator;
		}
		if(_sign == '-') {
			numerator = -numerator;
		}
		numerator += f_numerator;
		return Fraction(numerator, denominator);
	}

	// subtraction of two Fractions
	Fraction operator-(Fraction const & f) const {
		int denominator, f_denominator;
		int numerator, f_numerator;
		f_denominator = f.denominator();
		f_numerator = f.numerator() * _denominator;
		
		denominator = _denominator * f_denominator;
		numerator = _numerator * f_denominator; 
		if(f.sign() == '-') {
			f_numerator = -f_numerator;
		}
		if(_sign == '-') {
			numerator = -numerator;
		}
		numerator -= f_numerator;
		return Fraction(numerator, denominator);
	}

	// division of two Fractions
	Fraction operator/(Fraction const & f) const {
		int denominator, f_denominator;
		int numerator, f_numerator;
		f_denominator = f.denominator();
		f_numerator = f.numerator();
		
		denominator = _denominator;
		numerator = _numerator;
		if(f.sign() == '-') {
			f_numerator = -f_numerator;
		}
		if(_sign == '-') {
			numerator = -numerator;
		}
		return Fraction(numerator * f_denominator, denominator * f_numerator);
	}

private:
	// both numerator and denominator should be positive
	int _numerator;
	int _denominator;
	char _sign;

	void init(int numerator, int denominator) {
		_numerator = numerator;
		_denominator = denominator;

		/*generate sign*/
		if(_numerator > 0){
			if(_denominator < 0) {
				_denominator = -_denominator;
				_sign = '-';
			}
			else {
				_sign = '+';
			}
		}
		else if(_numerator == 0) {
			_sign = '+';
			if(_denominator < 0) {
				_denominator = -_denominator;
			}
		}
		else if(_numerator == 0) {
			if(_denominator < 0) {
				_denominator = -_denominator;
				_sign = '-';
			}
			else {
				_sign = '+';
			}
		}
		else {
			_numerator = -_numerator;
			if(_denominator < 0) {
				_denominator = -_denominator;
				_sign = '+';
			}
			else {
				_sign = '-';
			}
		}
	}
};

#endif