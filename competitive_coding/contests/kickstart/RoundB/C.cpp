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

#define inf INT_MAX

void solve(){
    string s;
    cin>>s;
    int n = s.size();
    s = "1(" + s + ")";

    stack<ll> fac;
    stack<string> dir;
    stack<pll> res;
    ll x;

    string t = "";
    ll temp[2];
    ll cnt[2] = {0ll};


    for(auto it: s){
        if(res.size()){
            watch(res.top().first);
            watch(res.top().second);
        }
        else watch(0);

        if(it >= '1' && it <= '9'){
            if(t != ""){
                dir.push(t);
                t = "";
            }
            fac.push(1ll*(it - '0'));
        } else if (it == '(') {
            if(t != ""){
                dir.push(t);
                t = "";
            }
            res.push({inf, inf});
            dir.push("@");
        } else if (it == ')') {
            dir.push(t);

            temp[0] = temp[1] = 0;
            while(res.size() && res.top().first != inf){
                temp[0] += res.top().first;
                temp[1] += res.top().second;
                res.pop();
            }
            res.pop();

            t = "";
            while(dir.size() && dir.top() != "@"){
                t += dir.top();
                dir.pop();
            }
            // watch(t);
            dir.pop();

            for(auto jit: t){
                if(jit == 'N' || jit == 'S') temp[0] += ((jit == 'S') ? 1 : -1);
                else temp[1] += ((jit == 'E') ? 1 : -1);
            }
            x = fac.top();
            res.push({x*temp[0], x*temp[1]});
            cnt[0] += x*temp[0];
            cnt[1] += x*temp[1];

            fac.pop();
            dir.pop();
            t = "";
        } else {
            t += it;
        }
    }

    cout<<cnt[0]<<" "<<cnt[1]<<endl;

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

