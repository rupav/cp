#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;


int main(){
    stack<bool> ms;
    int c[4];
    fr(i, 4){
        cin>>c[i];
    }

    if(c[0] == 0 && c[3] == 0 && c[2]){
        cout<<0;
        return 0;
    }
    if(c[0] == c[3])
        cout<<1;
    else
        cout<<0;
    return 0;
}
