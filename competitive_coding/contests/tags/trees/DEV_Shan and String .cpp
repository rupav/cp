#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

const int N = 1e5+1;
int bit[N];
int n, m, x, y;

void update(int i, int upd){
    for(; i<=n; i+=i&(-i)) bit[i] += upd;
}

int query(int i){
    int sum = 0;
    for(; i>0; i-=i&(-i)) sum += bit[i];
    return sum;
}

int main(){
    cin>>n>>m;
    string s;
    cin>>s;
    int i = 1;
    for(auto it: s) update(i++, it-'0');
    int c;
    while(m--){
        cin>>c;
        if(c == 1){
            cin>>x;
            int upd = (query(x) - query(x-1)) ? -1 : 1;
            update(x, upd);
        } else {
            cin>>x>>y;
            cout<<query(y) - query(x-1)<<endl;
        }
    }
}
