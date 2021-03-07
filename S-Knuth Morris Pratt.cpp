#include<bits/stdc++.h>

using namespace std;

int pi[1000];
vector<int> v;

void kmp_matcher(string text, string pattern)
{
    int m, n, i, j;
    pi[0] = 0;
    n = text.size();
    m = pattern.size();

    string temp = pattern + "#" + text;
    int l = temp.size();

    for(i = 1, j = 0; i < l; i++){
        while(j > 0 && temp[j] != temp[i]){
            j = pi[j-1];
        }

        if(temp[j] == temp[i])
            j++;

        pi[i] = j;
        if(pi[i] == m)
            v.push_back(i-(2*m));
    }

    for(i = 0; i < v.size(); i++)
        cout<< v[i] << "\n";
}

int main()
{
    string text = "AABAACAADAABAABA";
    string pattern = "AABA";

    kmp_matcher(text, pattern);

    return 0;
}
