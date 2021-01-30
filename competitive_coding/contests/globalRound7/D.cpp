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

ll gcdll(ll a, ll b){
    if(!b) return a;
    return gcdll(b, a%b);
}

void seive(int n){
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;

    for(int i=2; i*i<=n; i++){
        if(is_prime[i]){
            for(int j=i*i; j<=n; j+=i){
                is_prime[j] = false;
            }
        }
    }
}

vector<int> constructZFunc(string s){
    int n = s.size();
    vector<int> z(n);
    int l, r;
    l = r = 0;
    z[0] = 0;
    rep(i, 1, n-1){
        z[i] = 0;
        if(i<=r){
            z[i] = min(r-i+1, z[i-l]);  /// initialization, req. for linear time approach.
        }
        while(i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if(i+z[i]-1 > r){
            r = i+z[i]-1;
            l = i;
        }
    }
    return z;
}

int LongestPalindromicPrefix(string s){
    /// let s = AB, with A as the longest palindromic prefix, then ss = s+s.reverse()  = ABB'A, and then return lps of ss, to get the answer
    if(s.size()  == 0) return 0;
    string temp = s;
    reverse(s.begin(), s.end());
    string ss = temp + s;
    vector<int> z = constructZFunc(ss);
    /// find lps
    int res = 1;
    for(int i=s.size(); i<ss.size(); i++){
        if(z[i] + i == ss.size()){
            res = z[i];
            break;
        }
    }
    return res;
}

void solve(){
    string s, t, res;
    cin>>s;
    t = s;
    int n = s.size();
    reverse(t.begin(), t.end());
    vector<int> z = constructZFunc(s + t);

    int en = min(n/2, z[n]);

    int rem_len = n - 2*en;
    string s2, t2;
    int m1, m2;
    s2 = s.substr(en, rem_len);
    t2 = s2;

    reverse(t2.begin(), t2.end());
    m1 = LongestPalindromicPrefix(s2);
    m2 = LongestPalindromicPrefix(t2);

    res = s.substr(0, en);
    t = res;
    reverse(t.begin(), t.end());

    if(m1 >= m2){
        res += s2.substr(0, m1);
    } else {
        res += t2.substr(0, m2);
    }
    res += t;

    cout<<res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        solve();
        cout<<endl;
    }

    return 0;
}

