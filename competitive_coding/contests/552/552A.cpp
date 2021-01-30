#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;


int main(){
    int a[4];
    int maxE = 0;
    fr(i, 4){
        cin>>a[i];
        maxE = max(a[i], maxE);
    }
    fr(i, 4){
        if(maxE - a[i])
            cout<<maxE-a[i]<<" ";
    }
    return 0;
}

