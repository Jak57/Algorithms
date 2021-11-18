#include <bits/stdc++.h>
using namespace std;

char directions[100][100];
vector<char> subsequence;

void print_LCS(string X, int i, int j);

int main()
{
    string X, Y;
    int n, m, i, j, arr[100][100], p, q;

    cin>> X >> Y;

    m = X.size();
    n = Y.size();

    for (i = 0; i <= m; i++)
        arr[i][0] = 0;

    for (j = 0; j <= n; j++)
        arr[0][j] = 0;

    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            p = i-1;
            q = j-1;

            if (X[p] == Y[q])
            {
                arr[i][j] = arr[i-1][j-1] + 1;
                directions[i][j] = 'D';
            }
            else if (arr[i-1][j] > arr[i][j-1])
            {
                arr[i][j] = arr[i-1][j];
                directions[i][j] = 'U';
            }
            else
            {
                arr[i][j] = arr[i][j-1];
                directions[i][j] = 'L';
            }
        }
    }

    print_LCS(X, m, n);
    printf("Maximum length of common subsequence of %d\n", arr[m][n]);
    cout<< "Longest common subsequence is: ";

    for (i = 0; i < subsequence.size(); i++)
        cout<< subsequence[i];
    cout<< "\n";

    return 0;
}


void print_LCS(string X, int i, int j)
{
    if (i == 0 or j == 0)
        return;

    if (directions[i][j] == 'D')
    {
        print_LCS(X, i-1, j-1);
        subsequence.push_back(X[i-1]);
    }
    else if (directions[i][j] == 'U')
        print_LCS(X, i-1, j);
    else
        print_LCS(X, i, j-1);

}

/*
ABCBDAB
BDCABA
*/
