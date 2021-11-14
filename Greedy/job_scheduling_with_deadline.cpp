#include <bits/stdc++.h>
using namespace std;

struct job
{
    int id;
    int deadline;
    int profit;
};


bool comparison(job a, job b)
{
    return (a.profit > b.profit);
}

int main()
{
    int n, i, id, deadline, profit, slots[10000], total_profit = 0;
    vector<int> ids;
    job jobs[10000];

    cin>> n;

    for (i = 0; i < n; i++)
    {
        cin>> deadline >> profit;

        jobs[i].id = i;
        jobs[i].deadline = deadline;
        jobs[i].profit = profit;
    }

    sort(jobs, jobs + n, comparison);
    memset(slots, 0, sizeof(slots));

    for (i = 0; i < n; i++)
    {
        id = jobs[i].id;
        deadline = jobs[i].deadline;
        profit = jobs[i].profit;

        while (deadline >= 1)
        {
            if (slots[deadline] == 0)
            {
                total_profit += profit;
                slots[deadline] = 1;

                ids.push_back(id);
                break;
            }
            deadline -= 1;
        }
    }

    cout<< total_profit << "\n";

    for (i = 0; i < ids.size(); i++)
        cout<< ids[i] << " ";
    cout<< "\n";

    return 0;
}

/*
10
9 15
2 2
5 18
7 1
4 25
2 20
5 8
7 10
4 12
3 5
*/
