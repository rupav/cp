#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;


int main(){
    int n, k;
    cin>>n>>k;
    ll count = 1;

    count += max(0, (n-1))*3ll + 2ll + min(k-1, n-k);
    cout<<count<<endl;

    return 0;
}

