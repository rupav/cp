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
const ll inf = 1e18L + 5;

/// pi -> c1, c2, c3, ... ck
const int nax = 3005;
vector<vector<ll>> p(nax);

void solve(){
    int n, m;
    int party;
    ll cost;
    cin>>n>>m;
    fr(voters, n){
        cin>>party>>cost;
        p[party].push_back(cost);
    }
    rep(i, 1, m) sort(p[i].begin(), p[i].end());

    /// check if its possible to win with exactly k votes, if yes
    /// find min cost
    ll ans = inf;
    int surp = (int) p[1].size();
    int x;  /// extra votes needed

    for(int votes = surp; votes <= n; votes++){
        /// check if its possible to win the election with these many votes
        x = votes - surp;
        /// check for all those parties who have current vote count greater than votes - 1
        set<int> z;
        int toRemove = 0;
        rep(i, 2, m){
            int d = (int)p[i].size() - (votes - 1);
            if(d > 0){
                z.insert(i);
                toRemove += d;
            }
        }

        if(toRemove > x){
            continue;
        }

        cost = 0ll;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for(auto it: z){
            int d = (int) p[it].size() - (votes - 1);
            for(auto c: p[it]){
                if(d){
                    cost += c;
                    d--;
                    x--;
                } else {
                    pq.push(c);
                }
            }
        }

        rep(i, 2, m){
            if(z.find(i) != z.end()) continue;
            for(auto c: p[i]) pq.push(c);
        }

        while(x){
            cost += pq.top();
            pq.pop();
            x--;
        }

        ans = min(ans, cost);

    }

    cout<<ans;

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

