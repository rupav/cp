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

char nxt(char x){
    if(x == 'z') return 'a';
    return (char)(x + 1);
}

void solve(){
    int n, x;
    cin>>n;
    string s(200, 'a');
    cout<<s<<endl;
    fr(i, n){
        cin>>x;
        s[x] = nxt(s[x]);
        cout<<s<<endl;
    }
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

