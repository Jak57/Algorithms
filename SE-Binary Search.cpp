#include<bits/stdc++.h>

using namespace std;

int arr[10000];

int binarySearch(int l, int h, int x)
{
    int m;
    while(l <= h){
        m = (l+h)/2;

        if(arr[m] == x)
            return m;
        else if(arr[m] < x)
            l = m+1;
        else
            h = m-1;
    }
    return -1;
}

int main()
{
    int n, i, j, x;
    cin>> n >> x;

    for(i = 1; i <= n; i++){
        cin>> arr[i];
    }

    cout<< binarySearch(1, n, x) << "\n";

    return 0;
}
/*
11 79
2 3 4 10 40 50 66 79 89 100 200
*/
