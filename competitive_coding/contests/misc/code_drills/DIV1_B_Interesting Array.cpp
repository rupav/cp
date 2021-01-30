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
int bit[N][30];

void update(int i, int upd, int index){
    for(; i < N; i += i&(-i)) bit[i][index] += upd;
}

int get(int i, int index){
    if(i == 0) return 0;
    int sm = 0;
    for(; i > 0; i -= i&(-i)) sm += bit[i][index];
    return sm;
}

struct Q{
    int l, r, q;
    void in(){
        cin>>l>>r>>q;
    }
    bool operator<(const Q& a){
        return l < a.l;
    }
};

void solve(){
    int n, m;
    cin>>n>>m;
    vector<Q> queries(m);
    fr(i, m){
        queries[i].in();
    }
    sort(queries.begin(), queries.end());

    for(int i=0; i < 30; i++){
        int prev = 0;   /// already filled with 1's!
        for(auto it: queries){
            int st = max(prev + 1, it.l);
            int en = it.r;
            if(st > en) continue;
            if(it.q & (1 << i)){
                /// range update
                update(st, 1, i);
                update(en + 1, -1, i);
                prev = it.r;
            }
        }
    }

    bool f = true;

    vector<vector<int>> pref(30, vector<int>(N, 0));
    for(int i = 0; i < 30; i++){
        rep(j, 1, N - 1){
            pref[i][j] = get(j, i) + pref[i][j - 1];
        }
    }

    for(auto it: queries){
        for(int i = 0; i < 30; i++){
            /// check if bit is not set for query, then atleast 1 '0' must exists in the range l to r
            if( (it.q & (1<<i)) == 0){
                f = f & (pref[i][it.r] - pref[i][it.l - 1]  < it.r - it.l + 1);
            }
        }
    }

    if(!f) {
        cout<<"NO";
        return;
    }

    cout<<"YES"<<endl;
    rep(i, 1, n){
        int z = 0;
        fr(j, 30){
            if(get(i, j)){
                z |= (1 << j);
            }
        }
        cout<<z<<" ";
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

