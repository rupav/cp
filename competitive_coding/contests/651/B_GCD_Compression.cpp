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



void solve(){
    int n;
    cin>>n;
    int a[2 * n + 1];
    vector<int> odd, even;
    rep(i, 1, 2 * n) {
        cin>>a[i];
        a[i] = a[i]&1;
        if(a[i]) odd.push_back(i);
        else even.push_back(i);
    }

    /// gcd can be 2 alwaysby removing extra odd-even pair
    vector<int> b(n);
    if((int)odd.size()&1){
        odd.pop_back();
        even.pop_back();
    } else {
        if(odd.size()) {
            odd.pop_back();
            odd.pop_back();
        } else {
            even.pop_back();
            even.pop_back();
        }
    }

    int m = odd.size(); /// even size
    for(int i = 0; i < m; i += 2) cout<<odd[i]<<" "<<odd[i+1]<<endl;
    m = even.size();
    for(int i = 0; i < m; i += 2) cout<<even[i]<<" "<<even[i+1]<<endl;


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

