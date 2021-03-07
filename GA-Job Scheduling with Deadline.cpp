#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, i, j, d, p, dead[100000], id, slot[100000], ans = 0, s = 0;
    memset(slot, 0, sizeof(slot));
    priority_queue< pair<int, int> > pq;
    vector<int> vi;
    cin>> n;

    for(i = 0; i < n; i++){
        cin>> d >> p;
        pq.push(make_pair(p, i));
        dead[i] = d;
    }

    while(pq.size() > 0){
        id = pq.top().second;
        p = pq.top().first;
        d = dead[id]-1;
        pq.pop();

        while(d >= 0){
            if(slot[d] == 0){
                ans += p;
                slot[d] = 1;
                vi.push_back(id);
                break;

            }

            d--;
        }
    }
    cout<< ans << "\n";
    for(i = 0; i < vi.size(); i++)
        cout<< vi[i] << " ";
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

