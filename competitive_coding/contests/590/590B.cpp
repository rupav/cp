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

vector<pii> cp;
vector<bool> isp;
vector<int> arr, mp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin>>n>>k;
    arr.resize(n);
    cp.resize(n);
    int x;
    fr(i, n){
        cin>>x;
        cp[i] = make_pair(x, i);
    }

    mp.resize(n);
    sort(cp.begin(), cp.end());
    int min_ = 0;
    int prev = cp[0].first;

    arr[cp[0].second] = min_;
    mp[min_] = prev;


    rep(i, 1, n-1){
        x = cp[i].second;
        if(prev != cp[i].first) min_++;
        prev = cp[i].first;
        arr[x] = min_;
        mp[min_] = prev;
    }

    for(auto it: arr) cout<<it<<" ";
    cout<<endl;

    isp.assign(n, false);
    queue<int> q;

    fr(i, n){
        int x, y;
        x = arr[i];
        if(q.size() >= k){
            /// check for existence
            if(!isp[x]){
                q.push(x);
                y = q.front();
                isp[y] = false;
                q.pop();
            }
        } else {
            if(!isp[x])
                q.push(x);
        }
        isp[x] = true;
    }

    int cnt = accumulate(isp.begin(), isp.end(), 0);

    stack<int> ans;
    while(!q.empty()){
        x = q.front();
        q.pop();
        ans.push(mp[x]);
    }

    cout<<cnt<<endl;

    while(!ans.empty() && cnt){
        cout<<ans.top()<<" ";
        ans.pop();
        cnt--;
    }

    return 0;
}

