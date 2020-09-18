#include<bits/stdc++.h>

using namespace std;

vector<long long> v;

void rabin_karp(string text, string pattern)
{
    int n, m, i, j, k, cnt;
    int h, t = 0;
    n = text.size();
    m = pattern.size();

    int q = 31;
    int p = 0, s;
    int mod = 1e9 + 9;
    h = ((int)ceil(pow(q, m-1))) % mod;


    for(i = 0; i < m; i++){
        p = ((p * q) + (pattern[i] - 'a' + 1)) % mod;
        t = ((t * q) + (text[i] - 'a' + 1)) % mod;
    }


    for(s = 0; s <= n-m; s++){
        if(p == t){
            cnt = 0;
            for(i = s, k = 0; i < s+m; i++, k++){
                if(text[i] != pattern[k]){
                    cnt++;
                }
            }
            if(cnt == 0)
                v.push_back(s);
        }
        else
        {
            t = (((t - ((text[s] - 'a' + 1) * h)) * q) % mod) + ((text[m+s] - 'a' + 1) % mod);

        }
    }

    for(j = 0; j < v.size(); j++){
        cout<< v[j] << "\n";
    }


}

int main()
{
    string text = "ABAAABCDBBABCDDEBCABC";
    string pattern = "ABC";

    rabin_karp(text, pattern);



    return 0;
}

