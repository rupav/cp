#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

int conv(char x){
    return (int)(x - '0');
}

char deconv(int x){
    return (char)(x + '0');
}

int main(){
    int n;
    cin>>n;
    string s, t;
    cin>>s;
    int f[10];
    rep(i, 1, 9) cin>>f[i];

    fr(i, n){
        if( conv(s[i]) < f[conv(s[i])] ){
            t += deconv(f[conv(s[i])]);
            int j = i+1;
            while(j < n && conv(s[j]) <= f[conv(s[j])]) {
                t += deconv(f[conv(s[j])]);
                j++;
            }
            rep(k, j, n-1) t += s[k];
            break;
        }
        t += s[i];
    }

    cout<<t;

    return 0;
}

