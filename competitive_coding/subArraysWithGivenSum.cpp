/// return all pair of indices for which sub-arrays sum is equal to given sum.

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

vector<pii> windowMethod(int *arr, int n, ll sum){
    /// works only on non-negative integers!
    int i, j;
    i = j = 0;
    ll temp_sum = 1ll*arr[0];
    vector<pii> ans;
    while(j<n){
        if(temp_sum == sum){
            ans.push_back(make_pair(i+1, j+1));
            if(i == j){
                j++;
                if(j == n) break;
                temp_sum += 1ll*arr[j];
            } else {
                temp_sum -= 1ll*arr[i];
                i++;
            }
        } else if (temp_sum < sum) {
            j += 1;
            if(j == n) break;
            temp_sum += 1ll*arr[j];
        } else {
            temp_sum -= 1ll*arr[i];
            i += 1;
        }
    }
    // if(ans.empty()) ans.push_back(make_pair(-1, -1));
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll sum;
    int n;
    cin>>n;
    int arr[n];
    fr(i, n) cin>>arr[i];
    cin>>sum;

    vector<pii> v = windowMethod(arr, n, sum);
    for(auto it: v) cout<<it.first<<" "<<it.second<<endl;

    return 0;
}

