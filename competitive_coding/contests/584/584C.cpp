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


int conv(char i){
    return (int)(i-'0');
}

void print(vector<int> &color, int n){
    fr(i, n) cout<<color[i];
    cout<<endl;
}

bool check(vector<int> &color, vector<int> &a, int n){
    /// checking if both sequences are increasing are not in the same color!
    int max_[2] = {-1, -1};
    int z;
    fr(i, n){
        z = color[i] - 1;  /// either 0 or 1
        if(a[i] >= max_[z]){
            max_[z] = a[i];
        } else {
            return false;
        }
    }
    return true;
}

void solve(string &s, int n){
    vector<int> a(n);
    vector<int> color(n);
    fr(i, n) a[i] = conv(s[i]);

    /// finding critical x
    fr(x, 10){
        int secondSequFirstIndex = -1;
        fr(i, n){
            if(a[i] > x) {
                color[i] = 2;
                if(secondSequFirstIndex == -1) secondSequFirstIndex = i;
            }
            else if(a[i] < x) color[i] = 1;
        }
        ///
        fr(i, n){
            if(a[i] == x){
                if(i < secondSequFirstIndex) color[i] = 2;
                else color[i] = 1;
            }
        }
        /// now check
        if(check(color, a, n)){
            print(color, n);
            return ;
        }
    }

    cout<<"-"<<endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t, n;
    cin>>t;
    string s;
    while(t--){
        cin>>n;
        cin>>s;
        solve(s, n);
    }

    return 0;
}

