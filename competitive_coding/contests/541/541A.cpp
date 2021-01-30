#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;


int main(){
    ll w1, h1, w2, h2;
    cin>>w1>>h1>>w2>>h2;
    ll res = 0;
    res = 2*(h1+1) + 2*(h2+1) + 2*w1;
    cout<<res;
    return 0;
}
