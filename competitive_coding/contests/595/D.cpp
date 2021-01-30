#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
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

vector<piii> v;

vector<int> points(201, 0);  /// stores just the count
vector<int> ans;
set<piii> s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin>>n>>k;
    v.resize(n+1);
    int x, y;
    rep(i, 1, n){
        cin>>x>>y;
        v.push_back(make_pair(x, make_pair(y, i)));
        rep(j, x, y){
            points[j]++;  /// storing end point of that
        }
        s.insert(make_pair(y, make_pair(x, i)));
    }

    sort(v.begin(), v.end());


    rep(i, 1, 200){
        /// check if point is good
        int temp_count = 0;
        bool check = false;

        if(points[i] > k){
            /// remove
            int z = points[i] - k;
            vector<piii> temp;
            for(auto it=s.rbegin(); it!=s.rend(); it++){
                y = it->first;
                x = it->second.first;
                int ind = it->second.second;
                if(i>=x && i<=y){
                    /// remove this
                    temp.push_back(*it);
                    ans.push_back(ind);
                    rep(j, i+1, y){
                        points[j]--;
                    }
                    z--;
                }
                if(!z) break;
            }
            for(auto it: temp){
                s.erase(it);
            }
        }
    }

    cout<<ans.size()<<endl;
    for(auto it: ans) cout<<it<<" ";

    return 0;
}

