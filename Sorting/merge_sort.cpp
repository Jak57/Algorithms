#include <bits/stdc++.h>
using namespace std;

void merge_sort(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int high);

int main()
{
    int n, arr[100000], i;
    cin>> n;

    for (i = 0; i < n; i++)
    {
        cin>> arr[i];
    }

    merge_sort(arr, 0, n-1);

    for (i = 0; i < n; i++)
        cout<< arr[i] << " ";
    cout<< "\n";

    return 0;
}


void merge_sort(int arr[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high)/2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}


void merge(int arr[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
    int temp[high-low+1];

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i += 1;
        }
        else
        {
            temp[k] = arr[j];
            j += 1;
        }
        k += 1;
    }

    while (i <= mid)
    {
        temp[k] = arr[i];
        i += 1;
        k += 1;
    }

    while (j <= high)
    {
        temp[k] = arr[j];
        j += 1;
        k += 1;
    }

    k = 0;
    for (i = low; i <= high; i++)
    {
        arr[i] = temp[k];
        k += 1;
    }
}

/*
5
1 4 3 2 5
*/
