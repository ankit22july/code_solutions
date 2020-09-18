// MinCutsPallindromeString.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPallindrome(string &str, int min, int max)
{
    int l_idx = min;
    int r_idx = max;

    while (l_idx < r_idx)
    {
        if (str[l_idx] != str[r_idx])
            return false;
        l_idx += 1;
        r_idx -= 1;
    }

    return true;
}

//Time Complexity = O(n^3)
//Space Complexity = O(n^2)
int minNumOfCutsPallindrome_1(string input_string)
{
    
    size_t len = input_string.size();
    vector < vector <bool>> pallindromes(len, std::vector<bool>(len));
    vector <int> cuts(len, INT_MAX);

    for (int i = 0; i < len; i++)
    {   
        pallindromes[i][i] = true;
        for (int j = i + 1; j < len; j++)
        {
            pallindromes[i][j] = isPallindrome(input_string, i, j);
        }
    }

    for (int i = 0; i < len; i++)
    {
        if (pallindromes[0][i])
            cuts[i] = 1;
        else
        {
            cuts[i] = cuts[i - 1] + 1;
            for (int j = 1; j < i; j++)
            {
                if (pallindromes[j][i] && cuts[j - 1] + 1 < cuts[i])
                {
                    cuts[i] = cuts[j - 1] + 1;
                }
            }
        }
    }

    return cuts[cuts.size() - 1];
}

//Time Complexity = O(n^2)
//Space Complexity = O(n^2)
int minNumOfCutsPallindrome_2(string input_string)
{

    size_t len = input_string.size();
    vector < vector <bool>> pallindromes(len, std::vector<bool>(len));
    vector <int> cuts(len, INT_MAX);

    for (int i = 0; i < len; i++)
    {
        pallindromes[i][i] = true;
    }

    for (int length = 2; length < len + 1; length++)
    {
        for (int i = 0; i < len - length + 1; i++)
        {
            int j = i + length - 1;

            if (length == 2)
            {
                pallindromes[i][j] = input_string[i] == input_string[j];
            }
            else
            {
                pallindromes[i][j] = (input_string[i] == input_string[j]) && pallindromes[i + 1][j - 1];
            }
        }
    }

    for (int i = 0; i < len; i++)
    {
        if (pallindromes[0][i])
            cuts[i] = 1;
        else
        {
            cuts[i] = cuts[i - 1] + 1;
            for (int j = 1; j < i; j++)
            {
                if (pallindromes[j][i] && cuts[j - 1] + 1 < cuts[i])
                {
                    cuts[i] = cuts[j - 1] + 1;
                }
            }
        }
    }

    return cuts[cuts.size() - 1];
}

int main()
{
    int result = minNumOfCutsPallindrome_1("noonabbad");
    cout << "Minimum cuts needed : " << result << endl;
    result = minNumOfCutsPallindrome_2("noonabbad");
    cout << "Minimum cuts needed : " << result << endl;

    return 0;
}

