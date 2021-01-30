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
    string s;
    cin>>s;
    int n = s.size();
    int k;
    cin>>k;

    string res = "";

    int i = 0;
    while(i < n){
        int j = i;
        while(j < n && s[j] == s[i]) j++;
        if(j - i != k){
            j = i;
            while(j < n && s[j] == s[i]){
                res += s[j++];
            }
        }
        i = j;
    }

    cout<<res;

    return 0;
}
