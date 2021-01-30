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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int x;
    int seq[] = {4,8,15,16,23,42};
    int next[6] = {0};
    map<int, int> mp;
    map<int, int> weight;

    int i = 0;
    for(auto x: seq){
        mp[x] = i;
        weight[x] = i+1;
        i++;
    }

    ll count = 0;
    fr(i, n){
        cin>>x;
        if(x == 4) next[0]++;
        else {
            if(next[mp[x] - 1] == 0){
                count++;
            } else {
                next[mp[x] - 1]--;
                next[mp[x]] ++;
            }
        }
    }

    next[5] = 0;

    for(auto it: weight){
        count += 1ll*(it.second)*next[mp[it.first]];
    }

    cout<<count;

    return 0;
}

