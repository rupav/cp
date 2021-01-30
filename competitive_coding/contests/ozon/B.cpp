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

void solve(){
    string s;
    cin>>s;
    int n = s.size();

    int pos[n] = {0};
    fr(i, n) pos[i] = n+1;

    int len = 1;
    fr(i, n){
        if(s[i] == '(') pos[len++] = i;
    }

    len = 1;
    int max_ = 0;
    for(int i=n-1; i>=0; i--){
        if(s[i] == ')'){
            if(i < pos[len]){
                /// stop
                break;
            } else max_ = len;
            len++;
        }
    }

    cout<<(max_ != 0)<<endl;
    if(!max_) return;
    cout<<(max_*2)<<endl;
    rep(len, 1, max_) cout<<pos[len]+1<<" ";
    stack<int> st;

    for(int i=n-1; i>=0; i--){
        if(max_ && (s[i] == ')')){
            st.push(i+1);
            max_--;
        }
    }

    while(st.size()){
        cout<<st.top()<<" ";
        st.pop();
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    //  cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

