#include <iostream>
#include <cassert>
#include "math.hpp"

/**
 * @brief Tests the add function.
 */
void test_add() {
    assert(math::add(1, 2) == 3);
    assert(math::add(-1, 1) == 0);
    assert(math::add(0, 0) == 0);
    std::cout << "All add tests passed." << std::endl;
}

/**
 * @brief Tests the sub function.
 */
void test_sub() {
    assert(math::sub(5, 3) == 2);
    assert(math::sub(-1, 1) == -2);
    assert(math::sub(0, 0) == 0);
    std::cout << "All sub tests passed." << std::endl;
}

/**
 * @brief Tests the mul function.
 */
void test_mul() {
    assert(math::mul(2, 3) == 6);
    assert(math::mul(-2, 3) == -6);
    assert(math::mul(0, 5) == 0);
    std::cout << "All mul tests passed." << std::endl;
}

/**
 * @brief Tests the div function.
 */
void test_div() {
    assert(math::div(6, 3) == 2);
    assert(math::div(10, -2) == -5);
    assert(math::div(0, 5) == 0);
    std::cout << "All div tests passed." << std::endl;

    try {
        math::div(5, 0);
        std::cout << "Division by zero should throw an exception, but it did not.\n";
    } catch (const std::runtime_error& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
}

int main() {
    // Run the tests
    test_add();
    test_sub();
    test_mul();
    test_div();

    std::cout << "All tests passed." << std::endl;
    return 0;
}
