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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin>>n>>k;
    string s;
    vector<int> v(n+2);
    cin>>s;
    /// B will be 0, W will be 1 in vector v;
    rep(i, 1, n){
        v[i] = s[i-1] == 'W';
    }
    v[0] = v[n];
    v[n+1] = v[1];

    /// 2 consecutive of same color, will always remain same, on any iteration!
    /// cellular automata - maximum neighbour type problem

    /// and after 1 iteration, answer will be fixed, so do one iteration, and then check if (k-1) is odd or not!
    vector<int> ans(n+2);
    rep(i, 1, n){
        int votes = v[i-1] + v[i] + v[i+1];
        ans[i] = (votes >= 2);
    }
    ans[0] = ans[n];
    ans[n+1] = ans[1];


    /// find alternating sequences length, its size will decrease by 2 for each iteration, if original size isn't equal n

    k--;
    if(k&1){
        /// non-fixed will interchange
        rep(i, 1, n){
            if(ans[i] == ans[i-1] || ans[i] == ans[i+1]) cout<<(ans[i]?'W':'B');
            else (ans[i]?'B':'W');  /// interchange
        }
    } else {
        rep(i, 1, n){
            cout<<(ans[i]?'W':'B');
        }
    }

    return 0;
}

