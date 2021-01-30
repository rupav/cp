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


/// https://www.codechef.com/LTIME84A/problems/ABSNX
/// MIN MAX


/// IMBALANCE ARRAY Preprocessing
const int N = 3e5 + 5;
int a[N], L[N], R[N];
typedef long long ll;

void preprocess(int n){
    stack<int> s;
    for(int i=1; i<=n; i++) L[i] = 0;
    for(int i=1; i<=n; i++) R[i] = n+1;

    for(int i=1; i<=n; i++){
        while(s.size() && a[s.top()] <= a[i]) s.pop();
        if(s.size()) L[i] = s.top();  // rightmost index, s.top() s.t. a[s.top()] > a[i]
        s.push(i);
    }

    while(s.size()) s.pop();

    for(int i=n; i>=1; i--){
        while(s.size() && a[s.top()] >= a[i]) s.pop();
        if(s.size()) R[i] = s.top();  // leftmost index, s.top() s.t. a[s.top()] < a[i]
        s.push(i);
    }
}


/// 2D - bit
ll bit[N][2];
void update(int i, int upd, int f){
    for(; i<N; i += i&(-i)) bit[i][f] += upd;
}

ll get(int i, int f){
    ll s = 0ll;
    for(; i>0; i -= i&(-i)) s += bit[i][f];
    return s;
}




ll solve(ll n){
    preprocess(n);

    ll ans = 0ll;
    /*
    rep(i, 1, n) cout<<L[i]<<" ";
    cout<<endl;
    rep(i, 1, n) cout<<R[i]<<" ";
    cout<<endl;
    */

    rep(i, 0, N - 1) bit[i][0] = bit[i][1] = 0ll;

    rep(i, 1, n) {
        L[i] += 1ll;
        R[i] -= 1ll;
    }


    /// max. ending at a[i], find all min to its left
    vector<pll> v(n + 1);
    rep(i, 1, n){
        v[i] = {L[i], i};
    }

    sort(v.begin() + 1, v.end());

    ll previ = 0;    /// prev. index inserted
    ll prevd = 0;   /// prev. deleted index

    for(auto it: v){
        ll lt = it.first;
        ll rt = it.second;

        previ = max(previ, lt);
        while(previ <= rt - 1ll){
            if(previ) {
                update(previ, 1ll, 0);
                update(R[previ], 1ll, 1);
            }
            previ++;
        }

        while(prevd <= lt - 1ll){
            if(prevd){
                update(R[prevd], -1ll, 1);
            }
            prevd++;
        }

        ll sub = get(n, 0) - get(rt - 1ll, 0);  /// count of those right segments which had been inserted, has gauranteed 'R' greater than rt, so can be safely removed
        ll add = get(n, 1) - get(rt - 1ll, 1);  /// those min. indices for which their range lies right to i

        ans += (add - sub);
    }

    // watch(ans);
    return ans;
}

ll eq(ll n){
    ll ans = 0ll;

    int i = 1;
    while(i <= n){
        int j = i + 1;
        while(j <= n && a[j] == a[i]) j++;
        ll len = (ll) (j - i);
        ans += (len * (len - 1ll))/2ll;
        i = j;
    }
    return ans;
}

void solve_(){
    ll n;
    cin>>n;

    rep(i, 1, n) cin>>a[i];
    ll ans = solve(n);
    ans -= eq(n);
    rep(i, 1, n) a[i] = -a[i];
    ans += solve(n);

    cout<<ans + n<<endl;
}

/*
1
6
3 4 3 5 8 6
*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        solve_();
    }

    return 0;
}

