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

/// https://www.codechef.com/RC122020/problems/RECNDNOS
int solve(){
    int n;
    cin>>n;
    int a[n];
    map<int, int> mp;
    fr(i, n){
        cin>>a[i];
    }

    int cnt = 0, i = 0;
    while(i < n){
        int j = i + 1;
        while(j < n && a[j] == a[i]) j++;
        cnt = j - i;    /// consecutive a[i]
        mp[a[i]] += (cnt + 2 - 1)/2; /// ceil
        i = j;
    }

    int mx = 0;
    int val;
    for(auto it: mp) {
        if(it.second > mx){
            mx = it.second;
            val = it.first;
        }
    }
    return val;
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

