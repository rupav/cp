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
    int n, b;
    cin>>n>>b;
    vector<int> pref, a(n);
    vector<pii> diff;
    fr(i, n) cin>>a[i];
    int sum = 0;
    for(auto it: a){
        sum += it%2;
        pref.push_back(sum);
    }
    for(int i=2; i<n; i+=2){
        diff.push_back({abs(a[i] - a[i-1]), i-1});
    }
    sort(diff.begin(), diff.end());
    int cnt = 0;
    for(auto it: diff){
        if(it.first > b) break;
        int i = it.second;
        if(pref[i] == (i+1)/2){
            cnt++;
            b -= it.first;
        }
    }
    cout<<cnt;
}
