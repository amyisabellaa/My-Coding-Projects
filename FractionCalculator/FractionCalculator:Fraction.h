#ifndef FRACTION_H
#define FRACTION_H

#include <iostream> // lets us use cout

class Fraction {
private:
    int numerator;                 // top number
    int denominator;               // bottom number
    int gcd(int a, int b) const;   // helper to simplify fractions

public:
    Fraction();                               // default constructor
    Fraction(int num, int denom);             // normal constructor
    Fraction(const Fraction& other);          // copy constructor

    int getNumerator() const;                 // returns numerator
    int getDenominator() const;               // returns denominator

    void setNumerator(int num);               // sets numerator
    void setDenominator(int denom);           // sets denominator

    Fraction operator+(const Fraction& other) const; // add
    Fraction operator-(const Fraction& other) const; // subtract
    Fraction operator*(const Fraction& other) const; // multiply
    Fraction operator/(const Fraction& other) const; // divide

    void simplify();                          // reduce to simplest form
    void print() const;                       // print fraction as a/b
};

#endif