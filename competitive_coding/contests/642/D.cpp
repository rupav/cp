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

bool compare(pii a, pii b){
    if(a.len < b.len) return true;
    if(a.len == b.len) return a.st > b.st;
    return false;
}

void solve(){
    int n;
    cin>>n;
    priority_queue<pii, vector<pii>, decltype(compare)*> pq(compare);
    // set<pii, compare> s;
    int res[n+1];
    pq.push(make_pair(n, 1));
    int i = 1;
    int nl;
    int pos;
    while(pq.size()){
        pii z = pq.top();
        // watch(z.len);
        // watch(z.st);
        if(z.len <= 0) break;
        pq.pop();

        if(z.len&1){
            pos = z.st + z.len/2;
            nl = pos - z.st;
        } else {
            pos = z.st + (z.len/2) - 1;
            nl = pos - z.st;
        }

        res[pos] = i++;
        pq.push(make_pair(nl, z.st));
        pq.push(make_pair(z.len - nl - 1, pos + 1));
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

