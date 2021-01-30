#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;
const int N = (int) 1e5+5;
ll fac[N];
ll ifac[N];
ll dp[N];
ll temp_dp[N];

int encode(char c){
    if(c>='A' && c<='Z')
        return (int)(c-'A'+26);
    return (int)(c-'a');
}

char decode(int n){
    if(n<26)
        return (char)('a'+n);
    n-=26;
    return (char)('A'+n);
}

ll fmod(ll x, ll p = mod-2){  /// modulo binary exponentiation.
    x = x%mod;
    ll res = 1;
    while(p){
        if(p&1ll)
            res = (res*x)%mod;
        p = p>>1;
        x = (x*x)%mod;
    }
    return res;
}

void findFac(int n, bool force = false){
    if(force){
        fac[0] = 1;
        rep(i, 1, n)
            fac[i] = (fac[i-1]*1ll*i)%mod;
    }
    return;
}

void findIFac(int n, bool force = false){
    findFac(n, force);
    /// by fermat's little thm, find ifac[n]
    ifac[n] = fmod(fac[n], mod-2);
    for(int i=n-1; i>=0; i--){
        ifac[i] = (ifac[i+1]*1ll*(i+1))%mod;
    }
    return;
}

void constructDP(map<char, ll> &mp, int sum){
    dp[0] = 1;  /// by not selecting any element from the array.
    rep(i, 1, sum)
        dp[i] = 0;
    for(auto i: mp){
        for(int j=sum; j>=i.second; j--){
            dp[j] += dp[j-i.second];
            if(dp[j]>=mod)
                dp[j] -= mod;
            /// no. of ways to select for elements upto ith index, to add upto j is equal to current dp[j]+ no. of ways to add upto j-i!
        }
    }
    return;
}



int main(){
    int n, q, x, y;
    string s;
    cin>>s>>q;
    n = s.size();
    map<char, ll> mp;
    fr(i, n)
        mp[s[i]]++;  /// freq. of each character present in the string.

    /// part 1 - finding number of good strings.
    findFac(n, true);
    findIFac(n, false);
    ll W = (fac[n/2]*fac[n/2])%mod;
    for(auto i: mp){
        W = (W*ifac[i.second])%mod;
    }

    /// finding dp[n/2] = number of ways to combine f's such that their sum is n/2.
    /// total sum of freq. is 'n'.
    constructDP(mp, n);

    /// part 2 - precalculate for each pair of alphabets, if their frequencies are not included in sum = n/2.
    ll qdp[53][53];
    fr(i, 52)
        fr(j, 52)
            qdp[i][j] = dp[n/2];  /// initialization.

    fr(i, 52){
        ll freq_i = mp[decode(i)];
        if(!freq_i)
            continue;
        fr(k, n+1)
            temp_dp[k] = dp[k];
        /// remove ith element from the dp array.
        rep(k, freq_i, n){
            temp_dp[k] -= temp_dp[k - freq_i];
            if(temp_dp[k]<0)
                temp_dp[k] += mod;
        }

        rep(j, i+1, 51){
            ll freq_j = mp[decode(j)];
            if(!freq_j)
                continue;
            rep(k, freq_j, n){
                temp_dp[k] -= temp_dp[k - freq_j];
                if(temp_dp[k]<0)
                    temp_dp[k] += mod;
            }
            qdp[i][j] = (2ll*temp_dp[n/2])%mod;
            qdp[j][i] = qdp[i][j];  /// symmetric removal.
            /// restore temp_dp now for next j,
            for(int k=n; k>=freq_j; k--){
                temp_dp[k] += temp_dp[k-freq_j];
                if(temp_dp[k]>=mod)
                    temp_dp[k] -= mod;
            }
        }
    }

    /// queries time!
    while(q--){
        cin>>x>>y;
        x--;
        y--;  /// since we are following 0-based indexing.
        cout<<((W*qdp[encode(s[x])][encode(s[y])]))%mod<<endl;
    }

    return 0;
}

