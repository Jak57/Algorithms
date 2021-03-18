#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll mulmod(ll a, ll b, ll c)
{
    ll x = 0;
    ll y = a % c;

    while(b > 0){
       if(b % 2 == 1)
           x = (x+y)%c;

       y = (y*2LL)%c;
       b /= 2;
    }

    return x % c;
}

ll power(ll a, ll n, ll m)
{
    ll res = 1;

    while(n > 0){
        if(n % 2 == 1)
            res = mulmod(res, a, m);

        a = mulmod(a, a, m);
        n /= 2;
    }
    return res % m;
}

bool isPrime(ll p)
{
    ll a;
    int n = 5, i;
    if(p <= 4)
        return (p == 2 || p == 3);

    a = 2 + rand() % (p-3);

    for(i = 1; i <= n; i++){
        if(power(a, p-1, p) != 1)
            return false;
    }

    return true;
}

int main()
{
    int t, i;
    ll p;
    cin>> t;

    for(i = 1; i <= t; i++){
        cin>> p;
        if(isPrime(p))
            cout<< "YES" << "\n";
        else
            cout<< "NO" << "\n";
    }

    return 0;
}
