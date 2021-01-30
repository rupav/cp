#include<bits/stdc++.h>
#include <string>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
#define int32_t unsigned int
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;
ll INF = 1ll << 32;

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

    stack<ll> ms;
    ms.push(1);

    ll res = 0;

    while(n--){
        string s;
        cin>>s;
        if(s == "for"){
            int x;
            cin>>x;
            ms.push(min(INF, ms.top()*x));
        } else if (s == "end"){
            ms.pop();
        } else {
            if(ms.top() + res >= INF){
                cout<<"OVERFLOW!!!";
                return 0;
            }
            res += ms.top();
        }
    }

    cout<<res;

    return 0;
}

