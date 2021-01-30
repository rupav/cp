#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

void print(bool flag){
    if(flag)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}

int main(){
    int t;
    cin>>t;
    int n;
    string s;
    while(t--){
        cin>>n;
        cin>>s;
        if(n<11){
            print(false);
        } else {
            int i = 0;
            for(auto c: s){
                i++;
                if(c == '8'){
                    break;
                }
            }
            if(n-i >= 10){
                print(true);
            } else {
                print(false);
            }
        }
    }
    return 0;
}

