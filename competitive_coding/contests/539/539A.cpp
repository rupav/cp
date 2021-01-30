#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;


int main(){
    int n, v;
    cin>>n>>v;
    int cost = min(n-1, v);
    int temp = 0;
    temp = cost;
    int i = 2;
    while(temp != n-1){
        cost += i;
        temp++;
        i++;
    }
    cout<<cost;
    return 0;
}
