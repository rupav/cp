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

ll gcdll(ll a, ll b){
    if(!b) return a;
    return gcdll(b, a%b);
}

int gcd(int a, int b){
    if(!b) return a;
    return  gcd(b, a%b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x, y, z;
    cin>>x>>y>>z;
    if(z && abs(x-y) <= z){
        cout<<"?";
    } else {
        if(z == 0 && x==y){
            cout<<0;
        } else {
            if(x > y){
                cout<<"+";
            } else {
                cout<<"-";
            }
        }
    }

    return 0;
}

