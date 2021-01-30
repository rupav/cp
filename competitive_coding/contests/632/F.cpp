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

vector<int> p;
const int N = 5e5 + 5;
vector<bool> is_prime(N+1, true);
map<int, int> mp;

void seive(int n){
    is_prime[0] = is_prime[1] = false;
    mp[1] = 1;

    for(int i=2; i*i<=n; i++){
        if(is_prime[i]){
            mp[i] = 1;
            for(int j=2*i; j<=n; j+=i){
                is_prime[j] = false;
                mp[j] = i;
            }
        }
    }
}

void solve(){
    int n;
    cin>>n;
    seive(n);

    set<int> s;
    vector<int> v;
    rep(i, 1, n) {
        if(is_prime[i]) {
                mp[i] = 1;
                p.push_back(i);
        }
    }

    cout<<p.size()<<endl;



}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    //  cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

