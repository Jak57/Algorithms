#include <bits/stdc++.h>
using namespace std;

void quick_sort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

int main()
{
    int n, i, arr[10000];
    cin>> n;

    for (i = 1; i <= n; i++)
        cin>> arr[i];

    quick_sort(arr, 1, n);
    cout<< "After sorting:" << "\n";

    for (i = 1; i <= n; i++)
        cout<< arr[i] << " ";
    cout<< "\n";

    return 0;
}


void quick_sort(int arr[], int low, int high)
{
    if (low >= high)
        return;

    int pivot;
    pivot = partition(arr, low, high);

    quick_sort(arr, low, pivot-1);
    quick_sort(arr, pivot+1, high);
}


int partition(int arr[], int low, int high)
{
    int i, j, pivot, temp, k;
    pivot = arr[high];

    i = low-1;
    for (j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i += 1;

            // Swapping elements
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    i += 1;
    temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;

    return i;
}

/*
8
2 8 7 1 3 5 6 4
*/
