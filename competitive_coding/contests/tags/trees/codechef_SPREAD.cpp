#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

const int N = 1e6 + 5;
ll n, m, c;
ll bit[2][N];

void update(int idx, int i, ll upd){
    for(; i<=n; i+=i&(-i)) bit[idx][i] += upd;
}

ll pref(int idx, int i){
    ll sum =  0;
    for(; i>0; i-=i&(-i)) sum+=bit[idx][i];
    return sum;
}

int main(){
    cin>>n>>m>>c;
    ll l, r, val;
    char x;
    while(m--){
        cin>>x;
        if(x == 'S'){
            cin>>l>>r>>val;
            update(0, l, val);
            update(0, r+1, -val);
        } else {
            cin>>l;
            cout<<pref(0, l) + c<<endl;
        }
    }
}
