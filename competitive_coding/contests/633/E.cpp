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


const int N = 2e5+5;
const int sz = 201;
/*
int bit[N][sz];
void update(int i, int upd, int f, int n){
    for(; i<=n; i += i&(-i)) bit[i][f] += upd;
}

int get(int i, int f){
    int s = 0ll;
    for(; i>0; i -= i&(-i)) s += bit[i][f];
    return s;
}


void solve(){
    int n, x;
    cin>>n;
    int a[n+1];
    rep(i, 1, n) cin>>a[i];

    /// reset
    rep(i, 0, n){
        fr(j, sz) bit[i][j] = 0;
    }

    vector<int> pos[sz];
    rep(i, 1, n){
        update(i, 1, a[i], n);
        pos[a[i]].push_back(i);
    }

    int st, en, mid;

    int ans = 1;
    rep(i, 1, n/2){
        rep(j, 1, sz-1){
            x = pos[j].size();
            if(x - i >= 0){
                st = pos[j][i-1];
                en = pos[j][x - i];
                if(st < en){
                    st++;
                    en--;
                    mid = 0;
                    rep(k, 1, sz-1){
                        mid = max(mid, get(en, k) - get(st-1, k));
                    }
                    ans = max(ans, 2*i + mid);
                } else if(st == en){
                    ans = max(ans, 2*i - 1);
                }
            }
        }
    }

    cout<<ans<<endl;

}
*/

void solve_dp(){
    int n, x;
    cin>>n;
    int a[n+1];
    rep(i, 1, n) cin>>a[i];
    int pref[n+1][sz];
    fr(j, sz) pref[0][j] = 0;

    vector<int> pos[sz];
    rep(i, 1, n){
        fr(j, sz) pref[i][j] = pref[i-1][j];
        pref[i][a[i]]++;
        pos[a[i]].push_back(i);
    }

    int ans = 1;
    int st, en, mid;
    rep(i, 1, n/2){
        rep(j, 1, sz-1){
            x = pos[j].size();
            if(x - i >= 0){
                st = pos[j][i-1];
                en = pos[j][x - i];
                if(st < en){
                    mid = 0;
                    rep(k, 1, sz-1) mid = max(mid, pref[en-1][k] - pref[st][k]);
                    ans = max(ans, 2*i + mid);
                }
            }
        }
    }

    cout<<ans<<endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        solve_dp();
    }

    return 0;
}

