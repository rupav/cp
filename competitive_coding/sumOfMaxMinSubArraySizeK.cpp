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

vector<int> sumOfMaxMinSubArraySizeK(int *arr, int n, int k){
    vector<int> ans;
    deque<int> maxdq, mindq;
    fr(i, k){
        while(!maxdq.empty() && arr[i] >= arr[maxdq.back()]){
            maxdq.pop_back();
        }
        maxdq.push_back(i);
        while(!mindq.empty() && arr[i] <= arr[mindq.back()]){
            mindq.pop_back();
        }
        mindq.push_back(i);
    }

    rep(i, k, n-1){
        ans.push_back(arr[maxdq.front()] + arr[mindq.front()]);
        /// remove older elements
        while(!maxdq.empty() && maxdq.front() <= i-k){
            maxdq.pop_front();
        }
        while(!mindq.empty() && mindq.front() <= i-k){
            mindq.pop_front();
        }

        /// remove useless elements
        while(!maxdq.empty() && arr[i] >= arr[maxdq.back()]){
            maxdq.pop_back();
        }

        while(!mindq.empty() && arr[i] <= arr[mindq.back()]){
            mindq.pop_back();
        }

        maxdq.push_back(i);
        mindq.push_back(i);
    }

    ans.push_back(arr[maxdq.front()] + arr[mindq.front()]);

    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int arr[n];
        fr(i, n) cin>>arr[i];
        vector<int> ans = sumOfMaxMinSubArraySizeK(arr, n, k);
        for(auto it: ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    return 0;
}

