#include <bits/stdc++.h>
using namespace std;

struct conference
{
    int id;
    int start;
    int finish;
};


bool comparison(conference a, conference b)
{
    return (a.finish <= b.finish);
}


int main()
{
    int n, i, j, id, start, finish, previous_finish;
    conference conferences[10000];
    vector<int> ids;
    cin>> n;

    for (i = 0; i < n; i++)
    {
        cin>> start >> finish;

        conferences[i].id = i;
        conferences[i].start = start;
        conferences[i].finish = finish;
    }

    sort(conferences, conferences + n, comparison);
    id = conferences[0].id;
    previous_finish = conferences[0].finish;

    ids.push_back(id);

    for (i = 1; i < n; i++)
    {
        id = conferences[i].id;
        start = conferences[i].start;
        finish = conferences[i].finish;

        if (start >= previous_finish)
        {
            ids.push_back(id);
            previous_finish = finish;
        }
    }

    for (i = 0; i < ids.size(); i++)
        cout<< ids[i] << " ";
    cout<< "\n";

    return 0;
}


/*
11
1 4
3 5
0 6
5 7
3 8
5 9
6 10
8 11
8 12
2 13
12 14
*/
