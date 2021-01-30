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

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n), ans;
    fr(i, n) cin>>arr[i];
    int min_ = 1;
    int pos = 0;
    map<int, bool> mp;

    int st = 0;
    for(int i=0; i<n;){
        mp[arr[i]] = true;
        if(arr[i] == min_){
            cout<<min_<<" ";
            rep(j, st, i-2) cout<<arr[j]<<" ";
            if(i > st){
                mp[arr[i-1]] = false;
                arr[i] = arr[i-1];
                st = i;
            } else {
                i++;
                st = i;
            }
            rep(j, 1, n){
                if(!mp[j]){
                    min_ = j;
                    break;
                }
            }
        } else i++;
    }
    rep(i, st, n-1) cout<<arr[i]<<" ";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin>>q;
    while(q--){
        solve();
        cout<<endl;
    }

    return 0;
}

