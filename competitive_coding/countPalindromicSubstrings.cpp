#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

int countPalindromicSubstrings(string s, int n){
    bool P[n][n];
    fr(i, n)
        fr(j, n)
            P[i][j] = false;
    fr(i, n)
        P[i][i] = true;
    int count = 0;
    for(int i=n-2; i>=0; i--){
        for(int j=i+1; j<n; j++){
            if(j-i+1 == 2){
                if(s[i] == s[j])
                    P[i][j] = true;
                else
                    P[i][j] = false;
            } else {
                if(s[i] == s[j] && P[i+1][j-1])
                    P[i][j] = true;
                else
                    P[i][j] = false;
            }
            if(P[i][j] == true){
                count++;
            }
        }
    }
    return count;
}

int main(){
    return 0;
}

