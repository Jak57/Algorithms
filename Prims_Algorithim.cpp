
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, e, i, j, s, w, a, b, ed, we, u, v, cost = 0, weight, x, y, z;
    vector< pair<int, int> > adj[100];
    vector<int> vi;
    cin>> n >> e >> s;

    for(i = 0; i < e; i++)
    {
        cin>> a >> b >> w;
        adj[a].push_back(make_pair(b, w));
        adj[b].push_back(make_pair(a, w));
    }

    priority_queue<pair<int, int> > pq;
    int taken[1000];
    memset(taken, 0, sizeof(taken));
    taken[s] = 1;

    for(i = 0; i < adj[s].size(); i++){
        ed = adj[s][i].first;
        we = - (adj[s][i].second);

        pq.push(make_pair(we, ed));
    }

    while(pq.size() != 0){
        weight = -(pq.top().first);
        u = pq.top().second;
        pq.pop();
        if(taken[u] == 1)
            continue;

        taken[u] = 1;
        cost += weight;
        vi.push_back(weight);
        for(j = 0; j < adj[u].size(); j++){
            v = adj[u][j].first;

            if(taken[v] == 0){
                y = adj[u][j].first;
                z = - (adj[u][j].second);
                pq.push(make_pair(z, y));
            }
        }
    }

    cout<< cost << "\n";
    for(i = 0; i < vi.size(); i++){
        cout<< vi[i] << " ";
    }




    return 0;
}
