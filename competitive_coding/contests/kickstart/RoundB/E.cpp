#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
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


double solve(){
    ll m, n, x1, y1, x2, y2;    /// m rows, n cols
    cin>>m>>n>>x1>>y1>>x2>>y2;

    double p[m+1][n+1];
    if(x2 == m && y2 == n) p[m][n] = 0;
    else p[m][n] = 1;

    repn(i, m, 1){
        repn(j, n, 1){
            if(i == m && j == n) continue;
            if(i >= x1 && i <= x2 && j >= y1 && j <= y2){
                p[i][j] = 0;
                continue;
            }

            if(i == m) p[m][j] = p[m][j+1];
            else if (j == n) p[i][n] = p[i+1][n];
            else p[i][j] = 0.5*p[i+1][j] + 0.5*p[i][j+1];

        }
    }

    return p[1][1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    rep(tc, 1, t){
        cout<<"Case #"<<tc<<": ";
        cout<<solve();
        cout<<endl;
    }

    return 0;
}

