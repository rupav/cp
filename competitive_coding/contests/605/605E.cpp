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

vector<int> a(200005);
int dp[200005][2]; /// 0 left, 1 right

bool p_check(int i, int j, int n){
    if(j < 1 || j>n) return false;

    int x = a[i];
    int y = a[j];

    if(x&1){
        if(y%2 == 0) return true;
    } else {
        if(y&1) return true;
    }
    return false;
}

int recurse(int pos, int n){
    if(pos > n || pos < 1){
        return -1;
    }
    if(dp[pos][0] <= n || dp[pos][1] <= n){
        int temp = -1;
        if(dp[pos][0] != -1 && dp[pos][1] != -1) temp = min(dp[pos][0], dp[pos][1]);
        else if (dp[pos][0] == -1){
            temp = dp[pos][1];
        } else if(dp[pos][1] == -1){
            temp = dp[pos][0];
        }
        return temp;
    }

    if(dp[pos][0] == n+2 && dp[pos][1] == n+2){
        return -1;
    }

    /// dp[pos][0] = dp[pos][1] = n+2;

    if(dp[pos][1] != n+2){
        dp[pos][1] = n+2;
        if(!p_check(pos, pos+a[pos], n)){
            int temp = recurse(pos+a[pos], n);
            if(temp == -1){
                dp[pos][1] = -1;
            } else {
                dp[pos][1] = temp+1;
            }
        } else {
            dp[pos][1] = 1;
        }
    } else {
        dp[pos][1] = -1;
    }

    if(dp[pos][0] != n+2){
        dp[pos][0] = n+2;

        if(!p_check(pos, pos-a[pos], n)){
            int temp = recurse(pos-a[pos], n);
            if(temp == -1){
                dp[pos][0] = -1;
            } else {
                dp[pos][0] = temp+1;
            }
        } else{
            dp[pos][0] = 1;
        }
    } else {
        dp[pos][0] = -1;
    }

    int temp = -1;
    if(dp[pos][0] != -1 && dp[pos][1] != -1) temp = min(dp[pos][0], dp[pos][1]);
    else if (dp[pos][0] == -1){
        temp = dp[pos][1];
    } else if(dp[pos][1] == -1){
        temp = dp[pos][0];
    }
    return temp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    a.reserve(n+1);

    rep(i, 1, n) cin>>a[i];

    rep(i, 1, n){
        dp[i][0] = dp[i][1] = n+1;
    }

    rep(i, 1, n){
        if(dp[i][0] == n+1 && dp[i][1] == n+1){
            recurse(i, n);
        }
    }

    rep(i, 1, n){
        int pos = i;
        int temp = -1;
        if(dp[pos][0] != -1 && dp[pos][1] != -1) temp = min(dp[pos][0], dp[pos][1]);
        else if (dp[pos][0] == -1){
            temp = dp[pos][1];
        } else if(dp[pos][1] == -1){
            temp = dp[pos][0];
        }
        cout<<temp<<" ";
    }




    return 0;
}

