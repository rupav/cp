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

ll ans[200010];
ll arr[200010];
ll p_sum[200010];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin>>q;
    int n, k;
    while(q--){
        cin>>n>>k;
        p_sum[0] = 0;
        fr(i, n){
            cin>>arr[i];
            p_sum[i+1] = (p_sum[i]%2 + arr[i]%2)%2;  /// 1-based indexing
        }
        bool flag = true;

        int it = 0;
        rep(i, 1, n-1){
            if(k == 1) break;
            if(p_sum[i]%2 == flag){
                k--;
                flag = !flag;
                ans[it++] = i;
            }
        }
        if(k == 1 && p_sum[n]%2 == flag){
            ans[it++] = n;
            cout<<"YES"<<endl;
            fr(i, it) cout<<ans[i]<<" ";
            cout<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }

    return 0;
}

