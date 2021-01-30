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

int shifts = 0, l_i = 1, r_i = 1;


void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt = 0;
    for(auto it: s){
        if(it == '(') cnt++;
    }
    if(2*cnt != n){
        shifts = 0;
        l_i = r_i = 1;
        return;
    }

    shifts = 0;

    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            char x = s[i];
            s[i] = s[j];
            s[j] = x;

            /// check if correct
            cnt = 0;
            int sh = 0;
            stack<char> st;
            for(auto it: s){
                if(it == '(') st.push(it);
                else {
                    if(!st.empty()){
                        st.pop();
                        if(st.empty()) sh++;
                    }
                    else cnt++;
                }
            }
            if(true){
                /// update ans, by countint no. of disjoint correct sequences
                int z = (!st.empty()) + sh;
                if(z > shifts){
                    shifts = z;
                    l_i = i+1;
                    r_i = j+1;
                }
            }
            /// restore
            x = s[i];
            s[i] = s[j];
            s[j] = x;
        }
    }


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    /// for each swap check
    solve();
    cout<<shifts<<endl;
    cout<<l_i<<" "<<r_i;
    return 0;
}

