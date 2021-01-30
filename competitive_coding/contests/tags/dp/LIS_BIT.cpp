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

/// Using BIT - similar to DP solution, but finding max dp[j] s.t a[j] < a[i]
/// drawback: indexing is done on elements, so first need to compress points
/// advantage: O(nlogn) solution

const int N = 1e5 + 5;
int bit[N] = {0}; /// storing max of the prefix
void modify(int i, int val){
    for(; i < N; i += i&(-i)) bit[i] = max(bit[i], val);
}

/// max of the prefix
int get(int i){
    int mx = 0;
    for(; i > 0; i -= i&(-i)) mx = max(mx, bit[i]);
    return mx;
}

int lis(int *a, int n, bool strict){
    /// all a[i] are assumed to be greater than equal to 1
    int dp[n];
    int mx;
    fr(i, n){
        if(strict){
            mx = get(a[i] - 1);
        } else {
            mx = get(a[i]);
        }
        dp[i] = mx + 1;
        modify(a[i], dp[i]);
    }

    return get(*max_element(a, a+n));
}

void solve(){
    int n;
    cin>>n;
    int a[n];
    fr(i, n) cin>>a[i];
    cout<<lis(a, n, true);
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

