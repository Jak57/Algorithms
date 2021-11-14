#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n);

int main()
{
    int arr[10000], n, i, j;
    // n: Size of the array
    cin>> n;

    for (i = 1; i <= n; i++)
        cin>> arr[i];

    bubble_sort(arr, n);
    cout<< "\nSorted array:" << "\n";

    for (i = 1; i <= n; i++)
        cout<< arr[i] << " ";
    cout<< "\n";

    return 0;
}


void bubble_sort(int arr[], int n)
{
    /* Sorts the array in ascending order */

    int i, j, temp;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                // Swap arr[j] with arr[j+1]

                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

/*
5
14 33 27 35 10
*/
