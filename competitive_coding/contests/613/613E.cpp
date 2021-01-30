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



ll solve(){
    ll n;
    cin>>n;
    vector<pll> v(n);
    fr(i, n) cin>>v[i].first>>v[i].second;
    sort(v.begin(), v.end());

    /// find union of n segments
    ll max_ = v[0].second;
    ll cnt = 1;
    rep(i, 1, n-1){
        if(v[i].first > max_){
            // non intersecting
            cnt++;
        }
        max_ = max(v[i].second, max_);
    }

    cout<<cnt<<endl;

    bool flag = false;
    rep(i, 1, n-2){
        /// removing this segment
        if(v[i-1].second >= v[i].first && v[i+1].first <= v[i].second){
            /// currently imtersecting
            if(v[i-1].second >= v[i+1].first){
                flag = true;
            } else {
                return (cnt+1);  /// max
            }
        } else if(v[i-1].second < v[i].first && v[i+1].first > v[i].second){

        } else {
            flag = true;
        }
    }
    if(!flag) return (cnt-1);  /// all seg were nonintersecting
    return cnt;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }

    return 0;
}

