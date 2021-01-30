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
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    map<int, int> mp; 
    string r = s;
    int i = 0;
    while(i < n){
        if(s[i] == '1'){
            int j = i + 1;
            while(j < n && j - i <= k) r[j++] = '1';
            i = j;
            continue;
        }
        i++;
    }

    i = n - 1;
    while(i >= 0){
        if(s[i] == '1'){
            int j = i - 1;
            while(j >= 0 && i - j <= k) r[j--] = '1';
            i = j;
            continue;
        }
        i--;
    }

    vector<int> segs;

    i = 0;
    while(i < n){
        if(r[i] == '0'){
            int j = i + 1;
            while(j < n && r[j] == '0') j++;
            mp[j - i]++;
            segs.push_back(j - i);
            i = j;
            continue;
        }
        i++;
    }

    int ans = 0;
    int cnt;
    for(auto &it: segs){
        cnt = 1;
        it--;

        while(it > 0){
            it -= k;
            if(it > 0){
                it--;
                cnt++;
            }
        }

        ans += cnt;
    }

    cout<<ans<<endl;

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

