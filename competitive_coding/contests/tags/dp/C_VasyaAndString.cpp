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
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int> a[2];
    vector<int> pref[2];
    int i=0;
    while(i<n){
        int j = i+1;
        while(j<n && s[i] == s[j]) j++;
        a[s[i] == 'b'].push_back(j-i);
        i = j;
    }

    int temp = 0;
    for(auto it: a[0]){
        temp += it;
        pref[0].push_back(temp);
    }

    temp = 0;
    for(auto it: a[1]){
        temp += it;
        pref[1].push_back(temp);
    }

    return 0;
}
