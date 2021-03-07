#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, i, j, b[100][100];
    string x, y;
    cin>> x >> y;
    n = x.size();
    m = y.size();

    for(i = 0; i <= n; i++)
        b[i][0] = 0;
    for(j = 0; j <= m; j++)
        b[0][j] = 0;

    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){

            if(x[i-1] == y[j-1])
                b[i][j] = b[i-1][j-1] + 1;
            else
                b[i][j] = max(b[i][j-1], b[i-1][j]);
        }
    }

    cout<< b[n][m] << "\n";

    return 0;
}
/*
ABCBDAB
BDCABA
*/

