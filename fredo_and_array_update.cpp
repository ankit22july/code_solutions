/*
Fredo is assigned a new task today. He is given an array A containing N integers. His task is to update all elements of 
array to some minimum value x , that is,  ;  such that sum of this new array is strictly greater than the sum of the 
initial array. Note that x should be as minimum as possible such that sum of the new array is greater than the sum of
the initial array.

Input Format:
First line of input consists of an integer N denoting the number of elements in the array A.
Second line consists of N space separated integers denoting the array elements.

Output Format:
The only line of output consists of the value of x.

Explanation
Initial sum of array = 1+2+3+4+5 = 15
When we update all elements to 4, sum of array = 4+4+4+4+4 = 16 which is greater than 15.
Note that if we had updated the array elements to 3,  which is not greater than . So, 4 is the minimum value to which
array elements need to be updated.
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int numberOfElements = 0, result = 0;
    cin >> numberOfElements;
    
    vector <int> arrayList(numberOfElements);
    int sum = 0;
    
    for (int loopVar = 0; loopVar < numberOfElements; loopVar++)
    {
        cin >> arrayList[loopVar];
        sum += arrayList[loopVar];
    }
    
    int average = ((sum)/numberOfElements) + 1;
    
    for (auto it : arrayList)
    {
        if(it == average)
        {
            result = it;
            break;
        }
    }
    
    cout << result;
    
    return 0;
    
}
