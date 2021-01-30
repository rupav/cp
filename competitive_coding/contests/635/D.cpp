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

int n[3];
const int N = 1e5 + 5;
ll a[3][N];
ll neg[3][N];

int conv(char x){
    return (x - '0');
}

ll prof(ll x, ll y, ll z){
    return (x - y)*(x - y) + (y - z)*(y - z) + (x - z)*(x - z);
}

ll calc(int od[]){
    ll mn = numeric_limits<ll>::max();
    ll x, y, z;

    fr(i, n[od[1]]){
        y = a[od[1]][i];

        auto lb = lower_bound(neg[od[0]], neg[od[0]] + n[od[0]], -y) - neg[od[0]];
        if(lb == n[od[0]]) continue;
        else x = -neg[od[0]][lb];
        if(x > y) continue;

        lb = lower_bound(a[od[2]], a[od[2]] + n[od[2]], y) - a[od[2]];
        if(lb == n[od[2]]) continue;
        else z = a[od[2]][lb];

        mn = min(mn, prof(x, y, z));
    }

    return mn;
}

void permute(string s, int l, int r, vector<ll>& v){
    if(l == r){
        int od[3];
        fr(i, 3) od[i] = conv(s[i]);
        v.push_back(calc(od));
    }
    int n = s.size();
    rep(i, l, r){
        swap(s[i], s[l]);
        permute(s, l+1, r, v);
        swap(s[i], s[l]);
    }
}

void solve(){
    fr(i, 3) cin>>n[i];
    fr(i, 3) {
        fr(j, n[i]) {
            cin>>a[i][j];
            neg[i][j] = -a[i][j];
        }
        sort(a[i], a[i] + n[i]);
        sort(neg[i], neg[i] + n[i]);

    }

    vector<ll> poss;
    string z = "012";
    permute(z, 0, 2, poss);

    // for(auto it: poss) cout<<it<<endl;

    cout<<(*min_element(poss.begin(), poss.end()))<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

