#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

int n;
const int N = 3e4+5;
int bit[N];

void update(int i, int val){
    for(; i<=n; i+=i&(-i)) bit[i] += val;
}

int query(int i){
    int sum = 0;
    for(; i>0; i-=i&(-i)) sum += bit[i];
    return sum;
}

int main(){
    /// inversion count problem
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        rep(i, 0, n) bit[i] = 0;
        vector<string> a(n), b(n);
        map<string, int> mp;
        fr(i, n){
            cin>>a[i];
        }
        fr(i, n){
            cin>>b[i];
            mp[b[i]] = i+1;
        }
        int ans = 0;
        for(vector<string>::reverse_iterator rit = a.rbegin(); rit != a.rend(); ++rit){
            int pos = mp[*rit];
            /// find count of elements in the BIT, lower than this pos
            ans += query(pos-1);
            update(pos, 1);
        }
        cout<<ans<<endl;
    }
}
