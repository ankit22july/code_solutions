/* 
This program demonstrates the use of macro to find size of data type in two ways :
1. using the variable (e.g. x where x is of int type)
2. using the string literals (int , double etc) //improper results for STL
*/

#include <iostream>
#include <vector>

using namespace std;

#define my_sizeof1(type) (char *)(&type+1)-(char*)(&type)
#define mysizeof2(X)  ((X*)0+1)

int main()
{
	int x = 0;
	float f = 0.0f;
	double d = 0.0004;
	vector <int> vx;

	cout << "Size of int using sizeof() :\t" << sizeof(x) << endl;
	cout << "Size of float using sizeof() :\t" << sizeof(f) << endl;
	cout << "Size of double using sizeof() :\t" << sizeof(d) << endl;
	cout << "Size of vector<int> using sizeof() :\t" << sizeof(vx) << endl;

	cout << "Size of int using my_sizeof1() :\t" << my_sizeof1(x) << endl;
	cout << "Size of float using my_sizeof1() :\t" << my_sizeof1(f) << endl;
	cout << "Size of double using my_sizeof1() :\t" << my_sizeof1(d) << endl;
	cout << "Size of vector<int> using my_sizeof1() :\t" << my_sizeof1(vx) << endl;

	cout << "Size of int using mysizeof2() :\t" << mysizeof2(int) << endl;
	cout << "Size of float using mysizeof2() :\t" << mysizeof2(float) << endl;
	cout << "Size of double using mysizeof2() :\t" << mysizeof2(double) << endl;
	cout << "Size of vector<int> using mysizeof2() :\t" << mysizeof2(vector<int>) << endl;

	return 0;
}
