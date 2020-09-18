// MinimumUniqueSubArrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

int main()
{
    vector <string> stringList;
    unordered_map <string, int> stringCounter;

    stringList.push_back("One");
    stringList.push_back("Two");
    stringList.push_back("Three");
    stringList.push_back("Four");
    stringList.push_back("One");
    stringList.push_back("One");
    stringList.push_back("Two");

    for (auto& str : stringList)
    {
        if (stringCounter.find(str) != stringCounter.end())
        {
            stringCounter[str]++;
        }
        else
        {
            stringCounter[str] = 1;
        }
    }

    int numberOfSubArrays = 0;

    for (auto& ele : stringCounter)
    {
        if (ele.second > numberOfSubArrays)
        {
            numberOfSubArrays = ele.second;
        }
    }

    cout << "Number of sub-arrays needed : " << numberOfSubArrays << endl;

    return 0;
}

