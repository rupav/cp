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

/// to find largest subsequence ababababa....b or ababababa....a
void solve(){
    int n;
    cin>>n;
    int arr[n + 1];
    map<int, vector<int>> pos;
    map<pii, pii> res;

    rep(i, 1, n) {
        cin>>arr[i];
        pos[arr[i]].push_back(i);
    }

    for(auto &it: pos) {
        it.second.push_back(inf);
    }

    int a, b;
    /// for each 'a'
    for(auto it: pos){
        a = it.first;
        // watch(a);
        int sz = it.second.size();
        fr(i, sz - 1){
            for(auto jit: pos){
                if(jit.first == a) continue;

                b = jit.first;
                auto ub = upper_bound(jit.second.begin(), jit.second.end(), it.second[i]);
                if(*ub < it.second[i+1]){
                    // watch(*ub);
                    res[{a, b}].first += 1;
                } else if (i == sz - 2){
                    /// include last element as a
                    res[{a, b}].second = 1;
                }
            }
        }
    }

    int mx = 1;
    int cnt = 0;
    for(auto it: res){
        cnt = it.second.first;
        cnt *= 2;
        cnt += it.second.second;

        mx = max(mx, cnt);
    }

    cout<<mx;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    //  cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

