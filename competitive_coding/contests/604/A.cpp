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

map<char, char> mp;

void solve(){
    string s;
    cin>>s;
    int n = s.size();

    fr(i, n-1){
        if(s[i]!='?' && s[i+1] == s[i]){
            cout<<-1;
            return;
        }
        if(s[i] != '?');
        else{
            if(s[i+1] == '?'){
                s[i] = (i!=0) ? mp[s[i-1]] : 'a';
            } else {
                if(i!=0){
                    if(mp[s[i-1]] != s[i+1]){
                        s[i] = mp[s[i-1]];
                    } else {
                        s[i] = mp[s[i+1]];
                    }
                } else {
                    s[i] = mp[s[i+1]];
                }
            }
        }
    }
    if(s[n-1] == '?') s[n-1] = (n!=1) ? mp[s[n-2]] : 'a';
    cout<<s;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    mp['a'] = 'b';
    mp['b'] = 'c';
    mp['c'] = 'a';
    cin>>t;
    while(t--){
        solve();
        cout<<endl;
    }

    return 0;
}

