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

const int N = 10;

int bit[N + 1] = {0}; /// over freq of a el
void update(int i, int upd){
    if(!i) return;
    for(; i<=N; i += i&(-i)) bit[i] += upd;
}

int get(int i){
    ll s = 0;
    for(; i > 0; i -= i&(-i)) s += bit[i];
    return s;
}


void solve(){
    int n, x, y;
    map<int, int> mp;   /// cnt of el
    cin>>n;
    fr(i, n){
        cin>>x;
        mp[x]++;
    }
    int k, md;
    for(auto it: mp){
        y = it.second;
        k = y/4;
        md = y % 4;
        update(4, k);
        k = md/2;
        update(2, k);
    }

    int q;
    cin>>q;
    char ch;
    int z;
    bool f;
    fr(i, q){
        cin>>ch;
        cin>>x;
        if(ch == '+'){
            // increase freq
            y = mp[x];
            k = y/4;
            md = y % 4;
            update(4, -k);
            k = md/2;
            update(2, -k);

            mp[x]++;

            y = mp[x];
            k = y/4;
            md = y % 4;
            update(4, k);
            k = md/2;
            update(2, k);

        } else {
            y = mp[x];
            k = y/4;
            md = y % 4;
            update(4, -k);
            k = md/2;
            update(2, -k);

            mp[x]--;

            y = mp[x];
            k = y/4;
            md = y % 4;
            update(4, k);
            k = md/2;
            update(2, k);
        }
        /// now check if possible
        f = true;
        // watch(get(4) - get(2));
        // watch(get(2));
        z = get(5) - get(3);
        if(z < 1) f = false;
        z--;
        if(z < 1 && get(3) - get(1) < 2) f = false;
        cout<<(f ? "YES": "NO")<<endl;
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

