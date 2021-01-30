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


void solve(){
    int n;
    cin>>n;
    string s, t;
    cin>>s>>t;
    /// max 20 moves max required to solve it - simulate the process
    bool f = true;
    int mn = 21;
    fr(i, n){
        if(s[i] > t[i]) f = false;
        mn = min(mn, s[i] - 'a');
    }
    string z = s;   /// original

    if(!f) {
        cout<<"-1"<<endl;
        return;
    }

    /// inc min till t,
    int cnt = 0;

    while(mn < 20){
        /// change all mn elements to correspong min in t, which are greater
        int mnt = 20;
        fr(i, n){
            if(t[i] > s[i] && s[i] - 'a' == mn) mnt = min(mnt, t[i] - 'a');
        }

        fr(i, n) if(s[i] - 'a' == mn) s[i] = 'a' + mnt;
        if(mnt < 20) cnt++;

        /// find new mn
        mn = 20;
        fr(i, n){
            mn = min(mn, s[i] - 'a');
        }

    }

    cout<<cnt<<endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

