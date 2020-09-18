// PossiblePallindromes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

void checkPallindrome(string str)
{
    int left = 0, right = str.size() - 1;

    while(left <= str.size()/2)
    {
        if (str[left] == '?' && str[right] == '?')
        {
            str[left] = str[right] = 'a';
        }
        else if (str[left] == '?' || str[right] == '?')
        {
            if (str[left] == '?')
                str[left] = str[right];
            else
                str[right] = str[left];
        }
        else if (str[left] != str[right])
        {
            cout << "No" << endl;
            return;
        }

        left++;
        right--;
    }

    cout << str << endl;
}

int main()
{
    std::cout << "Hello World!\n";
    checkPallindrome("?ab??a");
    checkPallindrome("bab??a");
    checkPallindrome("?a?");
    return 0;
}

