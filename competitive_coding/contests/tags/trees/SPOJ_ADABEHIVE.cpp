#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

const int LIM = 2001;
ll bit[LIM][LIM];
int n, m, q, x, y, x2, y2;
ll val;

void update(int i_, int j_, ll upd){
    for(int i = i_; i<=n; i+=i&(-i)){
        for(int j = j_; j<=m; j+=j&(-j))
            bit[i][j] += upd;
    }
}

ll query(int i_, int j_){
    ll sum = 0;
    for(int i = i_; i>0; i-=i&(-i)){
        for(int j = j_; j>0; j-=j&(-j))
            sum += bit[i][j];
    }
    return sum;
}

int main(){
    cin>>n>>m>>q;
    rep(i, 1, n){
        rep(j, 1, m){
            cin>>val;
            update(i, j, val);
        }
    }

    int c;
    while(q--){
        cin>>c;
        if(c == 1){
            // update
            cin>>x>>y>>val;
            update(x, y, val);
        } else {
            cin>>x>>y>>x2>>y2;
            ll sum1 = query(x-1, y-1);
            ll sum2 = query(x2, y-1) - sum1;
            ll sum3 = query(x-1, y2) - sum1;
            ll sum = query(x2, y2);
            sum -= (sum1 + sum2 + sum3);
            cout<<sum<<endl;
        }
    }

}
