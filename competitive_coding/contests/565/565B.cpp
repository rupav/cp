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

    int t;
    cin>>t;
    int n;
    ll x;
    while(t--){
        cin>>n;
        int count[3] = {0};
        fr(i, n){
            cin>>x;
            if(x%3 == 0) count[0]++;
            else if(x%3 == 1) count[1]++;
            else count[2]++;
        }
        count[0] += min(count[1], count[2]);
        int temp = min(count[1], count[2]);
        count[1] -= temp;
        count[2] -= temp;
        count[0] += (count[1] + count[2])/3;
        cout<<count[0]<<endl;
    }

    return 0;
}

