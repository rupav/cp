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
    int n;
    cin>>n;
    int a[n];
    fr(i, n) cin>>a[i];

    int lp(0), rp(n-1);
    int prev = 0;
    int moves = 0;
    int sum[2] = {0};
    bool f = true;
    int temp;

    while(lp <= rp){
        if(f){
            temp = 0;
            while(lp <= rp && temp <= prev){
                temp += a[lp++];
            }

            sum[0] += temp;
        } else {
            temp = 0;
            while(rp >= lp && temp <= prev){
                temp += a[rp--];
            }

            sum[1] += temp;
        }

        prev = temp;
        moves++;
        f = !f;
    }
    cout<<moves<<" "<<sum[0]<<" "<<sum[1]<<endl;
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

