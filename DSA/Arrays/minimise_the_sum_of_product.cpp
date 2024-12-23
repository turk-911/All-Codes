#include <iostream>
using namespace std;
int main()
{
    int arr1[5] = {6, 1, 9, 5, 4};
    int arr2[5] = {3, 4, 8, 2, 4};
    int n = 5;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr1[i] > arr1[j])
            {
                int temp = arr1[j];
                arr1[j] = arr1[i];
                arr1[i] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr2[i] < arr2[j])
            {
                int temp = arr2[j];
                arr2[j] = arr2[i];
                arr2[i] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        sum += arr1[i] * arr2[i];
    }
    cout << "The minimum sum of product is: " << sum << endl;
}