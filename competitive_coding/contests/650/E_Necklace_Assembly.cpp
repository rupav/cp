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


int solve(){
    int n, k;
    cin>>n>>k;
    int cnt[26] = {0};
    string s;
    cin>>s;
    for(auto it: s){
        cnt[it - 'a']++;
    }

    repn(l, n, 1){
        int g = __gcd(k, l);
        int sz = l / g;
        int temp = 0;
        fr(i, 26){
            if(cnt[i] >= sz) temp += cnt[i]/sz;
        }
        if(temp >= g) return l;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }

    return 0;
}

