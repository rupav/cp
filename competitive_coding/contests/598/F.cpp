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

const int sz = 26;
int bit[sz + 1];

void update(int i, int upd){
    for(; i <= sz; i += i&(-i)) bit[i] += upd;
}

int get(int i){
    int sum = 0;
    for(; i > 0; i -= i&(-i)) sum += bit[i];
    return sum;
}

bool solve(){
    int n;
    string s, t;
    cin>>n;
    cin>>s>>t;
    map<char, int> mp;
    bitset<26> bs, bt;
    for(auto it: s) bs |= 1<<(it - 'a');
    for(auto it: t) bt |= 1<<(it - 'a');
    if(bs != bt) return false;

    // find inversion count of s and t, if same parity return true, if not check if any element has frequency more than 1
    int p[2] = {0};

    fr(i, sz+1) bit[i] = 0;
    reverse(s.begin(), s.end());

    for(auto it: s){
        p[0] = (p[0] + get(it - 'a')%2)%2;
        update(it - 'a' + 1, 1);
    }

    fr(i, sz+1) bit[i] = 0;
    reverse(t.begin(), t.end());

    for(auto it: t){
        p[0] = (p[0] + get(it - 'a')%2)%2;
        update(it - 'a' + 1, 1);
    }

    if(p[0] == p[1] || bs.count() < n) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        cout<<(solve() ? "YES" : "NO")<<endl;
    }

    return 0;
}

