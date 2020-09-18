#include<bits/stdc++.h>

using namespace std;

vector<int> adj[100];

int p[100], dis[100], f[100], t;
char color[100];

void dfs(int u)
{
    int j, v;
    t = t + 1;
    dis[u] = t;
    color[u] = 'G';

    for(j = 0; j < adj[u].size(); j++){
        v = adj[u][j];

        if(color[v] == 'W'){
            p[v] = u;
            dfs(v);
        }
    }
    color[u] = 'B';
    t = t + 1;
    f[u] = t;
}

int main()
{
    int n, e, i, j, a, b, u;
    cin>> n >> e;

    for(i = 0; i < e; i++){
        cin>> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(i = 0; i < n; i++){
        color[i] = 'W';
        p[i] = -1;
    }


    for(i = 0; i < n; i++){
        u = i;
        if(color[u] == 'W')
            dfs(u);
    }

    for(i = 0; i < n; i++){
        cout<< i << " " << dis[i] << " " << f[i] << " " << color[i] << "\n";
    }

    return 0;
}

