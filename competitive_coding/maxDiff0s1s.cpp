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

int kadane(int *arr, int n){
    int max_so_far = INT_MIN;
    int dp[n+1] = {0};  /// max sum ending at ith index
    rep(i, 1, n){
        dp[i] = max(dp[i-1] + arr[i-1], arr[i-1]);
        max_so_far = max(max_so_far, dp[i]);
    }
    return  max_so_far;
}

int maxDiff(int *arr, int n){
    fr(i, n) arr[i] = (arr[i] == 0) ? 1 : -1;
    /// now apply Kadane's algo, to find maximum sum subset array.
    int temp = kadane(arr, n);
    return temp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    string s;
    while(t--){
        cin>>s;
        int n = s.length();
        int arr[n];
        fr(i, n) arr[i] = (int)(s[i]-'0');
        cout<<maxDiff(arr, n)<<endl;
    }
    return 0;
}

