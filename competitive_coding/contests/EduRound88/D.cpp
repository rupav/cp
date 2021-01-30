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


const int N = 1e5 + 5;
/// IMBALANCE ARRAY Preprocessing
int a[N], L[N], R[N], mxl[N] = {0}, mxr[N] = {0}, pref[N] = {0}, suff[N] = {0};
int ans = 0;

int preprocess(int n){
    stack<int> s;
    for(int i=1; i<=n; i++) L[i] = 0;
    for(int i=1; i<=n; i++) R[i] = n+1;

    for(int i=1; i<=n; i++){
        int mx = 0;
        int sm = 0;
        int prev = 0;
        while(s.size() && a[s.top()] < a[i]){
            int z = s.top();
            prev = pref[i - 1] - pref[z];
            mx = max({mx, a[z] + mxl[z] + prev, a[z] + prev});
            s.pop();
        }
        mxl[i] = mx;
        if(s.size()) L[i] = s.top();  // rightmost index, s.top() s.t. a[s.top()] <= a[i]
        s.push(i);
        pref[i] = pref[i - 1] + a[i];
    }

    while(s.size()) s.pop();

    for(int i=n; i>=1; i--){
        int mx = 0;
        int sm = 0;
        int prev = 0;
        while(s.size() && a[s.top()] <= a[i]) {
            int z = s.top();
            prev = suff[i + 1] - suff[z];
            mx = max({mx, a[z] + mxr[z] + prev, a[z] + prev});
            s.pop();
        }
        mxr[i] = mx;
        if(s.size()) R[i] = s.top();  // leftmost index, s.top() s.t. a[s.top()] < a[i]
        s.push(i);
        suff[i] = suff[i + 1] + a[i];
    }

    int ans = 0;
    rep(i, 1, n){
        ans = max(ans, max(0, mxl[i]) + max(0, mxr[i]));
    }

    return ans;

}



void solve(){
    int n;
    cin>>n;
    rep(i, 1, n) cin>>a[i];

    cout<<preprocess(n)<<endl;
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

