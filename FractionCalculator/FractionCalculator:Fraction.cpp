#include "Fraction.h" // pulls in the class definition

int Fraction::gcd(int a, int b) const {
    if (a < 0) a = -a;              // make a positive
    if (b < 0) b = -b;              // make b positive

    while (b != 0) {                // keep looping until b is 0
        int temp = a % b;           // get remainder
        a = b;                      // move b into a
        b = temp;                   // move remainder into b
    }

    if (a == 0) return 1;           // just in case, avoid returning 0
    return a;                        // gcd result
}

Fraction::Fraction() {
    numerator = 0;                   // default to 0
    denominator = 1;                 // default to 1 so it’s valid
}

Fraction::Fraction(int num, int denom) {
    numerator = num;                 // set top
    denominator = denom;             // set bottom

    if (denominator == 0) {          // no such thing as /0
        denominator = 1;             // fix it
    }

    simplify();                      // clean it up
}

Fraction::Fraction(const Fraction& other) {
    numerator = other.numerator;     // copy numerator
    denominator = other.denominator; // copy denominator
}

int Fraction::getNumerator() const {
    return numerator;                // return top
}

int Fraction::getDenominator() const {
    return denominator;              // return bottom
}

void Fraction::setNumerator(int num) {
    numerator = num;                 // update top
    simplify();                      // reduce
}

void Fraction::setDenominator(int denom) {
    if (denom == 0) denom = 1;       // prevent /0
    denominator = denom;             // update bottom
    simplify();                      // reduce
}

void Fraction::simplify() {
    if (denominator < 0) {           // if bottom is negative
        denominator = -denominator;  // flip bottom
        numerator = -numerator;      // move sign to top
    }

    if (numerator == 0) {            // 0 over anything = 0
        denominator = 1;             // keep it as 0/1
        return;                      // done
    }

    int g = gcd(numerator, denominator); // find gcd
    numerator /= g;                       // divide top by gcd
    denominator /= g;                     // divide bottom by gcd
}

Fraction Fraction::operator+(const Fraction& other) const {
    int newNum = numerator * other.denominator + other.numerator * denominator; // cross add
    int newDen = denominator * other.denominator;                               // multiply bottoms
    Fraction result(newNum, newDen);                                            // make fraction
    return result;                                                              // return it
}

Fraction Fraction::operator-(const Fraction& other) const {
    int newNum = numerator * other.denominator - other.numerator * denominator; // cross subtract
    int newDen = denominator * other.denominator;                               // multiply bottoms
    Fraction result(newNum, newDen);                                            // make fraction
    return result;                                                              // return it
}

Fraction Fraction::operator*(const Fraction& other) const {
    int newNum = numerator * other.numerator;  // multiply tops
    int newDen = denominator * other.denominator; // multiply bottoms
    Fraction result(newNum, newDen);           // make fraction
    return result;                             // return it
}

Fraction Fraction::operator/(const Fraction& other) const {
    // dividing by a fraction is multiplying by its reciprocal
    int newNum = numerator * other.denominator; // top * other bottom
    int newDen = denominator * other.numerator; // bottom * other top

    if (newDen == 0) {                          // means we divided by 0
        return Fraction(0, 1);                  // return safe value
    }

    Fraction result(newNum, newDen);            // make fraction
    return result;                               // return it
}

void Fraction::print() const {
    std::cout << numerator << "/" << denominator; // print like 3/4
}