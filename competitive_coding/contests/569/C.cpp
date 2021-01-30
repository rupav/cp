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

    ll n, q;
    cin>>n>>q;
    ll a[n];
    deque<ll> dq;
    ll max_ = 0ll;
    fr(i, n) {
        cin>>a[i];
        max_ = max(max_, a[i]);
        dq.push_back(a[i]);
    }

    pll ans[n+1]; // for n iterations
    ll x, y;
    rep(i, 1, n){
        x = dq.front();
        dq.pop_front();
        y = dq.front();
        dq.pop_front();

        ans[i] = {x, y};
        if(x > y){}
        else{
            ll t = y;
            y = x;
            x = t;
        }

        dq.push_front(x);
        dq.push_back(y);
    }

    /// now dq will have max element fixed at front
    ll pos[n-1];
    dq.pop_front();

    rep(i, 0, n-2){
        pos[i] = dq.front();
        dq.pop_front();
    }

    ll it;
    fr(i, q){
        cin>>it;
        if(it <= n){
            cout<<ans[it].first<<" "<<ans[it].second<<endl;
        } else {
            it -= (n+1);
            it = it%(n-1);
            cout<<max_<<" "<<pos[it]<<endl;
        }
    }

    return 0;
}

