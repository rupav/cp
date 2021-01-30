#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;

vector<int> z_array(string s, int n){
    vector<int> z(n, 0);
    z[0] = n;
    int l, r;
    l = r = 0;  /// never seen anything
    int i=1;
    while(i<n){
        if(r >= i){
            z[i] = min(z[i-l], r-i+1);  /// initialization
        }
        while(i+z[i]<n && s[z[i]] == s[i + z[i]]) ++z[i];
        if(i+z[i]-1 > r){
            r = i+z[i]-1;
            l = i;
        }
        i++;
    }
    return z;
}

map<int, int> mp;  /// count the freq of those prefixes, which matches the suffixes, then substrings mathing these prefices, have same z[i] too!

int main(){
    string s;
    cin>>s;
    int n = s.size();
    vector<int> z = z_array(s, n);
    set<int> l;  /// length of z[i], which matches
    fr(i, n){
        mp[z[i]]++;
        if(z[i] + i == n){
            /// we have found the match with suffix and prefix!
            l.insert(z[i]);
        }
    }
    cout<<l.size()<<endl;
    /// now each prefix of length j>k matched, then k will be too counted
    int sum = 0;
    for(map<int, int>:: reverse_iterator rit = mp.rbegin(); rit != mp.rend(); ++rit){
        rit->second += sum;
        sum = rit->second;
    }

    for(auto it: l){
        cout<<it<<" "<<mp[it]<<endl;
    }
    return 0;
}
