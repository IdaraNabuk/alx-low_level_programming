#include "main.h"

/**
 * Recursive function that returns the factorial of a given number.
 * @n: The number to find the factorial of.
 *
 * Return: If n < 0, -1 to indicate an error for negative numbers
 * 	   If n == 0, 1 as the base case for factorial of 0
 * 	   If n > 0, Recursive call to calculate factorial
 */

int factorial(int n) {
  if (n < 0) {
    return -1;  // Return -1 to indicate an error for negative numbers
  } else if (n == 0) {
    return 1;   // Return 1 as the base case for factorial of 0
  } else {
    return n * factorial(n - 1);  // Recursive call to calculate factorial
  }
}
