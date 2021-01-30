
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

int gcd(int a, int b){
    if(!b) return a;
    return  gcd(b, a%b);
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

int helper(string s, int l, int r, int n){
    int count = 0;
    while(l >= 0 && r<n && s[l] == s[r]){
        l--;
        r++;
        count += 2;
    }
    return count;
}

int LongestPalindromicSubstring(string s){
    /// based on center method - 0(n^2) with constant space.
    int ans = 0;
    int n = s.length();
    for(int i=0; i<n; i++){
        ans = max(ans, max(helper(s, i-1, i+1, n)+1, helper(s, i, i+1, n)));
    }
    return ans;
}

int LongestPalindromicSubstringDP(string s){
    int n = s.length();
    bool P[n][n];  /// P[i][j] stores where s[i...j] is palindrome or not
    // initialization
    fr(i, n){
        fr(j, n) P[i][j] = false;
        P[i][i] = true;
    }
    int ans = 1;
    for(int i=n-2; i>=0; i--){
        rep(j, i+1, n-1){
            if(j-i+1 == 2){
                P[i][j] = (s[i] == s[j]);
            } else {
                P[i][j] = (s[i] == s[j] && P[i+1][j-1]);
            }
            if(P[i][j]) ans = max(ans, j-i+1);
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    getline(cin>>ws, s);
    cout<<s<<endl;
    string::iterator it = max_element(s.begin(), s.end());
    cout<<distance(s.begin(), it)<<endl;
    cout<<*it<<endl;
    cout<<LongestPalindromicSubstring(s)<<endl;
    cout<<LongestPalindromicSubstringDP(s)<<endl;
    return 0;
}
