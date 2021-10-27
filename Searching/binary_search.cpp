#include <bits/stdc++.h>
using namespace std;

bool binarySearch(int arr[], int n, int k);

int main()
{
    int n, i, k, arr[100001];
    cin>> n >> k;

    for (i = 0; i < n; i++)
        cin>> arr[i];

    cout<< binarySearch(arr, n, k) << "\n";

    return 0;
}


bool binarySearch(int arr[], int n, int k)
{
    int low, high, mid;
    low = 0;
    high = n-1;

    while (low <= high)
    {
        mid = (low + high)/2;
        printf("%d %d %d\n", low, high, mid);

        if (arr[mid] == k)
        {
            cout<< mid << " " << "found" << "\n";
            return true;
        }
        else if (arr[mid] < k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

/*
8 50
1 2 3 4 5 6 7 8
*/

