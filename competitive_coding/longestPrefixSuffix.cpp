#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

int findLPS(string s, int n){
    int *lps = new int[n];
    lps[0] = 0;
    rep(i, 1, n-1){
        int j = i-1;
        while(lps[j]!=0 && s[lps[j]] != s[i]){
            if(j == lps[j])  /// consider i=2 in aab string.
                j=0;
            else
                j = lps[j];
        }
        if(s[lps[j]] == s[i]){
            lps[i] = lps[j]+1;
        } else {
            lps[i] = 0;
        }
    }
    return lps[n-1];
}

/// using z-function
int findLPSUsingZFunc(string s){
    int n = s.size();
    vector<int> z(n);
    z[0] = 0;
    int l, r;
    l = r = 0;
    rep(i, 1, n-1){
        z[i] = 0;
        if(i<=r){
            z[i] = min(z[i-l], r-i+1);
        }
        while(z[i]+i < n && s[z[i]] == s[z[i]+i])
            ++z[i];
        if(z[i]+i-1 > r){
            r = z[i]+i-1;
            l = i;
        }
    }

    int res = 0;
    fr(i, n){
        if(z[i]+i == n){
            res = z[i];
            break;
        }
    }
    return res;
}

int main(){
    string s;
    cin>>s;
    int n = s.size();
    cout<<findLPS(s, n);
    cout<<endl;
    cout<<findLPSUsingZFunc(s);
    return 0;
}
