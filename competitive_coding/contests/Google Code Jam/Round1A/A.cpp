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

void seive(int n){
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;

    for(int i=2; i*i<=n; i++){
        if(is_prime[i]){
            for(int j=i*i; j<=n; j+=i){
                is_prime[j] = false;
            }
        }
    }
}

vector<int> constructZFunc(string s){
    int n = s.size();
    vector<int> z(n);
    int l, r;
    l = r = 0;
    z[0] = 0;
    rep(i, 1, n-1){
        z[i] = 0;
        if(i<=r){
            z[i] = min(r-i+1, z[i-l]);  /// initialization, req. for linear time approach.
        }
        while(i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if(i+z[i]-1 > r){
            r = i+z[i]-1;
            l = i;
        }
    }
    return z;
}


int calc(int n){
    if(n == 0) return -1;
    int i = 0;
    int val = 0;
    while(n){
        if(n&1) val = i;
        n /= 2;
        i++;
    }
    return val;
}

void solve(){
    int n, x;
    cin>>n;
    int sum = 0ll;
    if(n < 31){
        rep(i, 1, n){
            cout<<i<<" "<<1<<endl;
        }
    } else {
        n -= 30;
        int msb = calc(n);
        /// fill msb + 1 rows
        bool rt = true;
        int cnt = msb + 1 + 30;
        rep(i, 1, msb + 1){
            x = (1<<(i-1));
            if(!(x&n)){
                if(rt) cout<<i<<" "<<1<<endl;
                else cout<<i<<" "<<i<<endl;
                cnt--;
            } else {
                if(rt) {
                    rep(j, 1, i) cout<<i<<" "<<j<<endl;
                } else {
                    repn(j, i, 1) cout<<i<<" "<<j<<endl;
                }
                rt = !rt;
            }
        }
        if(rt){
            rep(i, msb + 2, cnt){
                cout<<i<<" "<<1<<endl;
            }
        } else {
            rep(i, msb + 2, cnt){
                cout<<i<<" "<<i<<endl;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    rep(i, 1, t){
        cout<<"Case #"<<i<<": "<<endl;
        solve();
    }

    return 0;
}

