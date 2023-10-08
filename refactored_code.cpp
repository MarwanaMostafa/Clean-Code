#include <iostream>
#include <cassert>
#include <string>

using namespace std;

/**
 * Calculate the sum of elements in an array within a specified range.
 *
 * @param arr The input array.
 * @param start The start index of the range (inclusive).
 * @param end The end index of the range (exclusive).
 * @param size The size of the array .
 * @return The sum of elements in the specified range.
 */
int calculateSum(int arr[], int start, int end, int size)
{
    try
    {
        if (start < 0)
            throw std::string("Start index Less than 0");
        if (start > size - 1)
            throw std::string("Start index Greater than size of array");
        if (end > size - 1)
            throw std::string("End index Greater than size of array");

        int sum = 0;

        for (int i = start; i < end; i++)
        {
            sum += arr[i];
        }

        return sum;
    }
    catch (const std::string &msg)
    {
        std::cout << "Out of range: " << msg << std::endl;
    }
}
int main()
{
    // Unit tests
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Test case 1: Should fail. Test case 1 fails because the start index is greater than the size of the array.
    assert(calculateSum(arr, 5, 3, 5) == 5);

    // Test case 2: Should fail. Test case 2 fails because the start index is less than the size of the array.
    assert(calculateSum(arr, -1, n, 5) == 15);

    // Test case 3: Should fail. Test case 3 fails because the end index is greater than the size of the array.
    assert(calculateSum(arr, 2, 40, 5) == 7);

    /* All the test cases above are failed test cases, and all the test cases below represent successful scenarios. */

    // Test case 4: Sum of elements from index 1 to 3 (exclusive) should be 2 + 3 = 5.
    assert(calculateSum(arr, 1, 3, 5) == 5);

    // Test case 5: Sum of all elements should be 1 + 2 + 3 + 4 + 5 = 15.
    assert(calculateSum(arr, 0, n, 5) == 15);

    // Test case 6: Sum of elements from index 2 to 4 (exclusive) should be 3 + 4 = 7.
    assert(calculateSum(arr, 2, 4, 5) == 7);

    return 0;
}
