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

ll gcdll(ll a, ll b){
    if(!b) return a;
    return gcdll(b, a%b);
}

void seive(int n){
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;

    for(int i=2; i*i<=n; i++){
        if(is_prime[i]){
            for(int j=i*i; j<=n; j+=i){
                is_prime[j] = false;
            }
        }
    }
}

vector<int> constructZFunc(string s){
    int n = s.size();
    vector<int> z(n);
    int l, r;
    l = r = 0;
    z[0] = 0;
    rep(i, 1, n-1){
        z[i] = 0;
        if(i<=r){
            z[i] = min(r-i+1, z[i-l]);  /// initialization, req. for linear time approach.
        }
        while(i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if(i+z[i]-1 > r){
            r = i+z[i]-1;
            l = i;
        }
    }
    return z;
}

ll msb(ll x){
    ll res = 0;
    while(x){
        res++;
        x /= 2ll;
    }
    return res - 1ll;
}

bool check(ll x, ll z){

    // watch(x);

    ll m = msb(x);
    ll n = msb(z);
    return (m == n && __builtin_popcount(x) == m + 1);
}

string fill_(ll x, ll y, char z, ll mb){
    ll m = msb(x^y);

    // watch(m);


    string s(m + 1, '@');
    fr(i, m+1){
        if((1<<i) & x) s[i] = (z == 'W') ? z : 'E';
        else if ((1<<i) & y) s[i] = (z == 'S') ? z : 'N';
        else if (i != 0 && (s[i-1] == 'N' || s[i-1] == 'E')){
            s[i-1] = (s[i-1] == 'N') ? 'S' : 'W';
            s[i] = (s[i-1] == 'S') ? 'N' : 'E';
        } else s[i] = '@';
    }

    if(mb != -1) s[mb] = (z == 'S') ? 'N' : 'W';
    return s;
}

void solve(){
    ll x, y;
    cin>>x>>y;
    ll ax(llabs(x)), ay(llabs(y));
    if(ax&1ll == ay&1ll){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }

    vector<string> res;
    if(true || check(ax^ay, max(ax, ay))){
        res.push_back(fill_(ax, ay, '@', -1));
    }

    ll mb = msb(ax);
    ll pw = pow(2ll, mb+1ll);

    // watch(pw);

    if(true|| check((2ll*pw - ax)^ay, max((2ll*pw - ax), ay))){
        res.push_back(fill_(2ll*pw - ax, ay, 'W', msb(pw)));
    }

    mb = msb(ay);
    pw = pow(2ll, mb+1ll);
    if(true || check((2ll*pw - ay)^ax, max((2ll*pw - ay), ax))){
        res.push_back(fill_(ax, 2ll*pw - ay, 'S', msb(pw)));
    }

    if(res.size() == 0) {
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }

    ll lim = 128;
    bool f;
    fr(i, res.size()){
        f = false;
        fr(j, res[i].size()){
            if(res[i][j] == '@') {
                f = true;
                break;
            }
        }
        if(f) res[i] = string(lim, '@');
    }

    int sz = res[0].size();
    int z = 0;
    fr(i, res.size()){

        // watch(res[i]);

        if(res[i].size() && res[i].size() < sz){
            sz = res[i].size();
            z = i;
        }
    }

    if(res[z].size() == lim) {
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }


    if(x < 0){
        fr(i, sz){
            char &al = res[z][i];
            if(al == 'E') al = 'W';
            else if(al == 'W') al = 'E';
        }
    }

    if(y < 0){
        fr(i, sz){
            char &al = res[z][i];
            if(al == 'S') al = 'N';
            else if(al == 'N') al = 'S';
        }
    }

    cout<<res[z]<<endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    rep(tc, 1, t){
        cout<<"Case #"<<tc<<": ";
        solve();
    }

    return 0;
}

