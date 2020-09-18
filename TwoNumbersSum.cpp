// TwoNumbersSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm> 

// Time Complexity = O(n^2)
void twoNumbersSumMethod1(std::vector<int>& list, int targetSum)
{
    for (int i = 0; i < list.size() - 1; i++)
    {
        int first = list[i];

        for (int j = i + 1; j < list.size(); j++)
        {
            int second = list[j];

            if ((first + second) == targetSum)
            {
                std::cout << "[" << first << "," << second<< "]" << std::endl;
                return;
            }
        }
    }
}

// Time Complexity = O(n)
// Space Complexity = O(n)
void twoNumbersSumMethod2(std::vector<int>& list, int targetSum)
{
    std::unordered_set<int> hash_table;

    for (int i = 0; i < list.size(); i++)
    {
        int potentialMatch = targetSum - list[i];

        if (hash_table.find(potentialMatch) != hash_table.end())
        {
            std::cout << "[" << potentialMatch << "," << list[i] << "]" << std::endl;
            break;
        }
        else
        {
            hash_table.insert(list[i]);
        }
    }
}

// Time Complexity = O(nlog(n))
// Time Complexity = O(1)
void twoNumbersSumMethod3(std::vector<int> & list, int targetSum)
{
    std::sort(list.begin(), list.end());
    int left = 0;
    int right = list.size() - 1;

    while (left < right)
    {
        int currentSum = list[left] + list[right];
        if (currentSum == targetSum)
        {
            std::cout << "[" << list[left] << "," << list[right] << "]" << std::endl;
            break;
        }
        else if (currentSum < targetSum)
            left += 1;
        else
            right -= 1;
    }
}

int main()
{
    std::cout << "Hello World!\n";

    std::vector <int> list = { 3, 5, -4, 8, 11, 1, -1, 6 };

    twoNumbersSumMethod1(list, 10);
    twoNumbersSumMethod2(list, 10);
    twoNumbersSumMethod3(list, 10);

    return 0;
}
