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

int c(char i){
    return (int)(i - 'a');
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    string s, t;
    cin>>s;
    cin>>t;

    vector<int> p(n);
    vector<int> vis(n, false);

    fr(i, n){
        p[i] = c(s[i]) - c(t[i]);
        if(p[i] == 0) vis[i] = true;  /// dont consider for swap
    }

    int x = accumulate(p.begin(), p.end(), 0);
    if(x&1){
        cout<<-1;
        return 0;
    }

    /// do same pair wise swap, until left
    vector<pii> ans;
    int i = 0;
    while(i<n){
        if(p[i] == 1){
            /// find next 1
            rep(j, i+1, n-1){
                if(p[j] == 1){
                    ans.push_back(make_pair(i, j));
                    vis[i] = vis[j] = true;
                    i = j;  /// searched till here!
                    break;
                }
            }
        }
        i++;
    }

    i = 0;
    while(i<n){
        if(p[i] == -1){
            /// find next 1
            rep(j, i+1, n-1){
                if(p[j] == -1){
                    ans.push_back(make_pair(i, j));
                    vis[i] = vis[j] = true;
                    i = j;  /// searched till here!
                    break;
                }
            }
        }
        i++;
    }

    /// only a pair of 1 and -1 left, add them to ans

    i = 0;
    while(i<n){
        if(!vis[i]){
            /// swap this now
            ans.push_back(make_pair(i, i));
            rep(j, i+1, n-1){
                if(!vis[j]){
                    ans.push_back(make_pair(i, j));
                    vis[i] = vis[j] = true;
                    break;
                }
            }
        }
        i++;
    }

    cout<<ans.size()<<endl;
    for(auto it: ans){
        cout<<it.first+1<<" "<<it.second+1<<endl;
    }

    return 0;
}

