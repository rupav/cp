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

int x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6;

bool debug(){
    static int x = 0;
    // cout<<x++<<endl;
    return true;
}

bool solve(){

    if((min(x3, x5) <= x1) && (min(y3, y5) <= y1) && debug() &&  /// left && bottom edge covered or not
       (max(x4, x6) >= x2) && (max(y4, y6) >= y2) && debug() &&  /// right && upper edge covered or not
       (((min(x4, x6) < x2) && ((min(x4, x6) >= max(x3, x5)) || (max(x3, x5) <= x1))) || (min(x4, x6) >= x2)) && debug() &&   /// if 1 black sheet covers the whole white
       (((min(y4, y6) < y2) && ((min(y4, y6) >= max(y3, y5)) || (max(y3, y5) <= y1))) || (min(y4, y6) >= y2)) && debug() &&   ///
       (((x4>=x2) && (y4>=y2)) || ((x6>=x2) && (y6>=y2))) && debug() &&  /// check if each corner is covered
       (((x3<=x1) && (y3<=y1)) || ((x5<=x1) && (y5<=y1))) && debug() && \
       (((x3<=x1) && (y4>=y2)) || ((x5<=x1) && (y6>=y2))) && debug() && \
       (((x4>=x2) && (y3<=y1)) || ((x6>=x2) && (y5<=y1))))
        return false;

    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4>>x5>>y5>>x6>>y6;

    cout<<(solve() ? "YES" : "NO");

    return 0;
}

