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

#define len first
#define st second

void solve(){
    int n;
    cin>>n;
    priority_queue<pii> pq;

    int res[n+1];
    pq.push(make_pair(n, -1));  /// since 2nd element will give max, in case of 1st element equality
    int i = 1;
    int nl;
    int pos;
    while(pq.size()){
        pii z = pq.top();

        if(z.len <= 0) break;
        pq.pop();

        if(z.len&1){
            pos = abs(z.st) + z.len/2;
            nl = pos - abs(z.st);
        } else {
            pos = abs(z.st) + (z.len/2) - 1;
            nl = pos - abs(z.st);
        }

        res[pos] = i++;
        pq.push(make_pair(nl, -abs(z.st)));
        pq.push(make_pair(z.len - nl - 1, -(pos + 1)));
    }

    rep(i, 1, n) cout<<res[i]<<" ";
    cout<<endl;
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

