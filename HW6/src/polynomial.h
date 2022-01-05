#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>
#include <algorithm>
#include <string>

#include "term.h"

class Polynomial {
public:
    Polynomial() {}

    Polynomial(std::vector<Term> terms, int degree) {
        ComparisonObj ComparisonFactor;

        std::stable_sort(terms.begin(), terms.end(), ComparisonFactor);
        for(int Run = 0; Run < terms.at(0).exponent(); Run++) {
            Term newTerm(0, Run);
            terms.insert(terms.begin(), newTerm);
        }

        for(int Run = terms.size() - 1; Run > 0; Run--) {
            if(terms.at(Run).exponent() == terms.at(Run - 1).exponent()) {
                throw std::string("with same exponent");
                break;
            }
            if(terms.at(Run).exponent() - 1 != terms.at(Run - 1).exponent()) {
                Term newTerm(0, terms.at(Run).exponent() - 1);
                terms.push_back(newTerm);
            }
        }

        std::stable_sort(terms.begin(), terms.end(), ComparisonFactor);
        _degree = degree;
        _terms = terms;
    }

    // get a term by exponent
    // If the term does not exist, return the term (0, exponent)
    Term term(int exponent) const {
        if(exponent <= _degree){
            return _terms.at(exponent);
        }
        return Term(0, exponent);
    }

    // get the degree
    int degree() const {
        return _degree;
    }

    // add two polynomials
    Polynomial operator+ (const Polynomial &q) const {
        int OutputDegree = _degree < q.degree() ? q.degree() : _degree;

        std::vector<Term> newTerm(OutputDegree + 1);
        for(int Run = 0; Run <= OutputDegree; Run++) {
            Term t = this->term(Run) + q.term(Run);
            newTerm[Run] = t;
        }

        while(newTerm[OutputDegree].coefficient() == 0 && OutputDegree > 0) {
            newTerm.pop_back();
            OutputDegree--;
        }
        Polynomial Output(newTerm, OutputDegree);
        return Output;
    }

    // multiply by a term
    Polynomial operator* (Term t) const {
        int OutputDegree = _degree + t.exponent();
        std::vector<Term> newTerm(OutputDegree + 1);

        for(int Run = 0; Run <= OutputDegree; Run++) {
            newTerm[Run] = this->term(Run) * t;
        }
        
        Polynomial Output(newTerm, OutputDegree);
        return Output;
    }

    // multiply by another Polynomial
    Polynomial operator* (const Polynomial &q) const {
        int OutputDegree = _degree + q.degree();
        std::vector<Term> newTerm(OutputDegree + 1);
        for(int Run = 0; Run <= OutputDegree; Run++) {
            newTerm[Run] = Term(0, Run);
        }

        for(int Outside = 0; Outside <= _degree; Outside++) {
            for(int Inside = 0; Inside <= q.degree(); Inside++) {
                newTerm[Outside + Inside] = newTerm[Outside + Inside] + (this->term(Outside) * q.term(Inside));
            }
        }

        Polynomial Output(newTerm, OutputDegree);
        return Output;
    }

private:
    std::vector<Term> _terms;
    int _degree;
};

#endif
