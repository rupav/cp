
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

    int n;
    cin>>n;
    vector<int> a(2*n);
    ll sum = 0;
    fr(i, 2*n){
        cin>>a[i];
        sum += 1ll*a[i];
    }

    ll temp = 0;
    sort(a.begin(), a.end());
    fr(i, n){
        temp += 1ll*a[i];
    }

    if(2*temp != sum){
        fr(i, 2*n) cout<<a[i]<<" ";
    } else {
        cout<<-1;
    }


    return 0;
}
