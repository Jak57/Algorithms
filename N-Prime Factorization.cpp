#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, i, j, m, cnt;
    cin>> n;
    m = n;

    for(i = 2; i*i <= n; i++){
        cnt = 0;
        while(n % i == 0){
            n /= i;
            cnt++;
        }

        if(cnt != 0)
            cout<< i << " " << cnt << "\n";

    }
    if(n > 1)
        cout<< n << " " << "1" << "\n";



    return 0;
}
//Using Seive

#include<bits/stdc++.h>
#define MAX 1000000

using namespace std;

int p[MAX+1];

void seive(int n)
{
    int i, j;
    p[1] = -1;

    for(i = 2; i*i <= n; i++){
        if(p[i] == 0){

            for(j = i*i; j <= n; j += i){
                if(p[j] == 0)
                    p[j] = i;
            }

        }
    }

}

int main()
{
    int n, i, j, m;
    cin>> n >> m;
    seive(n);

    while(m != 1){
        if(p[m] == 0)
            p[m] = m;

        cout<< p[m] << " ";
        m /= p[m];
    }

    return 0;
}
