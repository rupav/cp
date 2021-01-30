#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5+5;
ll a[N], L[N], R[N], cover[N];


void fill_(int n){
    stack<int> s;
    for(int i=1; i<=n; i++) L[i] = 0;
    for(int i=1; i<=n; i++) R[i] = n+1;

    for(int i=1; i<=n; i++){
        while(s.size() && a[s.top()] > a[i]) s.pop();
        if(s.size()) L[i] = s.top();  // rightmost index, s.top() s.t. a[s.top()] <= a[i]
        s.push(i);
    }

    while(s.size()) s.pop();

    for(int i=n; i>=1; i--){
        while(s.size() && a[s.top()] >= a[i]) s.pop();
        if(s.size()) R[i] = s.top();  // leftmost index, s.top() s.t. a[s.top()] < a[i]
        s.push(i);
    }
}

int main(){
    int n;
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    fill_(n);

    map<ll, ll> mp;  // for each no., storing its max cover
    for(int i=1; i<=n; i++){
        cover[i] = R[i] - L[i] - 1;
        mp[a[i]] = max(mp[a[i]], cover[i]);
    }

    map<ll, ll>::reverse_iterator rit = mp.rbegin();
    ll res[n];
    ll val = 1;
    while(val <=n && rit != mp.rend()){
        while(rit->second >= val){
            res[val++] = rit->first;
        }
        rit++;
    }

    for(int i=1; i<=n; i++) cout<<res[i]<<" ";

    return 0;
}
