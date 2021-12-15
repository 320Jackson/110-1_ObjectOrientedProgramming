#include <string>

class Fraction {
public:
	// default value is +0/1
	// i.e., _sign='+', _numerator=0, _denominator=1
	Fraction() {}

	// default value is an integer (denominator=1)
	// e.g., Fraction f(-3) has its _sign='-', _numerator=3, _denominator=1
	Fraction(int num) {}

	// hint: use gcd
	// throw exception when the denominator is 0
	Fraction(int numerator, int denominator) {}

	// get the numerator of the fraction
	int numerator() const {}

	// get the denominator of the fraction
	int denominator() const {}

	// get positive or negative sign of the fraction
	char sign() const {}

	// display the fraction by string
	std::string toString() const {}

	// addition of two Fractions
	Fraction operator + (Fraction const & f) const {}

	// subtraction of two Fractions
	Fraction operator - (Fraction const & f) const {}

	// division of two Fractions
	Fraction operator / (Fraction const & f) const {}

private:
	// both numerator and denominator should be positive
	int _numerator;
	int _denominator;
	char _sign;
};
