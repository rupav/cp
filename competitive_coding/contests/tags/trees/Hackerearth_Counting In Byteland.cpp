#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define op(i) i&(-i)

ll bit[102][102][102];
int n, x1, y1, z1, x2, y2, z2;
ll val;

void update(int x, int y, int z, ll upd){
    for(int i=x; i<=n; i += op(i)){
        for(int j=y; j<=n; j += op(j)){
            for(int k=z; k<=n; k += op(k)){
                bit[i][j][k] += upd;
            }
        }
    }
}

ll query(int x, int y, int z){
    ll sum = 0;
    for(int i=x; i>0; i -= op(i)){
        for(int j=y; j>0; j -= op(j)){
            for(int k=z; k>0; k -= op(k)){
                sum += bit[i][j][k];
            }
        }
    }
    return sum;
}

int main(){
    int q, c;
    cin>>n>>q;
    n++;
    ll tot = 0ll;
    while(q--){
        cin>>c;
        if(c == 1){
            cin>>x1>>y1>>z1>>val;
            x1++, y1++, z1++;
            tot += val;
            update(x1, y1, z1, val);
        } else {
            cin>>x1>>y1>>z1>>x2>>y2>>z2;
            x1++, y1++, z1++, x2++, y2++, z2++;
            ll s = query(x1-1, y1-1, z1-1);
            ll s1 = query(x1-1, y2, z2);
            ll s2 = query(x2, y1-1, z2);
            ll s3 = query(x2, y2, z1-1);
            ll s4 = query(x1-1, y1-1, z2);
            ll s5 = query(x1-1, y2, z1-1);
            ll s6 = query(x2, y1-1, z1-1);
            ll sum = query(x2, y2, z2);
            ll temp = (s6+s5+s4) - (s3+s2+s1) + (s);
            // cout<<tot<<" "<<sum<<" "<<temp<<endl;
            sum += temp;
            cout<<tot - sum<<endl;
        }
    }
    return 0;
}
