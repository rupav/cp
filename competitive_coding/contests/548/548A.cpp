#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;


int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int i=1;
    ll ans = 0;
    for(auto c: s){
        if((c-'0')%2==0){
            ans += i;
        }
        i++;
    }cout<<ans;
    return 0;
}

