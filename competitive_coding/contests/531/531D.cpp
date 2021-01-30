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

    int n;
    string s;
    cin>>n;
    cin>>s;
    int cnt[3] = {0};
    int diff[3] = {0};
    for(auto it: s) cnt[(int)(it-'0')]++;
    int x = n/3;
    fr(i, 3) diff[i] = cnt[i] - x;

    if(diff[2] > 0){
        fr(i, n){
            if(diff[2] == 0) break;
            if(s[i] == '2'){
                if(diff[0] < 0) {
                    s[i] = '0';
                    diff[0]++;
                }
                else if (diff[1] < 0){
                    s[i] = '1';
                    diff[1]++;
                } else break; /// done
                diff[2]--;
            }
        }
        diff[2] = 0;
    }

    if(diff[0] > 0){
        for(int i=n-1; i>=0; i--){
            if(diff[0] == 0) break;
            if(s[i] == '0'){
                if(diff[2] < 0) {
                    s[i] = '2';
                    diff[2]++;
                }
                else if (diff[1] < 0){
                    s[i] = '1';
                    diff[1]++;
                } else break; /// done
                diff[0]--;
            }
        }
        diff[0] = 0;
    }

    if(diff[1] > 0){
        fr(i, n){
            if(diff[1] == 0) break;
            if(s[i] == '1'){
                if(diff[0] < 0) {
                    s[i] = '0';
                    diff[0]++;
                } else break;
                diff[1]--;
            }
        }
        for(int i=n-1; i>=0; i--){
            if(diff[1] == 0) break;
            if(s[i] == '1'){
                if (diff[2] < 0){
                    s[i] = '2';
                    diff[2]++;
                } else break; /// done
                diff[1]--;
            }
        }
        diff[1] = 0;
    }

    cout<<s;

    return 0;
}

