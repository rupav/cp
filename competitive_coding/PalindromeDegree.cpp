#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

string reverseS(string s){
    string k = "";
    fr(i, s.size()){
        k+=s[s.size()-i-1];
    }
    return k;
}

int main(){
    string s;
    cin>>s;
    int n = s.size();
    string t = reverseS(s);
    string ss = s + t;
    int *lps = new int[2*n];  /// longest prefix suffix.
    lps[0] = 0;
    for(int i=1; i<2*n; i++){
        if(ss[lps[i-1]] == ss[i]){
            lps[i] = lps[i-1] + 1;
        } else {
            if(ss[i] == ss[0])
                lps[i] = 1;
            else
                lps[i] = 0;
        }
    }

    int sum = 0;
    int lpp = min(lps[(n*2)-1], n);
    sum = lpp;
    lpp--;
    while(lpp >= 0){
        sum += 1;
        lpp = lps[lpp]-1;
    }
    cout<<sum;
    return 0;
}

