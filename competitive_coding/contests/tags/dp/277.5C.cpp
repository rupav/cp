/// https://codeforces.com/problemset/problem/489/C
#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

void solve(int m, int s){
    if(m == 1 && s == 0){
        cout<<"0 0";
        return;
    }
    if(s >= 1 && s <= 9*m){

        vector<int> res(m+1);
        rep(i, 1, m-1){
            if(i != 1){
                // check for 0
                if(9*(m-i) >= s) {
                    res[i] = 0;
                    cout<<res[i];
                    continue;
                }
            }
            rep(j, 1, 9){
                if(9*(m-i) >= s - j){
                    res[i] = j;
                    s -= j;
                    break;
                }
            }
            cout<<res[i];
        }
        res[m] = s;
        cout<<res[m]<<" ";

        reverse(res.begin()+1, res.end());
        if(res[m] == 1){
            for(int i=1; i<m; i++){
                if(res[i] < 9){
                    // swap
                    res[i] += 1;
                    res[m] = 0;
                    break;
                }
            }
        }

        for(int i=1; i<=m; i++) cout<<res[i];

    } else {
        cout<<"-1 -1";
        return;
    }
}

int main(){
    int m, s;
    cin>>m>>s;
    solve(m, s);
}

