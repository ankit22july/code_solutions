/*
This program will move the outer ring values for a matrix with n-elements in clockwise direction.
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

constexpr size_t R = 4;
constexpr size_t C = 5;

void print(int m[R][C]) 
{
	for (size_t r = 0; r != R; r++) 
	{
		for (size_t c = 0; c != C; c++) 
		{
			cout << m[r][c] << " ";
		}
		cout << endl;
	}
}

/* this function will rotate the given matrix clockwise by n values*/
void rotate_border(int m[R][C], int n) 
{
	vector<int> tmp(2 * (R + C - 2), -1); /* creating vector to store outer ring elements in order */
	for (size_t c = 0; c != C; c++) 
	{
		tmp[c] = m[0][c];  /* copies the first row values in the temp array*/
		tmp[c + C + R - 2] = m[R - 1][C - c - 1]; /* copies the last row values in the temp array in reverse order*/
	}

	for (size_t r = 1; r != R - 1; r++) /* loop iterate for the second row to second last row*/
	{
		tmp[C + r - 1] = m[r][C - 1];   /* copies the last column values in the temp array*/
		tmp[2 * C + R - 3 + r] = m[R - r - 1][0]; /* copies the first column values in the temp array in reverse order*/
	}

	/*std::rotate will change the array with the new begin iterator(second argument)*/
	std::rotate(tmp.begin(), std::next(tmp.begin(), n), tmp.end());
	//Alternate approach for std::next
	//std::rotate(tmp.begin(), tmp.begin() + n, tmp.end());

	for (size_t c = 0; c != C; c++) 
	{
		m[0][c] = tmp[c];
		m[R - 1][C - c - 1] = tmp[c + C + R - 2];
	}
	for (size_t r = 1; r != R - 1; r++) 
	{
		m[r][C - 1] = tmp[C + r - 1];
		m[R - r - 1][0] = tmp[2 * C + R - 3 + r];
	}
}

int main() 
{
	int m[R][C] = 
	{
		{1, 2, 3, 4, 5}
	,   {6, 7, 8, 9, 0}
	,   {5, 4, 2, 5, 7}
	,   {8, 2, 7, 9, 3}
	};

	print(m);
	cout << "-----------------" << endl;
	rotate_border(m, 13);
	print(m);
	return 0;
}
