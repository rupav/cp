#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;

const int N = 2e5 + 5;
ll bit[N] = {0};

void update(int i, ll upd){
    for(; i < N; i += i&(-i)) bit[i] += upd;
}

ll get(int i){
    ll sm = 0;
    for(; i > 0; i -= i&(-i)) sm += bit[i];
    return sm;
}


void solve(){
    ll n, q, c, l, r, upd;
    cin>>n>>q;
    ll a[n];
    fr(i, n){
        cin>>a[i];
    }

    fr(i, q){
        cin>>c;
        c--;
        if(!c){
            cin>>l>>r>>upd;
            update(l, upd);
            update(r + 1, -upd);
        } else {
        	int k;
            cin>>k;
            cout<<a[k - 1] + get(k)<<endl;
        }
    }

}

int main(){
    solve();
    return 0;
}

