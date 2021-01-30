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

int ZFunc(string s1, string s2, int m){
    int n = 3*m + 1;
    vector<int> z(n, 0);
    string s = s1 + "@" + s2 + s2;
    int l, r;
    l=0, r=0;

    rep(i, 1, n-1){
        if(i <= r){
            z[i] = min(z[i-l], r-i+1);
        }
        while(z[i]+i < n && s[z[i]] == s[z[i]+i]) ++z[i];
        if(z[i]+i-1 > r){
            r = z[i]+i-1;
            l = i;
        }
    }

    int ind = m+1;
    int max_ = 0;
    rep(i, m, n-1){
        if(z[i] == m){
            return i -m -1;
        }
    }
    return -1;  /// order is incorrect
}

int main(){
    int n;
    cin>>n;
    vector<string> v(n);
    fr(i, n) cin>>v[i];
    int m = v[0].size();

    /// pre-check, if all strings have same character count or not
    string t = v[0];
    sort(t.begin(), t.end());
    for(auto it: v){
        string z = it;
        sort(z.begin(), z.end());
        if(z != t){
            cout<<-1;
            return 0;
        }
    }

    /// fix each string as the resulting string, then using Z-array, find ops required for each other string
    /// O(n^2) approach
    int cnt = INT_MAX;

    int temp;
    fr(i, n){
        temp = 0;
        fr(j, n){
            int z_ = ZFunc(v[i], v[j], m);
            if(z_ == -1) {
                cout<<-1;
                return 0;
            }
            temp += z_;
        }
        cnt = min(temp, cnt);
    }

    cout<<cnt;

    return 0;
}
