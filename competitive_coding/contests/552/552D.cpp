#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;


int main(){
    int n, a, b;
    cin>>n>>b>>a;
    int s[n];
    fr(i, n) cin>>s[i];
    int ans = 0;
    int lim = a;
    fr(i, n){
        if(!a && !b){
            cout<<i;
            return 0;
        }
        if(s[i]){
            if(a!=lim){
                if(b){
                    b--;
                    a++;
                } else {
                    a--;
                }
            } else {
                if(a){
                    a--;
                } else {
                    b--;
                }
            }
        } else {
            if(a){
                a--;
            } else {
                b--;
            }
        }
    }
    cout<<n;
    return 0;
}

