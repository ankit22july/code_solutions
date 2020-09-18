// LongestSubstringWithoutDuplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int findMax(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

void LongestSubstringWithoutDuplication(string input)
{
    unordered_map<char, int> hashTable;
    int currtLongest[2] = {0,1};
    int startIdx = 0;

    for (int i = 0; i < input.size(); i++)
    {
        if (hashTable.find(input[i]) != hashTable.end())
        {
            startIdx = findMax(startIdx, hashTable[input[i]] + 1);
        }

        if ((currtLongest[1] - currtLongest[0]) < (i + 1 - startIdx))
        {
            currtLongest[0] = startIdx;
            currtLongest[1] = i + 1;
        }

        hashTable[input[i]] = i;
    }

    cout << "Longest substring without duplication : " << input.substr(currtLongest[0], currtLongest[1] - currtLongest[0]) << '\n';

}

int main()
{  
    LongestSubstringWithoutDuplication("abcabcdefez");
    return 0;
}

