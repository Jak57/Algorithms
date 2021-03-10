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
