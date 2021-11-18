#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;

int main()
{
    int n, i, j, k, arr[100][100], length, dimensions[10000], product, len;
    cin>> len;

    for (i = 0; i < len; i++)
        cin>> dimensions[i];

    n = len-1;

    for (i = 1; i <= n; i++)
        arr[i][i] = 0;

    for (length = 1; length <= n-1; length++)
    {
        for (i = 1; i <= n-length; i++)
        {
            j = i + length;
            arr[i][j] = INF;

            for (k = i; k <= j-1; k++)
            {
                product = arr[i][k] + arr[k+1][j] + dimensions[i-1] * dimensions[k] * dimensions[j];

                if (product < arr[i][j])
                    arr[i][j] = product;
            }
        }
    }

    cout<< "Minimum number of multiplications is " << arr[1][n] << "\n";

    return 0;
}

/*
7
30 20 15 5 10 5 10
*/
