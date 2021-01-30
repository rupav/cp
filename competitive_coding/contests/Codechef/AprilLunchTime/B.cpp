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


/// https://www.codechef.com/LTIME83B/problems/SHUFFLE
bool solve(){
    int n, k, x;
    cin>>n>>k;
    vector<int> s[k];
    fr(i, n) {
        cin>>x;
        s[i%k].push_back(x);
    }

    fr(i, k) sort(s[i].begin(), s[i].end(), greater<int>());

    int a[n];
    fr(i, n){
        a[i] = s[i%k].back();
        s[i%k].pop_back();
    }

    rep(i, 1, n-1){
        if(a[i] < a[i-1]) return false;
    }


    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        cout<<(solve() ? "yes" : "no")<<endl;
    }

    return 0;
}

