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
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt[26] = {0};

    int swaps[n] = {0};

    for(int i = n-1; i>=0; i--){
        fr(j, (int)(s[i]-'a')){
            swaps[i] += cnt[j];
        }
        cnt[(int)(s[i]-'a')]++;
    }

    int res[n] = {0};
    int temp[n] = {0};

    for(int i=n-2; i>=0; i--){
        if(swaps[i] == 0){
            temp[i] = temp[i+1];
            res[i] = temp[i];
        } else {
            rep(j, i+1, swaps[i]+i-1){
                if(temp[j] != temp[j+1]){
                    cout<<"NO"<<endl;
                    return;
                }
            }
            res[i] = !temp[i+1];
            rep(j, i, swaps[i]+i-1){
                temp[j] = !res[i];
            }
            temp[swaps[i]+i] = res[i];
        }
    }
    cout<<"YES"<<endl;

    fr(i, n) cout<<res[i];
    cout<<endl;
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

