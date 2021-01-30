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
    string t, s;
    cin>>t>>s;
    int n = t.size();
    int m = s.size();
    int p[n];
    fr(i, n) cin>>p[i];
    bool del[n];

    /// binary search over the answer
    int st(0), en(n - 1), mid(0);
    int ans(0);
    while(st <= en){
        mid = (st + en)/2;
        /// deleting ordered elements till mid (not-inclusive), then check if answer s exists as a subsequences

        fr(i, n) del[i] = 0;
        fr(i, mid){
            del[p[i] - 1] = 1;
        }

        /// now check if s exists in t greedily, after removal of elements in given order
        bool f = false;
        int j(0);
        fr(i, n){
            if(j == m) break;
            if(!del[i] && t[i] == s[j]) j++;
        }

        if(j == m){
            /// s exists in t, so mid can be answer
            st = mid + 1;
            ans = max(ans, mid);
        } else {
            en = mid - 1;
        }

    }

    cout<<ans;

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

