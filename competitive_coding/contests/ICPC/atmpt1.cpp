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

vector<int> masks;
vector<int> mp;
vector<pii> ans;

int conv(char x){
    return (int)(x - 'a');
}

void submasks(int m, int pen){
    if(mp[m] != -1) return; /// no need to find submasks of already used pen
    for(int s=m; s!=0; s = (s-1)&m){
        mp[s] = pen;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--){

        int n, k;
        string s, p;
        cin>>n>>k;
        cin>>s;
        masks.resize(k+1);
        rep(i, 1, k){
            cin>>p;
            // sort(p.begin(), p.end());
            int p_mask = 0;     /// for each pen, create mask
            for(auto it: p){
                int pos = 1<<conv(it);
                p_mask |= pos;
            }
            masks[i] = p_mask;
        }

        /// create submasks, O(3^20 - 1) for each mask, optimize by stopping iterations, if submasks is already filled.
        mp.assign((1<<20 + 1), -1);
        rep(i, 1, k){
            submasks(masks[i], i);
        }

        /// adding character 1 by one, find if its already present in masks
        int temp_mask = 0;

        int i = 0;
        ans.clear();
        for(auto it: s){
            temp_mask |= (1<<conv(it));
            if(mp[temp_mask] != -1){
                /// continue
            } else {
                /// change the temp_mask
                /// remove older set bit
                temp_mask ^= (1<<conv(it));
                ans.push_back({mp[temp_mask], i-1});
                temp_mask = 0;
                temp_mask |= (1<<conv(it));
            }
            i++;
        }
        ans.push_back({mp[temp_mask], n-1});

        /// now just assign the ans
        int si = 0;
        for(auto it: ans){
            /// create submasks, till these end indices, and find the pen
            int ei = it.second;
            int pen = it.first;
            rep(i, si, ei){
                cout<<pen<<" ";
            }
            si = ei+1;
        }
        cout<<endl;
    }

    return 0;
}
