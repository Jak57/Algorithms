#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

const int INF = 1e9;

int main()
{
    int n, e, s, i, j, a, b, u, v, w, dis[100], par[100], weight, we, cnt = 0;
    vector< pair<ii, int> > adj;
    cin>> n >> e >> s;

    for(i = 0; i < e; i++){
        cin>> a >> b >> w;
        adj.push_back(make_pair(make_pair(a, b), w));
    }

    for(i = 0; i < n; i++){
        dis[i] = INF;
        par[i] = -1;
    }
    dis[s] = 0;


    for(i = 1; i < n; i++){
        for(j = 0; j < e; j++){
            u = adj[j].first.first;
            v = adj[j].first.second;

            weight = adj[j].second;

            if(dis[v] > dis[u] + weight){
                dis[v] = dis[u] + weight;
                par[v] = u;
            }
        }
    }

    for(i = 0; i < e; i++){

        u = adj[i].first.first;
        v = adj[i].first.second;
        weight = adj[i].second;

        if(dis[v] > dis[u] + weight){
            cnt++;
        }
    }

        for(i = 0; i < n; i++){
            cout<< dis[i] << " ";
        }


    return 0;
}
