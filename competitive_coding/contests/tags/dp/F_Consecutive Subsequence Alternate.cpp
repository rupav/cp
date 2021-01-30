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

map<int, int> dp;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    fr(i, n){
        cin>>a[i];
        dp[a[i]] = 0;
    }

    fr(i, n){
        dp[a[i]] = max(dp[a[i]], dp[a[i]-1] + 1);
    }

    int max_ = 0;
    int lst = 0;
    for(auto it: dp){
        if(it.second > max_){
            max_ = it.second;
            lst = it.first;
        }
    }

    vector<int> ans;
    int st = lst - max_ + 1;
    fr(i, n){
        int x = a[i];
        if(x == st){
            ans.push_back(i+1);
            st++;
            max_--;
        }
        if(max_ == 0) break;
    }

    cout<<ans.size()<<endl;
    for(auto it: ans) cout<<it<<" ";

    return 0;
}
