
#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
const int INF = 1e9;

int main()
{
    int n, e, s, a, b, i, j, w, u, v, weight, wei;
    vector< pair<int, int> > adj[100];
    int dis[100], par[100];
    cin>> n >> e >> s;

    for(i = 0; i < e; i++){
        cin>> a >> b >> w;
        adj[a].push_back(make_pair(b, w));
    }

    for(i = 0; i < n; i++){
        dis[i] = INF;
        par[i] = -1;
    }
    dis[s] = 0;

    priority_queue< ii, vector<ii>, greater<ii> > pq;
    pq.push(make_pair(0, s));


    while(pq.size() != 0){
        u = pq.top().second;
        pq.pop();
        weight = pq.top().first;

        for(j = 0; j < adj[u].size(); j++){
            wei = adj[u][j].second;
            v = adj[u][j].first;

            if(dis[v] > dis[u] + wei){
                dis[v] = dis[u] + wei;
                pq.push(make_pair(dis[v], v));
            }
        }
    }

    for(i = 0; i < n; i++){
        cout<< dis[i] << " ";
    }

    return 0;
}
