#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;

ll gcdll(ll a, ll b){
    if(!b) return a;
    return gcdll(b, a%b);
}

int gcd(int a, int b){
    if(!b) return a;
    return  gcd(b, a%b);
}

void seive(int n){
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;

    for(int i=2; i*i<=n; i++){
        if(is_prime[i]){
            for(int j=i*i; j<=n; j+=i){
                is_prime[j] = false;
            }
        }
    }
}

vector<int> constructZFunc(string s){
    int n = s.size();
    vector<int> z(n);
    int l, r;
    l = r = 0;
    z[0] = 0;
    rep(i, 1, n-1){
        z[i] = 0;
        if(i<=r){
            z[i] = min(r-i+1, z[i-l]);  /// initialization, req. for linear time approach.
        }
        while(i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if(i+z[i]-1 > r){
            r = i+z[i]-1;
            l = i;
        }
    }
    return z;
}

const int MAXN = 10000;
int t[4*MAXN];
/// update - O(lgn), query - O(lgn), build - O(n)
/// Max tree
void buildSegTree(int arr[], int tl, int tr, int node){
    if(tl == tr){
        t[node] = arr[tl];
        return;
    } else {
        int tm = (tl + tr) / 2;
        buildSegTree(arr, tl, tm, 2*node);
        buildSegTree(arr, tm+1, tr, 2*node+1);
        t[node] = max(t[2*node], t[2*node+1]);
    }
}

int getMax(int node, int tl, int tr, int l, int r){
    if(l > r) return INT_MIN;
    if(tl == l && tr == r){
        return t[node];
    }
    int tm = (tl + tr)/2;
    return max(getMax(2*node, tl, tm, l, min(tm, r)), getMax(2*node+1, tm+1, tr, max(l, tm+1), r));
}

void update(int node, int tl, int tr, int pos, int val){
    if(tl == tr){
        t[node] = val;
    } else {
        int tm = (tl + tr)/2;
        if( pos <= tm ){
            update(2*node, tl, tm, pos, val);
        } else {
            update(2*node+1, tm+1, tr, pos, val);
        }
        t[node] = max(t[2*node], t[2*node + 1]);
    }
}

bool check(int x, int y, int n){
    if(x >= n || x<0) return false;
    if(y >= n || y<0) return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int arr[n];
    fr(i, n) cin>>arr[i];
    memset(t, 0, sizeof(t));
    buildSegTree(arr, 0, n-1, 1);
    int x, y;
    int q;
    while(true){
        cin>>q>>x>>y;
        if(q == -1) return 0;
        if(q == 0){
            /// update xth index with val 'y';
            if(!check(x, 0, n)) return 0;
            update(1, 0, n-1, x, y);
        } else if (q == 1){
            if(!check(x, y, n)) return 0;
            cout<<getMax(1, 0, n-1, x, y)<<endl;
        } else {
            return 0;
        }
    }
    return 0;
}
