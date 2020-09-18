// MinimumNumberOfCoins.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int getNumberOfCoins(vector<int> coins, int amount)
{
    vector <int> numOfCoins;

    for (int i = 0; i <= amount; i++)
        numOfCoins.push_back(INT_MAX);

    numOfCoins[0] = 0;

    for (int i = 0; i <= amount; i++)
    {
        for (int& coinValue : coins)
        {
            if (coinValue <= i)
            {
                int sub_res = numOfCoins[i - coinValue];
                if (sub_res != INT_MAX && sub_res + 1 < numOfCoins[i])
                {
                    numOfCoins[i] = sub_res + 1;
                }
            }
        }
    }

    return numOfCoins[amount];
}

int main()
{
    vector<int> denoms = {9, 6, 5, 1};

    cout << "Number of coins needed = " << getNumberOfCoins(denoms, 11);

    return 0;
}
