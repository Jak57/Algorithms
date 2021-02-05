#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i, n, j;
    double a, total = 0, cap, wt, p;
    vector< pair<double, double> >vi;
    priority_queue< pair<double, int> > pq;

    cin>> n >> cap;
    for(int i = 0; i < n; i++)
    {
        cin>> wt >> p;
        vi.push_back(make_pair(wt, p));
        a = p / wt;
        pq.push(make_pair(a, i));
    }

    for(i = 0; i < n; i++){
        j = pq.top().second;
        pq.pop();
        wt = vi[j].first;
        p = vi[j].second;

        if(wt <= cap){
            total += p;
            cap -= wt;
        }
        else{
            total += (p * (cap/wt));
            break;
        }
    }

    cout<< total << "\n";

    return 0;
}

//n = 3 capacity = 50
//weight 10 20 30
//profit 60 100 120

