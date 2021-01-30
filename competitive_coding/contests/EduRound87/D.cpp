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

const int N = 1e6 + 5;
int bit[N] = {0};
void update(int i, int upd){
    for(; i < N; i += i&(-i)) bit[i] += upd;
}

int get(int i){
    int sm = 0;
    for(; i > 0; i -= i&(-i)) sm += bit[i];
    return sm;
}

void solve(){
    int n, m, k;
    cin>>n>>m;

    int x;
    fr(i, n){
        cin>>x;
        update(x, 1);
    }

    while(m--){
        cin>>x;
        if(x > 0){
            update(x, 1);
        } else {
            k = abs(x);
            int lb(1), rb(n), mb, ind;
            while(lb <= rb){
                mb = (lb + rb)/2;
                x = get(mb);

                if(x < k){
                    lb = mb + 1;
                } else {
                    ind = mb;
                    rb = mb - 1;
                }
            }
            update(ind, -1);
        }
    }

    for(int i=1; i <= n; i++){
        if(bit[i]){
            cout<<i;
            return;
        }
    }
    cout<<0;

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

