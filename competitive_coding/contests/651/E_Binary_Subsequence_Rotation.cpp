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

bool check(string s, string t){
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}

void solve(){
    int n;
    cin>>n;
    string s, t;
    cin>>s;
    cin>>t;
    /// check anagram
    if(!check(s, t)){
        cout<<-1;
        return;
    }

    set<int> odd[2];
    
    fr(i, n){
        if(s[i] != t[i]) {
            odd[s[i] == '1'].insert(i);
        }
    }

    /// simulate the whole process!
    vector<int> v(n);  /// elements to be deleted from set
    int ans = 0;
    while((int) odd[0].size()){
        int lb[2];
        fr(i, 2) lb[i] = *odd[i].begin();
        bool st = (lb[1] < lb[0]) ? 1 : 0;
        /// if we start from st, we have to end at !st, i.e. length of chain is always even
        int cnt = 0;
        bool p = st;
        int curr = lb[st];
        while(true){
            // watch(lb[st]);
            auto ub = odd[!st].upper_bound(curr);
            /// delete previous
            v[cnt++] = curr;
            // odd[st].erase(lb[st]);
            if(ub == odd[!st].end()){
                break;
            }
            curr = *ub;
            st = !st;
        }

        /// now delete only even chain
        if(cnt&1) cnt--;
        int i = 0;
        while(i < cnt){
            odd[p].erase(v[i]);
            i++;
            p = !p;
        }

        ans++;
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

