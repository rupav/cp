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


void solve(){
    ll x;
    cin>>x;
    vector<ll> pw;

    // map<ll, int> mp;
    ll lim = numeric_limits<ll>::max();
    ll i = 0;
    while(!i || lim/(i*i*i*i) > i){
        pw.push_back(i*i*i*i*i);
        i++;
    }

    ll z = pw.size();
    ll a, b;

    for(ll i=0; i<z; i++){
        a = pw[i];
        for(ll j=0; j<z; j++){
            b = pw[j];
            if(a >= b && a - b == x){
                cout<<i<<" "<<j;
                return;
            }
            if(a <= x && a + b == x){
                cout<<i<<" "<<-j;
                return;
            }
        }
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

