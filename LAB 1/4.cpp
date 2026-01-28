#include <iostream>
using namespace std;

int findMax(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int findMin(int arr[], int size)
{
    int min = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

int main()
{
    int size;
    cout << "Enter array size: ";
    cin >> size;

    int *arr = new int[size];   // Dynamic array

    cout << "Enter array elements:\n";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "\nMaximum value: " << findMax(arr, size);
    cout << "\nMinimum value: " << findMin(arr, size);

    delete[] arr;   // Free memory

    return 0;
}
