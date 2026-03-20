//my integrer h file i inckuded comments so one can follow my process of this code
#pragma once //this amkes sure the file is only included once 

class Integer{
    private:
        int value; //stores the actual integer value
        
public:
    Integer(); //default constructor which sets the value at 0
    Integer(int val); //constructor that sets the value to value
     
    int getValue()const; //returns the stored integer
    void setValue(int val); //changes the stored integer
    
    
    //overload opp
    
    Integer operator+(const Integer& rhs) const; //adding
    Integer operator-(const Integer& rhs) const;//substract
    Integer operator*(const Integer& rhs) const;//multiply
    Integer operator/(const Integer& rhs) const;//divide
    
};