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

const int N = 2e5+10;
ll bit[N];  /// bit on starting indices
vector<pll> v;

void update(ll i, ll upd){
    for(; i<N; i += i&(-i)) bit[i] = (bit[i] + upd)%mod;
}

ll get(ll i){
    ll sum = 0ll;
    for(; i>0; i -= i&(-i)) sum = (sum + bit[i])%mod;
    return sum;
}

bool comp(pll a, pll b){
    return a.second > b.second;
}

int main(){
    ll n, m, st, en;
    cin>>n>>m;
    v.resize(m);
    set<ll> s;
    rep(i, 0, m-1) {
        cin>>st>>en;
        st++;
        en++;
        v[i].first = st;
        v[i].second = en;
        s.insert(st);
        s.insert(en);
    }
    s.insert(1ll);
    s.insert(n+1ll);

    ll val = 1ll;
    map<ll, ll> mp;
    for(auto it: s){
        mp[it] = val++;
    }

    for(int i=0; i<v.size(); i++){
        v[i].first = mp[v[i].first];
        v[i].second = mp[v[i].second];
    }

    sort(v.begin(), v.end(), comp);

    ll cnt = 0ll;
    ll ans = 0ll;
    for(auto it: v){
        ll temp = get(it.second) - get(it.first);
        if(it.second != mp[n+1ll] && temp == 0ll){
            cnt = 0ll;
            break;
        }
        temp = max(1ll, temp);
        cnt = (cnt + temp)%mod;
        // cout<<it.first<<": "<<it.second<<endl;
        // cout<<cnt<<" "<<temp<<endl;
        if(it.first == mp[1ll]) ans = (ans + temp)%mod;
        update(it.first, temp);
    }

    cout<<ans;

    return 0;
}
