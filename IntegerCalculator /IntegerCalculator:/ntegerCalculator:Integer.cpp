#include <iostream>   // for cout
#include <cstdlib>    // for rand and srand
#include <ctime>      // for time
#include "Integer.h"  // our custom Integer class

int main() {

    // seeds random number generator so numbers change each run
    srand(static_cast<unsigned int>(time(0)));

    // loop runs calculator 10 times
    for (int i = 0; i < 10; ++i) {

        // generate random numbers from 1 to 10
        int num1 = rand() % 10 + 1;
        int num2 = rand() % 10 + 1;

        // create Integer objects using random values
        Integer int1(num1);
        Integer int2(num2);

        // choose random operation (0–3)
        int randomOperation = rand() % 4;
        char operation;

        // convert number into actual operator symbol
        switch (randomOperation) {
            case 0: operation = '+'; break;
            case 1: operation = '-'; break;
            case 2: operation = '*'; break;
            case 3: operation = '/'; break;
            default: operation = '+'; break; // backup safety
        }

        // perform calculation using overloaded operators
        switch (operation) {

            case '+': {
                Integer result = int1 + int2;   // calls operator+
                std::cout << int1.getValue() << " + " << int2.getValue()
                          << " = " << result.getValue() << std::endl;
                break;
            }

            case '-': {
                Integer result = int1 - int2;   // calls operator-
                std::cout << int1.getValue() << " - " << int2.getValue()
                          << " = " << result.getValue() << std::endl;
                break;
            }

            case '*': {
                Integer result = int1 * int2;   // calls operator*
                std::cout << int1.getValue() << " * " << int2.getValue()
                          << " = " << result.getValue() << std::endl;
                break;
            }

            case '/': {
                // check for divide by zero first
                if (int2.getValue() != 0) {
                    Integer result = int1 / int2;   // calls operator/
                    std::cout << int1.getValue() << " / " << int2.getValue()
                              << " = " << result.getValue() << std::endl;
                } else {
                    std::cout << "Division by zero is not allowed." << std::endl;
                }
                break;
            }
        }
    }

    return 0;   // program ends
}