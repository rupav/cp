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

ll _cost(int cost, int i, int j, int n){
    return (1ll*cost)*(1ll*(n - (j - i + 1) + 1));
}

ll MaximizeCost(vector<ll> arr, int n){
    pll dp[n][n];
    fr(i, n){
        dp[i][i].first = (n+1)*(arr[i]);
        dp[i][i].second = arr[i];
    }

    for(int i=n-2; i>=0; i--){
        rep(j, i+1, n-1){
            dp[i][j].first = max(dp[i+1][j].first + _cost(arr[i], i, j, n) + max(arr[i], dp[i+1][j].second), \
                                 dp[i][j-1].first + _cost(arr[j], i, j, n) + max(arr[j], dp[i][j-1].second));
            dp[i][j].second = max(dp[i+1][j].second, dp[i][j-1].second);
        }
    }

    return dp[0][n-1].first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll> v(n);
        fr(i, n){
            cin>>v[i];
        }
        cout<<MaximizeCost(v, n)<<endl;
    }

    return 0;
}

