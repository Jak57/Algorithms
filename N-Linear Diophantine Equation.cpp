#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b, int &x, int &y)
{

    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;

    int d = gcd(b, a%b, x1, y1);
    x = y1;
    y = x1 - y1 * (a/b);

    return d;
}

int main()
{
    int a, b, c, x, y, g;
    cin>> a >> b >> c;

    g = gcd(a, b, x, y);

    if(c % g != 0)
        cout<< "No solution exist" << "\n";
    else{
        cout<< x*(c/g) << " " << y*(c/g) << "\n";
    }


    return 0;
}
/*
5x+37 = 24
*/
