#include <iostream>
#include "math.hpp"

int main(){

    std::cout << "This the main program" << std::endl;

    std::cout << "Addition of 1 and 2 is: " << math::add(1, 2) << std::endl;
    std::cout << "Subtraction of 5 and 3 is: " << math::sub(5, 3) << std::endl;
    std::cout << "Multiplication of 2 and 3 is: " << math::mul(2, 3) << std::endl;
    std::cout << "Division of 6 by 3 is: " << math::div(6, 3) << std::endl;
    
    return 0;
}