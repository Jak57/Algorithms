#include<bits/stdc++.h>

using namespace std;

int phi(int n)
{
    int i, ans = n;

    for(i = 2; i*i <= n; i++){

        if(n % i == 0){
            while(n % i == 0)
                n /= i;

           ans = (ans*(i-1))/i;
        }
    }

    if(n > 1)
        ans = (ans*(n-1))/n;

    return ans;
}

int main()
{
    int n, i, t, j;
    cin>> t;

    for(i = 1; i <= t; i++){
        cin>> n;
        cout<< phi(n) << "\n";
    }


    return 0;
}
/*
1
2
3
4
5
6
7
8
9
10
*/
//In a range

#include<bits/stdc++.h>
#define MAX 1000000

using namespace std;

int arr[MAX];

void phi(int n)
{
    int i, j;
    for(i = 1; i <= n; i++)
        arr[i] = i;

    for(i = 2; i <= n; i++){
        if(arr[i] == i){
            for(j = i; j <= n; j += i){
                arr[j] = (arr[j] * (i-1)) / i;
            }
        }
    }

}

int main()
{
    int n, i, t, j;
    cin>> t;
    phi(100000);

    for(i = 1; i <= t; i++){
        cin>> n;
        cout<< arr[n] << "\n";
    }


    return 0;
}
/*
1
2
3
4
5
6
7
8
9
10
*/

