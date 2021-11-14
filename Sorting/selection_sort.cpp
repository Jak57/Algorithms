#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n);

int main()
{
    int arr[10000], n, i, j;
    cin>> n;

    for (i = 1; i <= n; i++)
        cin>> arr[i];

    selection_sort(arr, n);

    cout<< "After sort:" << "\n";

    for (i = 1; i <= n; i++)
        cout<< arr[i] << " ";
    cout<< "\n";

    return 0;
}


void selection_sort(int arr[], int n)
{
    /* Sorts array in ascending order */
    int i, j, temp, k;

    for (i = 1; i <= n; i++)
    {
        for (j = i; j <= n; j++)
        {
            if (arr[j] < arr[i])
            {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }

        }

    }
}

/*
8
3  7  4  9  5  2  6  1
*/
