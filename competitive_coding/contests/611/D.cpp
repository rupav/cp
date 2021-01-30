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

ll gcdll(ll a, ll b){
    if(!b) return a;
    return gcdll(b, a%b);
}

int gcd(int a, int b){
    if(!b) return a;
    return  gcd(b, a%b);
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, m;
    map<ll, ll> rmp;
    map<ll, ll> lmp;
    cin>>n>>m;
    vector<ll> x(n+2);
    x[0] = -1ll*2e9;
    rep(i, 1, n){
        cin>>x[i];
    }
    x[n+1] = 2e9;
    sort(x.begin(), x.end());

    ll d;
    rep(i, 1, n){
        d = x[i] - x[i-1] - 1;
        lmp[i] = d/2;
        d = x[i+1] - x[i] - 1;
        rmp[i] = d/2 + (d&1ll);
    }

    vector<ll> ans;
    ll val = 0ll;

    /*
    for(auto it: lmp) {
        cout<<it.second<<" ";
    }
    cout<<endl;
    for(auto it: rmp) {
        cout<<it.second<<" ";
    }
    cout<<endl;
    */

    ll curr = 1;
    while(m){
        for(auto it = lmp.begin(); it != lmp.end();){
            if(it->second == 0){
                lmp.erase(it++);
                continue;
            }

            ans.push_back(x[it->first] - curr);
            it->second--;
            val += curr;
            it++;
            m--;
            if(!m) break;
        }
        if(!m) break;

        for(auto it = rmp.begin(); it != rmp.end();){
            if(it->second == 0){
                rmp.erase(it++);
                continue;
            }

            ans.push_back(x[it->first] + curr);
            it->second--;
            val += curr;
            it++;
            m--;
            if(!m) break;
        }
        curr++;
    }

    cout<<val<<endl;
    for(auto it: ans) cout<<it<<" ";

    return 0;
}

