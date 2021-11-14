#include <bits/stdc++.h>
using namespace std;

struct item
{
    int id;
    double weight;

    double profit;
    double density;
};


bool comparison(item a, item b)
{
    return (a.density > b.density);
}


int main()
{
    int n, i, j, id, index;
    item items[10000];
    double weight, profit, density, capacity, total_profit = 0, total_weight;

    cin>> n >> capacity;

    for (i = 0; i < n; i++)
    {
        cin>> weight >> profit;
        density = profit / weight;

        items[i].id = i;
        items[i].weight = weight;

        items[i].profit = profit;
        items[i].density = density;
    }

    sort(items, items + n, comparison);

    for (i = 0; i < n; i++)
    {
        id = items[i].id;
        weight = items[i].weight;

        profit = items[i].profit;
        density = items[i].density;

        if (weight <= capacity)
        {
            total_profit += profit;
            capacity -= weight;
        }
        else
        {
            total_profit += (capacity * density);
            break;
        }
    }

    printf("Maximum profit is %lf\n", total_profit);

    return 0;
}

/*
3 50
20 100
10 60
30 120
*/


