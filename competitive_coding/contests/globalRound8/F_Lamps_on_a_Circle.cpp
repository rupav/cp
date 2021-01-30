#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a) * (a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;


void solve(){
    int n, st;
    cin>>n;
    int a[n] = {0};
    deque<pii> v, segs;
    while(true){
        v.clear();
        segs.clear();
        vector<int> query;
        int i = 0, j = 0;
        while(i < n){
            if(a[i] == 0){
                j = i + 1;
                while(j < n && a[j] == 0) j++;
                v.push_back({i, j - i});
                i = j;
                continue;
            }
            i++;
        }
        if(v.size() != 1 && v.front().first == 0){
            int len = v.front().second + v.back().second;
            v.pop_front();
            int st = v.back().first;
            v.pop_back();
            v.push_back({st, len});
        }

        for(auto it: v){
            if(it.second > 3) segs.push_back(it);
        }

        for(auto &it: segs){
            int l = it.second;
            int en = it.first + l - 1;
            for(int i = it.first; i <= en; i += 2){
                a[i%n] = 1;
                query.push_back(i%n + 1);
            }
        }

        if(query.size()){
            cout<<query.size()<<" ";
            for(auto it: query) cout<<it<<" ";
            cout<<endl;
            cin>>st;
            st--;
            int m = query.size();
            rep(i, st, st + m - 1){
                a[i%n] = 0;
            }
        } else {
            cout<<0<<endl;
            return;
        }

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

