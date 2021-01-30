#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(i, n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)

int decode(char x){
    return x - '0';
}

ll solve(string s){
    int n = s.length();
    int *z = new int[n];
    /// pre-calculate number of zeroes before 1 at ith position.
    int len = (s[0] == '0');
    z[0] = 0;

    rep(i, 1, n-1){
        if(s[i] == '0'){
            z[i] = len;
            len++;
        } else {
            z[i] = len;
            len = 0;
        }
    }

    ll ans = 0;
    fr(i, n){
        if(s[i] == '1'){
            int curr = 1;
            ans++;
            rep(j, i+1, min(i+20, n)-1){
                curr = 2*curr + (s[j] == '1');
                if(z[i] + j - i + 1 >= curr) ans++;
                else break;  /// not possible for next too
            }
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    string s;
    while(t--){
        cin>>s;
        cout<<solve(s)<<endl;
    }
    return 0;
}
