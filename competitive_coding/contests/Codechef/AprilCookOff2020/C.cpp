/// MINOPS -Simple Operations
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

ll solve(){
    string s, t;
    cin>>s>>t;
    vector<int> p;
    int n = s.size();

    priority_queue<int> pq;
    fr(i, n) {
        if(s[i] != t[i]) {
            p.push_back(i);
            pq.push(1);
        }
    }

    if(p.empty()) return 0ll;

    ll sum = p.back() - p[0] + 1;



    rep(i, 1, p.size() - 1){
        pq.push(p[i] - p[i-1] + 1);
    }

    /// iterate over k, then find min. l for each k,
    ll k = 1ll;
    ll ans = sum*k;   /// for k = 1
    k++;

    ll mx;
    while(!pq.empty()){
        mx = 1ll*pq.top();
        pq.pop();
        sum -= mx;
        sum += 2ll;
        ans = min(ans, sum*k);
        k++;
    }

    return ans;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }

    return 0;
}

