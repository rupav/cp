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

map<char, char> nxt;

vector<char> v = {'R', 'G', 'B'};
char curr;

int main(){

    int q;
    cin>>q;
    int n, k;
    string s;
    nxt['R'] = 'G';
    nxt['G'] = 'B';
    nxt['B'] = 'R';



    while(q--){
        cin>>n>>k;
        cin>>s;

        map<char, vector<int>> dp;
        for(auto it: v){
            dp[it].resize(n-k+1);
            rep(itt, 0, n-k) dp[it].push_back(0);
        }

        fr(i, 1){
            for(auto it: v){
                int changes = 0;
                curr = it;
                for(int j=0; j<k; j++){
                    if(s[j] != curr) changes++;
                    curr = nxt[curr];
                }
                dp[it][0] = changes;
            }
        }

        rep(i, 1, n-k){
            for(auto it: v){
                dp[it][i] = dp[nxt[nxt[it]]][i-1] - (s[i-1] != nxt[nxt[it]]) + (s[i+k-1] != it);
            }
        }

        ll ans = dp['R'][0];
        for(auto it: v){
            rep(itt, 0, n-k){
                ans = min(ans, 1ll*dp[it][itt]);
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}


