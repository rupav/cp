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
    string s, t;
    cin>>s>>t;
    string ss = s;
    if(s == t){
        cout<<s;
        return 0;
    }
    int i=10;
    while(i--){
        next_permutation(s.begin(), s.end());
        bool a = next_permutation(ss.begin(), ss.end());
        cout<<ss<<endl;
        if(a && (ss == t))
            cout<<s;
        else{
            next_permutation(ss.begin(), ss.end());
        }

    }
    return 0;
}

