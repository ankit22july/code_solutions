/*
Little Shino and Common factors
Max. Marks: 100
Little Shino loves maths. Today her teacher gave her two integers. Shino is now wondering how many integers can divide both the numbers. She is busy with her assignments. Help her to solve the problem.

Input:
First line of the input file contains two integers, a and b.

Output:
Print the number of common factors of a and b.

Constraints: 1 <= a,b <= 10power(12)

Explanation
The common factors of  and  are 1 and 5 and answer will be 1.

*/

#include <iostream>
#include <algorithm>
using namespace std;

unsigned long int findGCD(unsigned long int num1, unsigned long int num2)
{
    if(0 == num1)
        return num2;
    return findGCD(num2%num1, num1);
}

unsigned long int getCountOfCommonFactors(unsigned long int & num1, unsigned long int & num2)
{
    unsigned long int gcd = 0, commonFactorsCount = 0;
    
    gcd = findGCD(max(num1, num2), min(num1, num2));
    
    for(unsigned long int loopVar = 1 ; loopVar*loopVar <= gcd ; loopVar++)
    {
        if(0 == gcd%loopVar)
        {
            if((loopVar*loopVar) == gcd)
                commonFactorsCount += 1;
            else
                commonFactorsCount += 2;
        }
    }
    
    return commonFactorsCount;
}

int main() 
{
	unsigned long int num1, num2;
	cin >> num1 >>num2;										// Reading input from STDIN
	cout << getCountOfCommonFactors(num1, num2) << endl;		// Writing output to STDOUT

  return 0;
}
