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

int conv(int i, int n){
    if(i < 0) return n-1;
    return i;
}


vector<int> arr;

bool check(int j, int val, int n){
    while(arr[j] != 1){
        if(arr[j] != val) return false;
        val++;
        j = (j+1)%n;
    }
    return true;
}

bool solve(int st, int n){
    if(n == 1) return true;
    if( arr[(st+1)%n] ==  2){
        /// clockwise possible
        int j = (st+2)%n;
        return check(j, 3, n);
    } else if ( arr[conv(st-1, n)] == 2){
        /// anticlockwise possible
        /// reverse the array, for
        reverse(arr.begin(), arr.end());
        st = (n-1)-st;
        int j = (st+2)%n;
        return check(j, 3, n);
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        arr.resize(n);
        int st;
        fr(i, n){
            cin>>arr[i];
            if(arr[i] == 1) st = i;
        }
        cout<<(solve(st, n) ? "YES": "NO");
        cout<<endl;
    }

    return 0;
}

