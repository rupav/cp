#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

int findMinCuts(string &s, int n){
    if(n&1)
        return 2;

    string l = s.substr(0, n/2);
    string k = s.substr(n/2, n/2);
    if(l != k)
        return 1;
    return findMinCuts(l, n/2);
}

int main(){
    string s;
    cin>>s;
    int n = s.size();
    if(n <= 3){
        cout<<"Impossible";
        return 0;
    }

    vector<int> freq(255);
    for(auto i: s){
        ++freq[i];
    }

    int maxFreq = *max_element(freq.begin(), freq.end());
    if(maxFreq >= n-1){
        cout<<"Impossible";
        return 0;
    }

    cout<<findMinCuts(s, n);

    return 0;
}
