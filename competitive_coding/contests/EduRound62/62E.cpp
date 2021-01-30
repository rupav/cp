#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 998244353;

ll cntSame[200005];
ll cntDiff[200005];

void fillCnt(ll k){
    cntSame[0] = 0;
    cntDiff[0] = 1;
    int n = 200005;
    rep(i, 1, n-1){
        cntSame[i] = (cntDiff[i-1]*(k-1))%mod;
        cntDiff[i] = ((cntSame[i-1]%mod) + (cntDiff[i-1]*(k-2))%mod)%mod;
    }
    return;
}


/// returns count of arrays, with no consecutive same elements
ll helper(vector<ll> v, ll n, ll k){
    /// find consecutive -1 segments in the given vector
    ll a, b;
    a = b = -1;
    int i = 0;
    ll res = 1ll;
    while(i < n){
        if(v[i] != -1) a = v[i++];
        else {
            /// count the length of this subsegment, with consecutive -1's
            int j = i+1;
            while(j<n && v[j] == -1) j++;
            int cnt = j-i;  /// count of consecutive -1s, not including jth element, but including ith element
            ll ans = 0ll;  /// for this sequence only
            if(j == n){
                /// no 'b' found, i.e. segment is a, -1, -1, ...., -1
                if(a == -1){
                    /// seq. found is -1, -1, -1, ....., -1
                    if(cnt >= 2){
                        ans = (ans%mod + (k*cntSame[cnt-2])%mod)%mod;  /// fixing last two elements as same
                        ans = (ans%mod + k*(k-1)*(cntDiff[cnt-2])%mod)%mod;  /// fixing last two elements as different
                    } else {
                        /// seq type is '-1'.
                        return k;
                    }
                } else {
                    /// seq found is a, -1, -1, ....., -1
                    ans = (ans%mod + cntSame[cnt-1]%mod + ((k-1)*cntDiff[cnt-1])%mod)%mod;
                }
            } else {
                b = v[j];
                if(a == -1){
                    ans = (ans%mod + cntSame[cnt-1]%mod + ((k-1)*cntDiff[cnt-1])%mod)%mod;
                } else {
                    if(a == b){
                        ans = (ans + cntSame[cnt])%mod;
                    } else {
                        ans = (ans + cntDiff[cnt])%mod;
                    }
                }
                a = b; /// update 'a', for netxt segment
                b = -1;
            }

            res = (res * ans)%mod;
            i = j+1; /// update i
        }
    }
    return res;
}

bool check(vector<ll> v, int n){
    /// checks if 2 consecutive elements are same, but not -1
    rep(i, 1, n-1){
        if(v[i]!=-1 && v[i] == v[i-1]) return true;
    }
    return false;
}

int main(){

    ll n, k, x;
    cin>>n>>k;
    vector<ll> p[2];
    bool flag = false;

    fr(i, n){
        cin>>x;
        p[(i+1)&1].push_back(x);
    }

    if(check(p[0], p[0].size()) || check(p[1], p[1].size())){
        cout<<0;
        return 0;
    }

    fillCnt(k);
    cout<<(helper(p[0], p[0].size(), k) * helper(p[1], p[1].size(), k))%mod;

    return 0;
}

