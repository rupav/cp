#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

int solve(string &s, int n){
    stack<char> ms;
    fr(i, n){
        if(s[i] == '{')
            ms.push(s[i]);
        else{
            if(!ms.empty() && ms.top() == '{')
                ms.pop();
            else{
                ms.push(s[i]);
            }
        }
    }
    /// now stack will have }}}{{{ or {{{{ or }}}} formats left in the stack only.
    int ans = 0;
    while(!ms.empty() && ms.top() == '{'){
        ms.pop();
        ans++;
    }
    if(ms.empty())
        return ans/2;
    int temp = ms.empty() ? 0 : ms.size();
    ans = 2*ans + (temp-ans)/2;
    return ans;
}

int main(){
    string s;
    int n;
    int i=0;
    while(true){
        // cin.ignore();
        cin>>s;
        if(s[0] == '-')
            break;
        n = s.size();
        cout<<++i<<". "<<solve(s, n)<<endl;
    }
    return 0;
}
