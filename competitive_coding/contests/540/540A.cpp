#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef unsigned long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;


int main(){
    ll n;
    int q, a, b;
    cin>>q;
    ll sum=0;
    while(q--){
        sum = 0;
        cin>>n>>a>>b;
        if(2*a<b){
            sum = 1ll*a*n;
        } else {
            sum = 1ll*(b)*(n/2);
            sum += (n&1)*a;
        }
        cout<<sum<<endl;
    }
    return 0;
}
