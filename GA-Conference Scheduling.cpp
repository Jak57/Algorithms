#include<bits/stdc++.h>

using namespace std;

struct conf{
    int id;
    int s;
    int f;
};

bool cmp(conf a, conf b)
{
    if(a.f <= b.f)
        return true;
    else
        return false;

}

int main()
{
    conf arr[10000];
    int n, i, j, s, f, cnt = 1, prev, id;
    vector<int> vi;
    cin>> n;
    for(i = 0; i < n; i++){
        cin>> s >> f;
        arr[i].id = i;
        arr[i].s = s;
        arr[i].f = f;
    }

    sort(arr, arr+n, cmp);

    prev = arr[0].f;
    id = arr[0].id;
    vi.push_back(id);

    for(i = 1; i < n; i++){
        id = arr[i].id;
        s = arr[i].s;
        f = arr[i].f;

        if(s >= prev){
            cnt++;
            prev = f;
            vi.push_back(id);
        }
    }

    cout<< cnt << "\n";

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

