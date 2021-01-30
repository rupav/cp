#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<bool, bool> pii;
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

    int n;
    cin>>n;
    vector<int> a(n);
    fr(i, n) cin>>a[i];

    map<int, bool> mp;
    int cnt = 0;
    vector<int> ans;

    int sum = 0;
    int i = 0;
    for(auto it: a){
        if(mp[it]){
            if(it < 0){
                cout<<-1;
                return 0;
            } else {
                if(mp[-1*it] == false){
                    cout<<-1;
                    return 0;
                } else {
                    /// break till here
                    for(auto it: mp){
                        if(!mp[-1*it.first]){
                            cout<<-1;
                            return 0;
                        }
                    }

                    mp.clear();
                    mp[it] = true;
                    if(!ans.empty()){
                        ans.push_back(i - sum);
                        // sum += (i - sum);
                    } else {
                        ans.push_back(i);
                        // sum += i;
                    }
                    sum = i;
                }
            }
        } else {
            if(it < 0){
                if(mp[abs(it)]){
                    mp[it] = true;
                } else {
                    cout<<-1;
                    return 0;
                }
            } else {
                mp[it] = true;
            }
        }
        i++;
    }

    int ind = accumulate(ans.begin(), ans.end(), 0);
    int x = n - ind;

    for(auto it: mp){
        if(!mp[-1*it.first]){
            cout<<-1;
            return 0;
        }
    }


    cout<<ans.size() + !(!x)<<endl;
    for(auto it: ans) cout<<it<<" ";
    if(x) cout<<x;

    return 0;
}

