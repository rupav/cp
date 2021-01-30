#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
#define int ll
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

void solve(){
    int n;
    cin>>n;
    int a[n + 1];
    rep(i, 1, n) cin>>a[i];

    if(n == 1) {
        cout<<-1;
        return;
    }

    sort(a + 1, a + n + 1);

    int d;
    if(n == 2){
        d = a[2] - a[1];
        if(!d) {
            cout<<1<<endl<<a[1];
            return;
        }
        if((a[1]&1) != (a[2]&1)){
            cout<<2<<endl;
            cout<<a[1] - d<<" "<<a[2] + d;
            return;
        } else {
            cout<<3<<endl;
            cout<<a[1] - d<<" "<<(a[1] + d/2)<<" "<<a[2] + d;
            return;
        }
    }


    d = a[2] - a[1];
    int place = 0;
    bool f = true;

    rep(i, 3, n){
        if(a[i] - a[i-1] == d) continue;
        if(!place && a[i] - a[i-1] == 2ll*d){
            place = i - 1;
        } else {
            f = false;
            break;
        }
    }

    if(f){
        if(place) cout<<1<<endl<<a[place] + d;
        else {
            if(!d) cout<<1<<endl<<a[1];
            else cout<<2<<endl<<a[1] - d<<" "<<a[n] + d;
        }
        return;
    }

    f = true;
    d = a[n] - a[n - 1];
    place = 0;

    repn(i, n-2, 1){
        if(a[i + 1] - a[i] == d) continue;
        if(!place && a[i + 1] - a[i] == 2ll*d) place = i + 1;
        else {
            f = false;
            break;
        }
    }

    if(f){
        cout<<1<<endl<<a[place] - d;
        return;
    }

    cout<<0;
    return;

}

signed main(){
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

