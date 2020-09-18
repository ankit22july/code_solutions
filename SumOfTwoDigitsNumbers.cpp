// SumOfTwoDigitsNumbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void findSum(int * array, int size)
{
    long int sum = 0;

    for (int i = 0; i < size; i++)
    {
        if ((array[i] > 9 && array[i] < 100) ||
            (array[i] > -100 && array[i] < -9))
        {
            sum += array[i];
        }
    }

    std::cout << "Sum = " << sum << std::endl;
}

int main()
{
    std::cout << "Hello World!\n";

    int array[] = { -13, 1900, 1, 100, 45 };

    findSum(array, 5);

    return 0;
}