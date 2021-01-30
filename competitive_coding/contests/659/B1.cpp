#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a) * (a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;

ll nxt(ll x, ll k, bool &dec){
    if(x == 0){
        dec = false;
        return 1;
    }
    if(x == k){
        dec = true;
        return k - 1;
    }

    if(dec){
        return x - 1;
    }
    return x + 1;
}

bool solve(){
    ll n, k, l;
    cin>>n>>k>>l;
    ll d[n + 1];
    bool f = true;
    rep(i, 1, n) {
        cin>>d[i];
        if(d[i] > l){
            f = false;
        }
        d[i] = min(l - d[i], k);    /// how much depth we can bear
    }
    if(!f) return f;

    /// p = [0,1,2,…,k−2,k−1,k,k−1,k−2,…,2,1] at all time, depth increases
    /// simulate the process

    /// d[i] is >= 0 now
    /// d[i] == k, these are stops, where i can rest indefinitely



    f = true;
    int j = 1;
    while(j <= n && d[j] == k) j++;

    if(j > n) return true;
    /// now d[j] != k

    int i = j;
    /// int st = d[j];  /// starting time in decreasing order!
    bool dec = true;
    int st;
    while(i <= n){
        dec = true;
        st = d[i];
        j = i + 1;
        while(j <= n && d[j] != k){
            /// check
            st = nxt(st, k, dec);
            if(st > d[j] && dec) st = d[j];
            if(st > d[j]) return false;
            j++;
        }
        /// d[j] = k
        while(j <= n && d[j] == k) j++;
        i = j;
    }

    return true;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        cout<<(solve() ? "Yes": "No")<<endl;
    }

    return 0;
}

