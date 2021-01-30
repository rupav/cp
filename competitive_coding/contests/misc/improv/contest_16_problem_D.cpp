#include<bits/stdc++.h>
#include <string>
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

void solve(){
    int n;
    cin>>n;
    int days = 1;
    string s;
    int prev = -1;
    int val = 0;
    int streak = 1;
    fr(i, n){
        std::getline(std::cin >> std::ws, s);
        if(s[1] == '1' && s[2] == '2'){
            s[1] = s[2] = '0';
        }
        val = 60*(10*(int)(s[1]-'0') + (int)(s[2]-'0')) + 10*(int)(s[4]-'0') + (int)(s[5]-'0');
        val += (s[7] == 'p')*60*12;

        if(val < prev) {
            days++;
            streak = 1;
        }
        else if (val == prev){
            streak++;
            if(streak > 10) {
                streak = 1;
                days++;
            }
        } else streak = 1;
        prev = val;
    }
    cout<<days;
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

