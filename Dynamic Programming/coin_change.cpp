#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, j, coins[10000], target;
    int arr[100][100];

    cin>> n >> target;

    for (i = 1; i <= n; i++)
        cin>> coins[i];

    for (i = 0; i <= n; i++)
        arr[i][0] = 0;

    for (j = 0; j <= target; j++)
        arr[0][j] = INT_MAX;

    for (i = 1; i <= n; i++)
    {
        int coin_value = coins[i];

        for (j = 1; j <= target; j++)
        {
            if (j >= coin_value)
            {
                arr[i][j] = min(arr[i-1][j], arr[i][j-coin_value] + 1);
            }
            else
            {
                arr[i][j] = arr[i-1][j];
            }
        }
    }

    printf("Minimum number of coins to change amount %d is %d\n", target, arr[n][target]);

    return 0;
}

/*
4 7
1 2 4 7
*/

