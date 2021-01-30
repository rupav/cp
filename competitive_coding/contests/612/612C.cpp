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

    int n, x;
    cin>>n;
    int a[n];
    int cnt[2] = {n/2, n/2 + (n&1)};
    fr(i, n){
        cin>>x;
        if(x == 0) a[i] = -1;
        else{
            a[i] = x%2;
            cnt[a[i]]--;
        }
    }

    bool p[2];
    int i=0;
    while(i<n){
        if(a[i] != -1){
            int j = i+1;
            while(j<n){
                if(a[j] == -1){
                    p[0] = a[j-1];
                    int k = j+1;
                    while(k<n && a[k]==-1) k++;
                    if(k != n){
                        p[1] = a[k];
                    }
                    if(p[0] == p[1]){
                        /// fill from j
                        k = j;
                        while(k<n && a[k] == -1 && cnt[p[0]]){
                            a[k] = p[0];
                            cnt[p[0]]--;
                            k++;
                        }
                        while(k<n && a[k] == -1){
                            a[k] = !p[0];
                            cnt[!p[0]]--;
                            k++;
                        }
                    }
                    j = k+1;
                    continue;
                }
                j++;
            }
            break;
        }
        i++;
    }

    i = 0;
    while(i<n){
        if(a[i] ! = -1){
            int j=i-1;
            p[0] = a[i];
            while(j>=0 && cnt[p[0]]){
                a[j] = p[0];
                cnt[p[0]]--;
                j--;
            }
            while(j>=0){
                a[j] = !p[0];
                cnt[!p[0]]--;
                j--;
            }
            break;
        }
        i++;
    }

    i=0;
    while(i<n){
        if(a[i] != -1){
            int j=i+1;

        }
    }

    return 0;
}

