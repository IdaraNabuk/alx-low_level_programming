#include "main.h"

int find_sqrt(int num, int root);
int _sqrt_recursion(int n);

/**
 * Helper function that finds the natural square root of a number.
 * @num: The number to find the square root of.
 * @root: The root to be tested.
 *
 * Return: If the number has a natural square root - the square root.
 *         If the number does not have a natural square root - -1.
 */
int find_sqrt(int num, int root)
{
    if ((root * root) == num)
    {
        return root;  // Return the square root if it is found
    }

    if (root == num / 2)
    {
        return -1;    // Return -1 if the root reaches the limit
    }

    return find_sqrt(num, root + 1);  // Recursive call to search for the square root
}

/**
 * Recursive function that returns the natural square root of a number.
 * @n: The number to return the square root of.
 *
 * Return: If n has a natural square root - the natural square root of n.
 *         If n does not have a natural square root - -1.
 */
int _sqrt_recursion(int n)
{
    int root = 0;

    if (n < 0)
    {
        return -1;  // Return -1 to indicate an error for negative numbers
    }

    if (n == 1)
    {
        return 1;   // Return 1 as the base case for square root of 1
    }

    return find_sqrt(n, root);  // Call the helper function to find the square root
}
