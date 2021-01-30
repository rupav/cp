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

const ll INF = 3e9 + 1;
const int N = 4e6+5;
char mat[2001][2001];
int n, m, r, c;

struct Node{
    ll x, y, lm, rm;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>r>>c;
    ll l_, r_;
    cin>>l_>>r_;

    int ans = 0;
    deque<Node> dq;
    dq.push_front({r, c, l_, r_});

    rep(i, 1, n) rep(j, 1, m) cin>>mat[i][j];

    while(!dq.empty()){
        Node node = dq.front();
        dq.pop_front();
        if(mat[node.x][node.y] == '*') continue;
        ans++;
        mat[node.x][node.y] = '*';
        if(node.x>1 && mat[node.x-1][node.y] == '.') dq.push_front({node.x-1, node.y, node.lm, node.rm});
        if(node.x<n && mat[node.x+1][node.y] == '.') dq.push_front({node.x+1, node.y, node.lm, node.rm});
        if(node.y>1 && mat[node.x][node.y-1] == '.' && node.lm>0) dq.push_back({node.x, node.y-1, node.lm-1, node.rm});
        if(node.y<m && mat[node.x][node.y+1] == '.' && node.rm>0) dq.push_back({node.x, node.y+1, node.lm, node.rm-1});
    }

    cout<<ans;

    return 0;
}

