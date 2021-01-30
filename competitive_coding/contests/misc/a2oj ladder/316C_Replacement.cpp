#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
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

char conv(char z){
    if(z == '.') return z;
    return 'x';
}

void solve(){
    int n, m;
    cin>>n>>m;
    string s;
    cin>>s;
    int len = 0, cnt = 0;
    int i=0;
    while(i < n){
        if(s[i] == '.'){
            cnt++;
            int j = i+1;
            while(j < n && s[j] == '.') j++;
            len += j - i;
            i = j;
        } else i++;
    }

    int x;
    char z;

    fr(i, m){
        cin>>x>>z;
        z = conv(z);
        x--;

        if(z == conv(s[x]));
        else if(z == '.'){
            /// char to .
            len++;
            if((x > 0 && s[x-1] == '.') && (x < n - 1 && s[x+1] == '.')) cnt--;
            else if((x > 0 && s[x-1] == '.') || (x < n - 1 && s[x+1] == '.'));
            else cnt++;
        } else {
            /// . to char
            len--;
            if((x > 0 && s[x-1] == '.') && (x < n - 1 && s[x+1] == '.')) cnt++;
            else if((x > 0 && s[x-1] == '.') || (x < n - 1 && s[x+1] == '.'));
            else cnt--;
        }

        s[x] = z;

        cout<<len - cnt<<endl;
    }

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

