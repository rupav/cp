#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;


int main(){
    int n, x, y;
    cin>>n>>x>>y;
    string s;
    cin>>s;
    int count = 0;

    int i=n-1;
    x -= y;
    x--;
    while(y){
        y--;
        if(s[i] == '1'){
            count++;
        }
        i--;
    }
    if(s[i--] == '0'){
        count++;
    }
    while(x){
        if(s[i] == '1')
            count++;
        x--;
        i--;
    }
    /*
    if(s[i] == '0')
        count++;
        */
    cout<<count;
    return 0;
}

