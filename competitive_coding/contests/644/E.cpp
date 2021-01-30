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
    int n;
    cin>>n;
    vector<string> a(n+1);
    fr(i, n) {
        cin>>a[i];
        a[i] += '1';
    }
    a[n] = string(n + 1, '1');

    // fr(i, n+1) cout<<a[i]<<endl;
    repn(i, n - 1, 0){
        repn(j, n - 1, 0){
            if(a[i][j] == '1'){
                if(a[i+1][j] == '0' && a[i][j+1] == '0') return false;
            }
        }
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
        cout<<(solve() ? "YES" : "NO")<<endl;
    }

    return 0;
}

