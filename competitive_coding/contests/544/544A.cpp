#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

int encode(int h, int m){
    return h*60+m;
}

void decode(int t){
    int h = t/60;
    int m = t%60;
    if(h<=9){
        cout<<0<<h<<":";
    }else{
        cout<<h<<":";
    }
    if(m<=9){
        cout<<0<<m;
    }else{
        cout<<m;
    }
}

int main(){
    int h1, h2, m1, m2;
    string s, m;
    cin>>s>>m;
    h1 = (int)(s[1]-'0')+(int)(s[0]-'0')*10;
    h2 = (int)(m[1]-'0')+(int)(m[0]-'0')*10;
    m1 = (int)(s[4]-'0')+(int)(s[3]-'0')*10;
    m2 = (int)(m[4]-'0')+(int)(m[3]-'0')*10;
    /// cin>>h1>>m1>>h2>>m2;

    int a = encode(h1, m1);
    int b = encode(h2, m2);
    decode((a+b)/2);
    return 0;
}
