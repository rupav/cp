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
    int a[n];
    int m[2];
    m[0] = 101;
    m[1] = -1;
    fr(i, n){
        cin>>a[i];
        m[0] = min(m[0], a[i]);
        m[1] = max(m[1], a[i]);
    }

    int ans = 101;
    int prev = ans;
    int diff;
    rep(j, m[0], m[1]){
        bool flag = false;
        fr(i, n){
            if(abs(j - a[i])){
                diff = abs(j-a[i]);
                flag = true;
                break;
            }
        }
        if(!flag){
            cout<<0;
            return 0;
        } else {
            bool fl = false;
            fr(i, n){
                if(abs(j - a[i]) && (abs(j - a[i]) != diff)){
                    fl = true;
                    break;
                }
            }
            if(!fl)
                ans = min(diff, ans);
        }
    }

    if(ans != 101)
        cout<<ans;
    else
        cout<<-1;
    return 0;
}

