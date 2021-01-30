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

void solve(){
    int pref = 0, z;
    string s;
    cin>>s;
    int n = s.size();
    int prev = 0;

    vector<int> b;
    int d;

    fr(i, n){
        z = s[i] - '0';
        d = z - prev;
        pref += d;
        b.push_back(d);
        b.push_back(z); /// digit itself
        prev = z;
    }

    b.push_back(-pref);
    int m = b.size();
    char c[2] = {')', '('};

    fr(i, m){
        if(i&1) cout<<b[i];
        else {
            z = (b[i] >= 0);
            rep(j, 1, abs(b[i])) cout<<c[z];
        }
    }

    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    rep(i, 1, t){
        cout<<"Case #"<<i<<": ";
        solve();
    }

    return 0;
}

