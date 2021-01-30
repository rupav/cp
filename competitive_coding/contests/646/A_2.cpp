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


bool solve(){
    int n, x;
    cin>>n>>x;
    int a[n];
    int cnt[2] = {0};
    int sm = 0;
    fr(i, n) {
        cin>>a[i];
        cnt[a[i]&1]++;
        sm += a[i];
    }

    if(x == n) return (sm & 1);


    if(x&1){
        if(cnt[1]) {
            if(cnt[1]%2 == 0) cnt[1]--;
            return (x <= cnt[1] + cnt[0]);
        }
        else return false;
    } else {
        if(!cnt[1] || !cnt[0]) return false;
        if(cnt[1]%2 == 0) cnt[1]--;
        return (x <= cnt[1] + cnt[0]);
    }
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

