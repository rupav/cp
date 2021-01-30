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

int main(){
    int n, m;
    cin>>n>>m;
    int mat[n][m];
    set<int> s[n];
    int x;
    int r=-1, c=-1;
    bool fl = false;
    fr(i, n){
        fr(j, m) {
            cin>>x;
            s[i].insert(x);
            mat[i][j] = x;
        }
        if(s[i].size() > 1){
            fl = true;
            r = i;
        }
    }

    int xor_ = 0;
    if(!fl){
        fr(i, n){
            xor_ = xor_^mat[i][0];
        }
        if(xor_ != 0){
            cout<<"TAK"<<endl;
            fr(i, n) cout<<1<<" ";
        } else {
            cout<<"NIE";
        }
    } else {
        /// except for row r, choose 1st element of each row
        fr(i, n){
            if(i!=r)
                xor_ = xor_^mat[i][0];
        }
        fr(j, m){
            if(xor_ != mat[r][j]){
                xor_ = xor_^mat[r][j];
                c = j;
                break;
            }
        }
        cout<<"TAK"<<endl;
        fr(i, n){
            if( i == r ){
                cout<<c+1<<" ";
            } else {
                cout<<1<<" ";
            }
        }
    }

    return 0;
}
