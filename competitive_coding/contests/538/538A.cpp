#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;


int main(){
    int x, y, z;
    int a, b, c;
    cin>>x>>y>>z>>a>>b>>c;
    a -= x;
    if(a<0){
        cout<<"NO";
    } else {
        int temp = b+a;
        temp -= y;
        if(temp<0){
            cout<<"NO";
        } else {
            if(temp+c < z){
                cout<<"NO";
            } else {
                cout<<"YES";
            }
        }
    }
    return 0;
}
