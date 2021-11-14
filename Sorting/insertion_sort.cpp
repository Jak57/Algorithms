#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[], int n);

int main()
{
    int arr[10000], n, i, j;
    cin>> n;

    for (i = 1; i <= n; i++)
        cin>> arr[i];

    insertion_sort(arr, n);

    cout<< "\nAfter sort:" << "\n";

    for (i = 1; i <= n; i++)
        cout<< arr[i] << " ";
    cout<< "\n";

    return 0;
}


void insertion_sort(int arr[], int n)
{
    /* Sorts array in ascending order */
    int i, j, temp;

    for (i = 2; i <= n; i++)
    {
        for (j = i; j > 1; j--)
        {
            if (arr[j] < arr[j-1])
            {
                // swap arr[j] with arr[j-1]
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }

}
/*
8
3  7  4  9  5  2  6  1
*/
