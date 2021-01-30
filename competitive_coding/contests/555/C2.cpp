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

void solve(){
    int n;
    cin>>n;
    int a[n];
    fr(i, n) cin>>a[i];

    string res;
    int i(0), j(n-1);
    int min_ = 0;

    while(i <= j){
        if(min(a[i], a[j]) > min_){

            if(i != j && a[i] == a[j]){
                /// check for left and right seperately!
                int l(i), r(j);
                int temp = min_;
                while(l < j && a[l] > min_){
                    min_ = a[l];
                    l++;
                }

                min_ = temp;
                while(r > i && a[r] > min_){
                    min_ = a[r];
                    r--;
                }

                if(l - i > j - r){
                    int k = i;
                    while(k<l) k++, res += 'L';
                } else {
                    int k = j;
                    while(k>r) k--, res += 'R';
                }
                break;
            }

            min_ = min(a[i], a[j]);
            if(a[i] < a[j]) i++, res += 'L';
            else j--, res += 'R';
        } else if (min_ < max(a[i], a[j])){
            min_ = max(a[i], a[j]);
            if(a[i] < a[j]) j--, res += 'R';
            else i++, res += 'L';
        } else {
            break;
        }
    }
    cout<<res.size()<<endl;
    cout<<res;

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


