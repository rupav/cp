#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<bool, bool> pbb;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;


bool solve(){
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin>>t;
    int n;
    cin>>n;
    while(t--){
        bool x, y;

        /// 5 pair queries
        bool res[n + 1];

        rep(i, 1, n/2){
            cout<<i<<endl;
            cin>>x;
            cout<<n - i + 1<<endl;
            cin>>y;

            res[i] = x;
            res[n - i + 1] = y;
        }

        /// final 10 queries
        int lim = (n > 10)? 10 : 5;
        rep(i, 1, lim){
            cout<<i<<endl;
            cin>>x;
            bool &l = res[i];
            bool &r = res[n - i + 1];
            if(l && r){
                /// 1, 1
                if(x);
                else l = r = 0;
            } else if (l && (!r)){
                /// 1, 0
                if(x);
                else l = 0, r = 1;
            } else if ((!l) && r){
                /// 0, 1
                if(x) l = 1, r = 0;
                else;
            } else if ((!l) && (!r)){
                /// 0, 0
                if(x) l = 1, r = 1;
                else;
            }
        }

        string s;
        rep(i, 1, n) s += char(res[i] + '0');

        cout<<s<<endl;
        char z;
        cin>>z;
        if(z != 'Y') break;
    }

    return 0;
}

