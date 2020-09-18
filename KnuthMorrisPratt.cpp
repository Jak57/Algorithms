#include<bits/stdc++.h>

using namespace std;

int pi[1000];

void prefix_function(string s)
{
    int n, i, j;
    n = s.length();
    pi[0] = 0;

    for(i = 1, j = 0; i < n; i++){
        while(s[j] != s[i] && j > 0){
            j = pi[j-1];
        }
        if(s[j] == s[i]){
            j++;
        }
        pi[i] = j;

    }

}

void kmp_matcher(string text, string pattern)
{
    int m, n, i, j, cnt = 0;
    prefix_function(pattern);

    n = text.size();
    m = pattern.size();

    for(i = 0, j = 0; i < n; i++){
        while(j > 0 && text[i] != pattern[j])
            j = pi[j-1];

        if(text[i] == pattern[j]){
            j++;
        }

        if(j == m){
            printf("Pattern found at %d\n", i - m +1);
            j = pi[j-1];
        }
    }
}


int main()
{
    string text = "AABAACAADAABAABA";
    string pattern = "AABA";

    kmp_matcher(text, pattern);



    return 0;
}

