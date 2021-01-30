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


ll solve(){
    ll n, m, x;
    cin>>n>>m;
    map<ll, ll> mp;
    fr(i, m){
        cin>>x;
        mp[x]++;
    }

    ll cnt = 0ll;
    for(ll i = 0; i <= 60; ++i){
        if((1ll << i)&n){
            if(!mp[1ll << i]){

                bool f = false;
                for(ll j = i + 1; j <= 60; ++j){
                    if(mp[1ll << j]){
                        f = true;

                        cnt += (j - i);
                        mp[1ll << j]--;

                        for(ll k = j - 1; k > i; --k){
                            mp[1ll << k]++;
                        }

                        break;
                    }
                }

                if(!f) return -1ll;

            } else mp[1ll << i]--;
        }

        mp[1ll << (i + 1)] += mp[1ll << i]/2ll;
    }

    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    ll t = 1;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }

    return 0;
}

