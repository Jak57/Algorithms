#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    int t;
    while(b > 0){
       t = a;
       a = b;
       b = t % b;
    }
    return a;
}

int main()
{
    int a, b;
    cin>> a >> b;

    cout<< gcd(a, b) << "\n";

    return 0;
}

