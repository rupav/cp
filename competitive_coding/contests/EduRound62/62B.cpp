#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;


int main(){
    int t;
    cin>>t;
    int n;
    string s;
    int ans;
    while(t--){
        cin>>n;
        cin>>s;
        int ans[2] = {0};
        for(auto c: s){
            if(c == '<'){
                ans[0]++;
            } else {
                break;
            }
        }
        for(int i=n-1; i>=0; i--){
            if(s[i] == '>'){
                ans[1] ++;
            } else {
                break;
            }
        }
        cout<<min(ans[0], ans[1])<<endl;
    }
    return 0;
}

