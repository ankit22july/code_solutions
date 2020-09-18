// MaxProfitWithKTransactions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int findMax(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int maxProfitWithKTransactions_1(vector <int> prices, int K/* Number of Transactions */)
{
    if (prices.empty())
        return 0;

    vector <vector <int>> profits(K + 1, vector<int>(prices.size()));
    for (auto& profit : profits)
    {
        for (auto& val : profit)
            val = 0;
    }

    for (int t = 1; t < K + 1; t++)
    {
        int maxProfitSoFar = INT_MIN;

        for (int d = 1; d < prices.size(); d++)
        {
            // prices[d-1] is current day prices as its index start with 0 
            //cout << "maxProfit = findMax(" << maxProfit << ", (" << profits[t - 1][d - 1] << " - " << prices[d - 1] << "))" << '\n';
            maxProfitSoFar = findMax(maxProfitSoFar, (profits[t - 1][d - 1] - prices[d - 1]));
            
            // profits[t][d - 1] is profit for t transaction on previous day  
            profits[t][d] = findMax(profits[t][d - 1], (maxProfitSoFar + prices[d]));
            //cout << "profits["<<t<<"]["<<d<<"] = findMax(" << profits[t][d - 1] << ", (" << maxProfit << " + " << prices[d] << "))" << '\n';
        }
    }

    /* 
    for (auto& profit : profits)
    {
        for (auto& val : profit)
            cout << val << '\t';
        cout << '\n';
    }
    */
    return profits[K].back();
}

int maxProfitWithKTransactions_2(vector <int> prices, int K/* Number of Transactions */)
{
    if (prices.empty())
        return 0;

    vector <int> oddProfits(prices.size(), 0);
    vector <int> evenProfits(prices.size(), 0);
    vector <int> * currentProfits;
    vector <int> * previousProfits;

    for (int t = 1; t < K + 1; t++)
    {
        int maxProfitSoFar = INT_MIN;

        if (t % 2 == 1)
        {
            currentProfits = &oddProfits;
            previousProfits = &evenProfits;
        }
        else
        {
            currentProfits = &evenProfits;
            previousProfits = &oddProfits;
        }

        for (int d = 1; d < prices.size(); d++)
        {
            maxProfitSoFar = findMax(maxProfitSoFar, ((*previousProfits)[d - 1] - prices[d - 1]));
            (*currentProfits)[d] = findMax((*currentProfits)[d - 1], (maxProfitSoFar + prices[d]));
        }
    }
     
    if (K%2 == 0)
        return evenProfits.back();
    else
        return oddProfits.back();
}

int main()
{
    int profit = maxProfitWithKTransactions_1({ 5,11,3,50,60,90 }, 2);
    cout << "Max profit : " << profit << endl;

    profit = maxProfitWithKTransactions_2({ 5,11,3,50,60,90 }, 2);
    cout << "Max profit : " << profit << endl;

    return 0;
}

