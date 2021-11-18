#include <bits/stdc++.h>
using namespace std;

struct item
{
    int id;
    int weight;
    int profit;
};


int main()
{
    int n, i, j, weight, profit, capacity;
    item items[1000];
    int container[100][100];

    cin>> n >> capacity;

    for (i = 1; i <= n; i++)
    {
        cin>> weight >> profit;

        items[i].id = i;
        items[i].weight = weight;
        items[i].profit = profit;
    }

    for (i = 0; i <= n; i++)
        container[i][0] = 0;

    for (j = 0; j <= capacity; j++)
        container[0][j] = 0;

    for (i = 1; i <= n; i++)
    {
        weight = items[i].weight;
        profit = items[i].profit;

        for (j = 1; j <= capacity; j++)
        {
            if (weight <= j)
            {
                container[i][j] = max(container[i-1][j],   container[i-1][j-weight] + profit);
            }
            else
            {
                container[i][j] = container[i-1][j];
            }
        }
    }

    cout<< "Maximum profit is " << container[n][capacity] << "\n";

    return 0;
}

/*
4 5

2 3
3 4
4 5
5 6
*/



