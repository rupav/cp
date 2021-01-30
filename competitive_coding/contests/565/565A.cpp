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
    ll n;
    ll count;
    while(t--){
        cin>>n;
        count = 0;
        while(n != 1){
            if(n%2 == 0){
                n /= 2;
                count += 1ll;
            } else if (n%3 == 0){
                n /= 3;
                count += 2ll;
            } else if (n%5 == 0){
                n /= 5;
                count += 3ll;
            } else {
                cout<<-1<<endl;
                break;
            }
        }
        if(n == 1){
            cout<<count<<endl;
        }
    }

    return 0;
}

