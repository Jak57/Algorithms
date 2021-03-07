#include<bits/stdc++.h>
#define p 1000003

using namespace std;

int f[1000001];

//Binary Exponentiation
int power(int a, int n)
{
    int res = 1;
    while(n > 0){
        if(n % 2 == 1)
            res = (res * 1LL *a) % p;

        a = (a * 1LL * a) % p;
        n /= 2;
    }
    return res;
}

int C(int n, int k)
{
    if(k > n)
        return 0;

    int res = f[n];
    res = (res * 1LL * power(f[k], p-2)) % p;
    res = (res * 1LL * power(f[n-k], p-2)) % p;

    return res;

}

int main()
{
    int i, j, n, k, t;
    f[0]=1; f[1] = 1;

    for(i = 2; i <= 1000000; i++){
        f[i] = (i * 1LL * f[i-1]) % p;
    }
    cin>> t;

    for(i = 1; i <= t; i++){
        cin>> n >> k;

        printf("Case %d: %d\n", i, C(n, k));
    }

    return 0;
}

