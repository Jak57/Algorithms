# hello-world

Activity Selection Problem:

#include<iostream>
#include<algorithm>

using namespace std;

int p;
struct Act
{
    char id;
    int start;
    int finish;
};

bool comparison(Act a, Act b)
{
    return (a.finish < b.finish);
}

void func(Act arr[], int n)
{
    sort(arr, arr + n, comparison);

    int result[n], i = 0, k = 0;
    for(int j = 1; j < n; j++)
    {
        if(arr[j].start >= arr[i].finish)
        {
            result[k] = j;
            i = j;
            p++;
            k++;
        }
    }

   cout<<arr[0].id<<" ";
   for(int i = 0; i < p; i++)
        cout<<arr[result[i]].id<<" ";

}

int main()
{
    Act arr[] = {{'a', 1, 2}, {'b', 3, 4}, {'c', 0, 6}, {'d', 5, 7}, {'e', 8, 9}, {'f', 5, 9}};
    int n = sizeof(arr) / sizeof(arr[0]);
    func(arr, n);

    return 0;
}








