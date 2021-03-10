#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, ans = 0, i;
    cin>> n;

    for(i = 2; i*i <= n; i++){
        if(n % i == 0){
            ans++;
            break;
        }
    }

    if(ans > 0 || n == 1)
        cout<< "NO" << "\n";
    else
        cout<< "YES" << "\n";


    return 0;
}
