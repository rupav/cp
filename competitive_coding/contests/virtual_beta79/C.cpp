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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    int n = s.size();
    int k;
    cin>>k;

    int f[26] = {0};
    for(auto it: s){
        f[it - 'a']++;
    }

    vector<pii> v;
    for(int i=0; i<26; i++){
        v.push_back({f[i], i});
    }

    sort(v.begin(), v.end());

    for(auto it: v){
        if(it.first <= k){
            k -= it.first;
            f[it.second] = 0;
        } else {
            f[it.second] -= k;
            k = 0;
            break;
        }
    }

    string res = "";
    set<char> st;
    for(auto it: s){
        if(f[it - 'a']){
            f[it - 'a']--;
            res += it;
            st.insert(it);
        }
    }

    cout<<st.size()<<endl;
    cout<<res;

    return 0;
}

