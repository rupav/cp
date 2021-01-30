#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

char flagBasedIndex(bool flag){
    if(flag)
        return 'A';
    return 'a';
}

void alternateUpperLowerSort(string s){
    int freq[2][26];
    memset(freq, 0, sizeof(freq));
    for(auto c: s){
        if(c>='a' && c<='z'){
            freq[0][c-'a']++;
        } else {
            freq[1][c-'A']++;
        }
    }
    bool flag = true;
    int k[2] = {0};
    int count = 0;
    while(count<s.size()){
        while(k[flag]<26 && freq[flag][k[flag]] == 0){
            k[flag]++;
        }
        if(k[flag] < 26){
            cout<<(char)(k[flag] + flagBasedIndex(flag));
            freq[flag][k[flag]]--;
            count++;
        }
        flag = !flag;
    }
}

void alternateUpperLowerSort2(string ss){
    string s, t;
    for(auto c: ss){
        if(c>='a' && c<='z'){
            s += c;
        } else {
            t += c;
        }
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
}

int main(){
    string s;
    cin>>s;
    alternateUpperLowerSort(s);
    return 0;
}

