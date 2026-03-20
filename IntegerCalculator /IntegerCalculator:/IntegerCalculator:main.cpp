#include "Integer.h"   // include the class definition

// default constructor
Integer::Integer() {
    value = 0;        // this make it start at zero
}

// constructor with parameter
Integer::Integer(int val) {
    value = val;     // store the passed number
}

// getter function
int Integer::getValue() const {
    return value;    // return the current value
}

// setter function
void Integer::setValue(int val) {
    value = val;     // update the value
}

// overload + operator
Integer Integer::operator+(const Integer& rhs) const {
    return Integer(value + rhs.value); // add both values and return new Integer
}

// overload - operator
Integer Integer::operator-(const Integer& rhs) const {
    return Integer(value - rhs.value); // subtract and return new Integer
}

// overload * operator
Integer Integer::operator*(const Integer& rhs) const {
    return Integer(value * rhs.value); // multiply and return new Integer
}

// overload / operator
Integer Integer::operator/(const Integer& rhs) const {
    // prevents crashing if division by zero somehow happens
    if (rhs.value == 0) {
        return Integer(0);
    }

    return Integer(value / rhs.value); // integer division
}
