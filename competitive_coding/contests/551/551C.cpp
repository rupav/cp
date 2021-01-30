#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;


int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(n&1 || (s[0] == ')')){
        cout<<":(";
        return 0;
    }
    /// make s[1... n-2] as perfect!
    int count[2] = {0};
    rep(i, 1, n-2){
        if(count[0] > count[1]){
            cout<<":(";
            return 0;
        }
        if(s[i] == '?'){
            if(count[1] > count[0]){
                s[i] = ')';
                count[0]++;
            } else {
                s[i] = '(';
                count[1]++;
            }
        } else {
            count[s[i] == '(']++;
        }
    }
    if(count[0] != count[1]){
        cout<<":(";
        return 0;
    }
    if(s[n-1] == ')' || s[n-1] == '?'){
        s[0] = '(';
        s[n-1] = ')';
        cout<<s;
    } else {
        cout<<":(";
    }
    return 0;
}

