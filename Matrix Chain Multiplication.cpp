#include<bits/stdc++.h>
#define INF 1e9

using namespace std;

int main()
{
    int len, i, j, k, n;
    int m[100][100], l, q, p[10000];
    cin>> len;

    for(i = 0; i < len; i++)
        cin>> p[i];

    n = len-1;
    for(i = 1; i <= n; i++)
        m[i][i] = 0;

    for(l = 2; l <= n; l++){
        for(i = 1; i <= n-l+1; i++){
            j = i+l-1;
            m[i][j] = INF;

            for(k = i; k <= j-1; k++){
                q = m[i][k] + m[k+1][j] + (p[i-1]*p[k]*p[j]);
                if(q < m[i][j]){
                    m[i][j] = q;
                }

            }
        }
    }

    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            cout<< m[i][j] << " ";
        }
        cout<< "\n";
    }


    return 0;
}

/*
7
30 20 15 5 10 5 10
*/
