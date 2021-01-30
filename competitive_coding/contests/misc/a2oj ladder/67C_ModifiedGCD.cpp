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

vector<int> getDivisors(int x){
    vector<int> v;
    for(int i=1; i*i <= x;  i++){
        if(x%i == 0){
            v.push_back(i);
            if(i != x/i)
                v.push_back(x/i);
        }
    }
    sort(v.begin(), v.end());
    return v;
}

void solve(){
    int a, b, q, lo, hi;
    cin>>a>>b;

    vector<int> d1 = getDivisors(a);
    vector<int> d2 = getDivisors(b);

    vector<int> v(d1.size() + d2.size() + 1);
    vector<int>::iterator it = set_intersection(d1.begin(), d1.end(), d2.begin(), d2.end(), v.begin());
    v.resize(it - v.begin());

    cin>>q;
    while(q--){
        cin>>lo>>hi;
        auto ub = upper_bound(v.begin(), v.end(), hi) - v.begin();
        ub--;
        if(ub < 0 || v[ub] < lo) cout<<-1<<endl;
        else cout<<v[ub]<<endl;
    }
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

