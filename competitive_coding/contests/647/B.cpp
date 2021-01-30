#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a) * (a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;


int solve(){
    int n;
    cin>>n;
    int a[n];
    fr(i, n) cin>>a[i];
    if(n == 1) return -1;

    int k;
    vector<int> ans;
    set<int> el;
    fr(i, n) el.insert(a[i]);

    int x = a[0];
    rep(i, 1, n - 1){
        /// find k, s.t. x^k = a[i] => k = a[i]^x
        k = a[i] ^ x;
        /// check if its valid k
        bool f = true;
        set<int> s;
        fr(j, n) s.insert(a[j] ^ k);
        for(auto it: el){
            if(s.find(it) == s.end()) {
                f = false;
                break;
            } else s.erase(s.find(it));
        }
        if(f) ans.push_back(k);
    }

    if(ans.size()){
        return *min_element(ans.begin(), ans.end());
    } else return -1;

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

