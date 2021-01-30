#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;

int main(){
    int n, m;
    cin>>n;
    vector<int> a(n);
    fr(i, n) cin>>a[i];
    sort(a.begin(), a.end());
    cin>>m;
    vector<int> b(m);
    fr(i, m) cin>>b[i];
    sort(b.begin(), b.end());

    int cnt = 0;
    int st = 0;
    for(auto x: a){
        auto it = upper_bound(b.begin()+st, b.end(), x-2);
        if(it == b.end()) break;
        if(abs(x - *it) <= 1) {
            cnt++;
            st = it - b.begin() + 1;  // update
        } else {
            st = it - b.begin();
        }
    }
    cout<<cnt;
}
