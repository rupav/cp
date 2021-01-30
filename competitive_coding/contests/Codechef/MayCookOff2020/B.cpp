#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;

/// CHEFSHIP

vector<int> constructZFunc(string s){
    int n = s.size();
    vector<int> z(n, 0);
    int l(0), r(0);
    rep(i, 1, n-1){
        if(i <= r) z[i] = min(r-i+1, z[i-l]);
        while(i+z[i] < n && s[z[i]] == s[i+z[i]]) ++z[i];
        if(i+z[i]-1 > r){
            r = i+z[i]-1;
            l = i;
        }
    }
    return z;
}

int solve(){
    string s;
    cin>>s;
    int n = s.size();
    vector<int> z1 = constructZFunc(s);
    reverse(s.begin(), s.end());
    vector<int> z2 = constructZFunc(s);

    int ans = 0;
    int len;
    rep(i, 1, n - 1){
        if(z1[i] >= i){
            len = (n - 2*i);
            if(!len) continue;
            if(z2[len/2] >= len/2) ans++;
        }
    }

    return ans;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }

    return 0;
}

