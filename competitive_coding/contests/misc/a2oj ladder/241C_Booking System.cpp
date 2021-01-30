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

struct Node{
    int sum;
    int sz;
    int i;
};

bool compare(Node a, Node b){
    return a.sum > b.sum;
}

void solve(){
    int n, k, sum, sz;
    cin>>n;
    map<int, stack<int>> mp;
    Node nodes[n + 1];
    rep(i, 1, n){
        cin>>sz>>sum;
        nodes[i].sum = sum;
        nodes[i].i = i;
        nodes[i].sz = sz;
    }
    sort(nodes + 1, nodes + n + 1, compare);

    cin>>k;
    int tables[k + 1];
    set<int> s;
    rep(i, 1, k){
        cin>>tables[i];
        mp[tables[i]].push(i);
        s.insert(tables[i]);
    }

    sum = 0;
    vector<pii> res;
    rep(i, 1, n){
        auto ub = s.lower_bound(nodes[i].sz);
        if(ub != s.end()) {
            sum += nodes[i].sum;
            res.push_back({nodes[i].i, mp[*ub].top()});
            mp[*ub].pop();
            if(mp[*ub].empty()) s.erase(ub);
        }
    }

    cout<<res.size()<<" "<<sum<<endl;
    for(auto it: res) cout<<it.first<<" "<<it.second<<endl;

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

