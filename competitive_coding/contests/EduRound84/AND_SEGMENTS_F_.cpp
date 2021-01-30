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
ll mod =   998244353;

const int N = 5e5 + 5;
vector<int> pref(N), ones(N), f(N), dp(N);

struct Q{
    int l, r, q;
    void in(){
        cin>>l>>r>>q;
    }
    bool operator<(const Q& a){
        return l < a.l;
    }
};

vector<Q> queries;

void add_self(int &x, int y){
    x += y;
    if(x >= mod) x -= mod;
}

void sub_self(int &x, int y){
    x -= y;
    if(x < 0) x += mod;
}

int n, k, m;

int calc(int lvl){
    /// for bit lvl
    ones.assign(n+2, 0);
    pref.assign(n+2, 0);
    f.assign(n+2, 0);
    dp.assign(n+2, 0);
    int l, r;

    for(auto it: queries){
        l = it.l;
        r = it.r;
        if(it.q & (1<<lvl)){
            ones[l]++;
            ones[r + 1]--;
        } else {
            f[r + 1] = max(f[r + 1], l);
        }
    }

    rep(i, 1, n+1) f[i] = max(f[i], f[i - 1]);  /// f[i] stores the max l of a zero segment that ends before i.

    dp[0] = 1;  /// dp[i] stores valid arrays that end at 0 and 0 segments contained within it atleast 1 0.
    pref[0] = 1;
    rep(i, 1, n + 1){
        if(!ones[i]){
            /// can put 0 here
            int &z = dp[i];
            add_self(z, pref[i - 1]);
            if(f[i]) sub_self(z, pref[f[i] - 1]);
        }

        int tmp = 0;
        pref[i] = (pref[i - 1] + dp[i]) % mod;
        ones[i + 1] = (ones[i + 1] + ones[i]) % mod;
    }

    return dp[n + 1];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    while(t--){

        cin>>n>>k>>m;
        queries.resize(m);
        fr(i, m) queries[i].in();

        int ans = 1;
        fr(i, k){
            ans = (ans * 1ll * calc(i)) % mod;
        }
        cout<<ans;
    }

    return 0;
}

