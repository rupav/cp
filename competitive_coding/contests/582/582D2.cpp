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

pair<int, int> res[200010];  /// steps to reach there, and count of elements who reached there!

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fr(i, 200010) res[i] = make_pair(0, 0);

    int n, k;
    cin>>n>>k;

    int x;
    int arr[n];
    fr(i, n) cin>>arr[i];
    sort(arr, arr+n);
    fr(i, n){

        x = arr[i];

        int steps = 0;
        while(x){
            pii temp = res[x];
            if(temp.second < k)
                res[x] = make_pair(steps + temp.first, temp.second+1);  /// else dont update no. of steps!
            x = x>>1;
            steps++;
        }
        pii temp = res[0];
        if(temp.second < k)
            res[0] = make_pair(steps+temp.first, temp.second+1);  /// all elements will reach here!
    }

    int ans = INT_MAX;
    fr(i, 200010){
        if(res[i].second >= k){
            ans = min(ans, res[i].first);
        }
    }

    cout<<ans;

    return 0;
}

