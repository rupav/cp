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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll q;
    cin>>q;
    ll n, x;
    ll res = 0;
    ll m;
    while(q--){
        cin>>n;
        ll cnt[n+1] = {0};
        fr(i, n){
            cin>>x;
            cnt[x]++;
        }
        map<ll, ll, greater<ll> > rmp;
        rep(i, 1, n){
            rmp[cnt[i]]++;
        }

        ll prev = 0;
        ll pit = -1;
        res = 0;
        for(auto it: rmp){
            res += it.first;
            if(pit != -1){
                m = min(pit - it.first - 1ll, prev);
                if(m){
                    res += ((pit-1)*(pit))/2 - max(0ll, ((pit-1-m)*(pit-m))/2);
                }
                prev -= min(pit - it.first - 1ll, prev);
            }
            prev += (it.second - 1);
            pit = it.first;
        }

        if(pit!=-1){
            m = min(pit - 0ll - 1ll, prev);
            if(m){
                res += ((pit-1)*(pit))/2 - max(0ll, ((pit-1-m)*(pit-m))/2);
            }
        }
        cout<<res<<endl;
    }

    return 0;
}

