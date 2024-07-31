#pragma once

/**
 * @namespace math
 * @brief Namespace for basic math operations.
 */
namespace math {

    /**
     * @brief Adds two integers.
     * 
     * @param a The first integer.
     * @param b The second integer.
     * @return int The result of the addition.
     */
    int add(int a, int b);

    /**
     * @brief Subtracts the second integer from the first integer.
     * 
     * @param a The first integer.
     * @param b The second integer.
     * @return int The result of the subtraction.
     */
    int sub(int a, int b);

    /**
     * @brief Multiplies two integers.
     * 
     * @param a The first integer.
     * @param b The second integer.
     * @return int The result of the multiplication.
     */
    int mul(int a, int b);

    /**
     * @brief Divides the first integer by the second integer.
     * 
     * @param a The dividend.
     * @param b The divisor.
     * @return int The result of the division.
     * @throw std::runtime_error if the divisor is 0.
     */
    int div(int a, int b);
}
