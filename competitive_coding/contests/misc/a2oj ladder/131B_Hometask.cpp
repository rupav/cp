#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

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

void solve(){
    int n;
    cin>>n;
    int a[n];
    bool f = false;
    int sum = 0;
    vector<int> res[3];
    fr(i, n) {
        cin>>a[i];
        res[a[i]%3].push_back(a[i]);
        sum = (sum + a[i])%3;
        if(!a[i]) f = true;
    }

    if(!f) {
        cout<<-1;
        return;
    }

    sort(a, a+n, greater<int>());

    if(!a[0]){
        cout<<0;
        return;
    }

    if(sum == 0){
        fr(i, n) cout<<a[i];
        return;
    }

    multiset<int> ms;
    fr(i, n) ms.insert(a[i]);
    fr(i, 3) sort(res[i].begin(), res[i].end());

    int x;
    if(res[sum].size()){
        ms.erase(ms.find(*res[sum].begin()));
    } else {
        x = (sum == 1) ? 2 : 1;
        auto it = res[x].begin();
        ms.erase(ms.find(*it));
        it++;
        ms.erase(ms.find(*it));
    }

    vector<int> ans;
    for(auto it: ms) ans.push_back(it);

    sort(ans.begin(), ans.end(), greater<int>());
    if(ans[0] == 0){
        cout<<0;
        return;
    }

    for(auto it: ans) cout<<it;


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    //  cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

