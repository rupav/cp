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
    string s;
    cin>>s;
    int n = s.size();
    if(n < 5) return false;
    bool a[3] = {0};
    fr(i, n){
        if(s[i] >= 'A' && s[i] <= 'Z') a[0] = 1;
        else if(s[i] >= 'a' && s[i] <= 'z') a[1] = 1;
        else if(s[i] >= '0' && s[i] <= '9') a[2] = 1;
    }
    int sm = a[0] + a[1] + a[2];
    if(sm == 3) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    //  cin>>t;
    while(t--){
        cout<<(solve() ? "Correct" : "Too weak");
    }

    return 0;
}

