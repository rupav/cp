#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e3;
int a[N];
vector<ll> blocks(N);

void update(int pos, int upd, int s){
    int c_pos = pos/s;
    blocks[c_pos] += 1ll*upd;
    blocks[c_pos] -= 1ll*a[pos];
    a[pos] = upd;
}

ll get(int l, int r, int s){
    int cl(l/s), cr(r/s);
    ll sum = 0ll;
    if(cl == cr) {
        for(int i=l; i<=r; i++) sum += 1ll*a[i];
        return sum;
    }

    for(int st = l, en = (cl+1)*s - 1; st <= en; st++){
        sum += 1ll*a[st];
    }
    for(int ci = cl; ci < cr; ci++){
        sum += blocks[ci];
    }
    for(int st = cr*s; st<=r; st++){
        sum += 1ll*a[st];
    }

    return sum;
}

int main(){
    cout<<"enter values!"<<endl;

    int n, q, c;
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    cin>>q;

    int s = (int)sqrt(n + .0) + 1;

    cout<<s<<endl;

    blocks.resize(s);
    blocks.assign(s, 0ll);
    for(int i=0; i<n; i++){
        blocks[i/s] += 1ll*a[i];
    }

    while(q--){
        cin>>c;
        if(c == 1){
            /// update a[i] to upd
            int ind, upd;
            cin>>ind>>upd;
            update(ind, upd, s);
        } else {
            /// get sum from l to r     /// 0-based indexing
            int l, r;
            cin>>l>>r;
            cout<<get(l, r, s);
        }
    }

    return 0;
}

