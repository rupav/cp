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


void solve(){
    int n, m, x;
    cin>>n>>m;
    vector<vector<int>> a(n);
    fr(i, n){
        fr(j, m){
            cin>>x;
            a[i].push_back(x);
        }
    }
    pii ans;

    /// binary search over answer >= x, if true, then answer is also valid for y < x
    /// find max x, such that there exists a pair whose 'b' array value min. is >= x

    vector<int> masks(n);
    map<int, int> mp;   /// mask and leader
    int lb(0), rb(1e9 + 5);

    while(lb <= rb){
        x = lb + (rb - lb)/2;
        mp.clear();
        fr(i, n) masks[i] = 0;
        fr(i, n){
            fr(j, m){
                if(a[i][j] >= x)
                    masks[i] |= (1 << j);
            }
            if(mp.find(masks[i]) == mp.end()) mp[masks[i]] = i;
        }

        /// check between each pair of distinct masks, if OR of pairs make ALL_ONE
        int ALL_ONE = (1 << m) - 1;

        int z;
        bool f = false;
        for(auto &m1: mp){
            for(auto &m2: mp){
                z = m1.first | m2.first;
                if(z == ALL_ONE) {
                    f = true;
                    ans = make_pair(m1.second, m2.second);
                }
            }
        }

        if(f){
            lb = x + 1;
        } else rb = x - 1;

    }

    cout<<ans.first + 1<<" "<<ans.second + 1;
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

