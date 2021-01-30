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
    /// partially for first part
    ll n;
    cin>>n;
    vector<ll> b(n + 1), res(n + 1);
    bool f = true;
    bool pos = true;   /// all positive
    rep(i, 1, n) {
        cin>>b[i];
        pos = pos & (b[i] > 0);
    }

    sort(b.begin(), b.end());

    /// edge case
    if(n == 1){
        if(b[1] <= 0){
            cout<<"NO"<<endl;
        } else {
            cout<<"YES"<<endl;
            cout<<b[1]<<endl;
        }
        return;
    }


    /// res[1] should be 2nd least element, still positive
    int ind = -1;
    if(pos){
        res[1] = b[2];
        // b.erase(b.begin() + 2);
        ind = 2;
        res[2] = b[1];
    } else {
        res[2] = b[1];
        /// find 1st positive
        bool allneg = true;
        rep(i, 1, n){
            /// first positive
            if(b[i] > 0) {
                res[1] = b[i];
                // b.erase(b.begin() + i);
                ind = i;
                allneg = false;
                break;
            }
        }
        if(allneg) f = false;   /// not possible
    }

    // for(auto it: b) cout<<it<<endl;
    /// res_odd > res_odd - 1, res_odd + 1
    /// move in triplets to fill

    rep(i, 1, n) cout<<b[i]<<endl;
    int j = 2;
    int i = 3;
    while(i <= n){

        if(j == ind) j++;
        if(i + 1 <= n) res[i + 1] = b[j++];

        if(j == ind) j++;
        if(i <= n) res[i] = b[j++];
        i += 2;
    }

    /// now check finally
    ll sm = 0ll;

    if(!f){
        cout<<"NO"<<endl;
    } else {
        cout<<"YES"<<endl;
        rep(i, 1, n) cout<<res[i]<<" ";
        cout<<endl;
    }
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

