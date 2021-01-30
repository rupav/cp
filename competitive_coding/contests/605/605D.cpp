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
    cin>>n;
    ll a[n], r[n], l[n];
    fr(i, n){
        cin>>a[i];
        r[i] = l[i] = 0;
    }

    ll max_ = *max_element(a, a+n);

    r[n-1] = l[0] = 0;
    int i = 0;
    while(i < n-1){
        int j=i+1;
        ll min_ = -1;
        while(j<n && a[j] > min_){
            min_ = a[j];
            j++;
        }
        ll d = 1ll*(j-i-1);
        rep(k, i, j-1){
            r[k] = d;
            d--;
        }
        i = max(j-1, i+1);
    }

    i = n-1;
    while(i > 0){
        int j=i-1;
        ll min_ = max_+1;
        while(j>=0 && a[j] < min_){
            min_ = a[j];
            j--;
        }
        ll d = 1ll*(i-j-1);
        for(int k=i; k>j; k--){
            l[k] = d;
            d--;
        }
        i = min(j+1, i-1);
    }

    ll ans = 0;
    fr(i, n){
        ll temp = 0;
        if(l[i] == 0ll){
            temp = r[i];
        } else if (r[i] == 0ll){
            temp = l[i];
        } else {
            if(a[i-1] < a[i+1]){
                temp = l[i] + r[i];
            } else {
                temp = max(l[i], r[i]);
            }
        }
        ans = max(ans, temp);
    }


    i = 0;
    ll len = 0;
    while(i<n){
        ll min_ = a[i];
        int j=i+1;
        while(j<n && a[j]>min_){
            min_ = a[j];
            j++;
        }
        len = max(len, 1ll*(j-i));
        i = j;
    }

    cout<<max(ans, len);

    return 0;
}

