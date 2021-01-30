#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;
map<int, bool> mp;
int N = 0;

bool check(int i, int n = N){
    if(i<=n && i>=1 && mp[i] == false){
        return mp[i] = true;
    } else {
        cout<<-1;
        return false;
    }
}

int main(){
    int n;
    cin>>n;
    N = n;
    int q[n];
    ll p_sum[n] = {0};

    ll cp = 0;
    rep(i, 1, n-1){
        cin>>q[i];
        p_sum[i] = p_sum[i-1] + q[i];
        cp = min(cp, p_sum[i]);
    }

    int x = -cp+1;  /// let be p1
    if(!check(x)) return 0;

    int p[n];
    int k = 1;
    p[0] = x;
    rep(i, 1, n-1){
        if(!check(x+p_sum[i])) return 0;
        p[k++] = x+p_sum[i];
    }

    fr(i, n)
        cout<<p[i]<<" ";

    return 0;
}

