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
const int mod = 998244353;

const int N = 2e5 + 5;
int a[N], L[N], R[N];

void preprocess(int n){
    stack<int> s;
    for(int i=1; i<=n; i++) L[i] = 0;
    for(int i=1; i<=n; i++) R[i] = n+1;

    for(int i=1; i<=n; i++){
        while(s.size() && a[s.top()] > a[i]) s.pop();
        if(s.size()) L[i] = s.top();
        s.push(i);
    }

    while(s.size()) s.pop();

    for(int i=n; i>=1; i--){
        while(s.size() && a[s.top()] >= a[i]) s.pop();
        if(s.size()) R[i] = s.top();
        s.push(i);
    }
}


void solve(){
    int n, m;
    cin>>n>>m;
    vector<int> b(m + 1);
    rep(i, 1, n) cin>>a[i];
    rep(i, 1, m) cin>>b[i];

    preprocess(n);
    rep(i, 1, n) L[i]++, R[i]--;    /// range

    int en = m;
    vector<int> intervals;
    bool f = true;
    repn(i, n, 1){
        if(a[i] < b[en]) en--;
        if(en < 1){
            f = false;
            break;
        }
        if(a[i] == b[en]) intervals.push_back(i);
    }

    if(!f){
        cout<<0;
        return;
    }

    int cnt = 1;
    for(auto it: intervals){
        mul_self(cnt, L[it]);
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

