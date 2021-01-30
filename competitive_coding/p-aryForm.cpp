#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

vector<int> p_ary(int n, int p){
    int k = sizeof(int)*8;
    vector<int> v;
    for(int i=0; i<k; i++){
        v.push_back(n%p);
        n /= p;
    }
    return v;
}

int main(){
    int n, p;
    cin>>n>>p;
    vector<int> v = p_ary(n, p);
    for(auto c: v){
        cout<<c<<" ";
    }
    return 0;
}

