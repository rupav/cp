/// better/intended approach using sets and binary search
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

set<int> s[26];

int conv(char x){
    return (int)(x - 'a');
}

int main(){
    string t;
    cin>>t;
    int n, q;
    n = t.size();
    int arr[n];
    fr(i, n) arr[i] = conv(t[i]);

    fr(i, n){
        /// initialize
        s[arr[i]].insert(i);
    }

    cin>>q;
    while(q--){
        int t;
        cin>>t;
        if(t == 1){
            int x;
            char y;
            cin>>x>>y;
            x--;
            s[arr[x]].erase(x);
            s[conv(y)].insert(x);
            arr[x] = conv(y);
        } else {
            int x, y;
            cin>>x>>y;
            x--;
            y--;
            int cnt = 0;
            fr(i, 26){
                auto it = s[i].lower_bound(x);
                if(it != s[i].end() && (*it <= y)) cnt++;  /// yes its present!
            }
            cout<<cnt<<endl;
        }
    }


    return 0;
}
