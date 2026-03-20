#include <iostream>  // for cout
#include <cstdlib>   // for rand/srand
#include <ctime>     // for time
#include "Fraction.h"

int main() {
    srand(static_cast<unsigned int>(time(0))); // seed random so it changes each run

    for (int i = 0; i < 10; ++i) {             // do 10 calculations
        int num1 = rand() % 15 + 1;            // random 1-15
        int den1 = rand() % 15 + 1;            // random 1-15
        int num2 = rand() % 15 + 1;            // random 1-15
        int den2 = rand() % 15 + 1;            // random 1-15

        Fraction frac1(num1, den1);            // first fraction
        Fraction frac2(num2, den2);            // second fraction

        int randomOperation = rand() % 4;      // 0-3
        char operation;                         // operation symbol

        switch (randomOperation) {              // pick + - * /
            case 0: operation = '+'; break;
            case 1: operation = '-'; break;
            case 2: operation = '*'; break;
            default: operation = '/'; break;
        }

        std::cout << "Calc " << (i + 1) << ": ";
        frac1.print();
        std::cout << " " << operation << " ";
        frac2.print();
        std::cout << " = ";

        switch (operation) {
            case '+': {
                Fraction result = frac1 + frac2;
                result.print();
                break;
            }
            case '-': {
                Fraction result = frac1 - frac2;
                result.print();
                break;
            }
            case '*': {
                Fraction result = frac1 * frac2;
                result.print();
                break;
            }
            case '/': {
                // dividing by a fraction that equals 0 is not allowed
                if (frac2.getNumerator() == 0) {
                    std::cout << "Division by zero not allowed";
                } else {
                    Fraction result = frac1 / frac2;
                    result.print();
                }
                break;
            }
        }

        std::cout << std::endl; // go to next line after each calc
    }

    return 0; // done
}//Main.cpp