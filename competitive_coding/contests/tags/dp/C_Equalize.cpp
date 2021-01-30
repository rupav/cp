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

int main(){
    int n;
    cin>>n;
    string s, t;
    cin>>s;
    cin>>t;
    int cnt=0; /// swap only when consecutive elements needs to be swapped!
    int i=0;
    while(i<n-1){
        if(s.substr(i, 2) == "01" && t.substr(i, 2) == "10"){
            cnt++;
            i+=2;
            continue;
        }

        if(s.substr(i, 2) == "10" && t.substr(i, 2) == "01"){
            cnt++;
            i+=2;
            continue;
        }

        /// else change if requd
        if(s[i] != t[i]) cnt++;
        i++;
    }
    if(i == n-1){
        if(s[i] != t[i]) cnt++;
    }
    cout<<cnt;
}
