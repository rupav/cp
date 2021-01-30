#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pll;
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

    ll n, k;
    cin>>n>>k;
    ll a[n];
    fr(i, n) cin>>a[i];
    sort(a, a+n);
    vector<pll> arr;
    for(int i=0; i<n;){
        int j = i+1;
        while(j<n && a[j] == a[i]){
            j++;
        }
        arr.push_back({a[i] ,j-i});
        i = j;
    }

    n = arr.size();
    ll min_ = arr[n-1].first - arr[0].first;

    int i=0, j=n-1;
    while(i<j){
        if(arr[i].second < arr[j].second){
            if(arr[i].second <= k){
                ll z = arr[i+1].first - arr[i].first;
                /// find max cnt<=z for which cnt*arr[i].second <= k
                ll cnt = min(z, k/arr[i].second);
                min_ -= cnt;
                k -= cnt*arr[i].second;
                arr[i+1].second += arr[i].second;
                i++;
            } else break;
        } else {
            if(arr[j].second <= k){
                ll z = arr[j].first - arr[j-1].first;
                /// find max cnt<=z for which cnt*arr[i].second <= k
                ll cnt = min(z, k/arr[j].second);
                min_ -= cnt;
                k -= cnt*arr[j].second;
                arr[j-1].second += arr[j].second;
                j--;
            } else break;
        }
    }
    cout<<min_<<endl;

    return 0;
}

