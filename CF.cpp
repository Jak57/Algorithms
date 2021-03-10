#include<bits/stdc++.h>
#define MAX 1000001

using namespace std;

bool p[MAX];

void seive(int n)
{
    int i, j;
    p[1] = 1;

    for(i = 4; i <= n; i += 2)
        p[i] = 1;

    for(i = 3; i*i <= n; i += 2){
        if(p[i] == 0){
            for(j = i*i; j <= n; j += i)
                p[j] = 1;

        }

    }


}

int main()
{
    int n, i, j;
    cin>> n;

    seive(n);
    for(i = 2; i <= n; i++){
        if(p[i] == 0)
            cout<< i << "\n";
    }

    return 0;
}
