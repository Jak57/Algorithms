#include<bits/stdc++.h>

using namespace std;

vector<int> adj[100];
vector<int> radj[100];
vector<int> ans[100];
char color[100], rcol[100];
int t, dis[100], fin[100], k = -1;
stack<int> s;
vector<int> ve;

void rdfs(int u)
{
    int j, v;
    rcol[u] = 'G';
    ans[k].push_back(u);
    for(j = 0; j < radj[u].size(); j++){
        v = radj[u][j];

        if(rcol[v] == 'W')
            rdfs(v);
    }
}

void dfs(int u)
{
    int i, j, v;
    t = t + 1;
    dis[u] = t;
    color[u] = 'G';

    for(j = 0; j < adj[u].size(); j++){
        v = adj[u][j];
        if(color[v] == 'W')
            dfs(v);
    }

    s.push(u);
    ve.push_back(u);
    color[u] = 'B';
    t = t + 1;
    fin[u] = t;
}

int main()
{
    int n, e, i, j, a, b, u;
    cin>> n >> e;

    for(i = 0; i < e; i++){
        cin>> a >> b;
        adj[a].push_back(b);
        radj[b].push_back(a);

    }

    for(i = 0; i < n; i++){
        color[i] = 'W';
        rcol[i] = 'W';
    }



    for(i = 0; i < n; i++){
        if(color[i] == 'W')
            dfs(i);
    }

    while(s.size() != 0){
        u = s.top();
        s.pop();
        k = k + 1;
        if(rcol[u] == 'W'){
            rdfs(u);
        }
    }

    for(i = 0; i < k + 1; i++)
    {
        if(ans[i].size() == 0)continue;
        for(j = 0; j < ans[i].size(); j++){
            cout<< ans[i][j] << " ";
        }
        cout<< "\n";
    }

    return 0;
}


