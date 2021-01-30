#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
#define int ll
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;


vector<int> a;

int lis(vector<int>::iterator it, vector<int>::iterator jit, bool strict = true){
    vector<int> en;
    while(it < jit){
        auto ub = (!strict) ? upper_bound(en.begin(), en.end(), *it) : lower_bound(en.begin(), en.end(), *it);
        if(ub == en.end()){
            en.push_back(*it);
        } else en[ub - en.begin()] = *it;
        it++;
    }
    return (int)en.size();
}

int solve(){
    int n;
    cin>>n;
    a.resize(n);
    fr(i, n) cin>>a[i];

    return max({lis(a.begin(), a.end(), true),
                1 + lis(a.begin() + 1, a.begin() + n),
                1 + lis(a.begin(), a.begin() + n - 1)
               });

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    // cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }

    return 0;
}


