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

int conv(char x){
    return int(x-'0');
}

void merge_(){
    string s;
    cin>>s;
    int n = s.size();
    vector<int> dig[2]; /// dig[1]: odd, dig[0]: even
    for(auto it: s) dig[conv(it)&1].push_back(conv(it));
    /// now merge!
    int x = conv(s[0]);
    int it[] = {0, 0};  /// iterators
    bool f = x&1;

    while(it[f] < dig[f].size()){
        while(it[!f] < dig[!f].size() && dig[!f][it[!f]] < dig[f][it[f]]){
            cout<<dig[!f][it[!f]];
            it[!f]++;
        }
        cout<<dig[f][it[f]];
        it[f]++;
    }
    while(it[!f] < dig[!f].size()){
        cout<<dig[!f][it[!f]];
        it[!f]++;
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        merge_();
        cout<<endl;
    }
    return 0;
}

