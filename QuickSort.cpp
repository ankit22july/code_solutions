// QuickSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int partition(int A[], int start, int end)
{
    int i = start;
    int j = end;
    int tmp;
    int pivot = A[(start + end)/2];

    while (i <= j)
    {
        while (A[i] < pivot)
            i++;
        while (A[j] > pivot)
            j--;
        if (i <= j)
        {
            tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
            i++;
            j--;
        }
    }

    return j;
}

void quickSort(int A[], int start, int end)
{
    if (start < end)
    {
        int pivot = partition(A, start, end);
        quickSort(A, start, pivot - 1);
        quickSort(A, pivot + 1, end);
    }
}

int main()
{
    std::cout << "Hello World!\n";
    int arr[] = {2,5,1,0,9,-8 };

    quickSort(arr, 0, 5);

    for (int i = 0; i < 6; i++)
        std::cout << arr[i] << std::endl;

    return 0;

}

