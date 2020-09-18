#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, e, s, i, j, a, b, u, v;
    vector<int> adj[100];
    char color[100];
    int dis[100], par[100];
    queue<int> q;

    cin>> n >> e >> s;

    for(i = 0; i < e; i++){
        cin>> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);

    }

    for(i = 0; i < n; i++){
        if(i == s)continue;

        color[i] = 'W';
        dis[i] = -1;
        par[i] = -1;
    }

    color[s] = 'G';
    dis[s] = 0;
    par[s] = -1;

    q.push(s);

    while(q.size() != 0){
        u = q.front();
        q.pop();

        for(j = 0; j < adj[u].size(); j++){
            v = adj[u][j];
            if(color[v] == 'W'){
                color[v] = 'G';
                dis[v] = dis[u] + 1;
                par[v] = u;
                q.push(v);
            }
        }
        color[u] = 'B';
    }

    for(i = 0; i < n; i++){
        cout<< i << " " << color[i] << " " << dis[i] << " " << par[i] << "\n";
    }



    return 0;
}

