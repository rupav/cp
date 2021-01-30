#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a) * (a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;

const int N = 205;
int a[N], L[N][2], R[N][2];


int profit(int n){
    rep(i, 0, n + 1) L[i][0] = L[i][1] = R[i][0] = R[i][1] = 0;
    rep(i, 1, n){
        L[i][0] += L[i - 1][0] + (a[i] == 0);
        L[i][1] += L[i - 1][1] + (a[i] == 1);
    }
    repn(i, n, 1){
        R[i][0] += R[i + 1][0] + (a[i] == 0);
        R[i][1] += R[i + 1][1] + (a[i] == 1);
    }

    int sm = 0;
    rep(i, 1, n){
        if(a[i] == 0){
            sm += R[i][1];
        }
    }

    return sm;
}



void solve(){
    int n, k;
    cin>>n>>k;
    string s, t;
    cin>>s>>t;
    fr(i, n) {
        if(s[i] == t[0]) a[i+1] = 0;
        else if(s[i] == t[1]) a[i+1] = 1;
        else a[i+1] = -1;
    }

    int cnt = 0;
    if(t[0] == t[1]){
        cnt = 0;
        fr(i, n){
            if(a[i+1] != -1) cnt++;
        }
        int z = min(n, cnt + k);
        cout<<(z * (z - 1))/2<<endl;
        return;
    }

    int dp[n + 1] = {0};
    dp[0] = profit(n);

    int mx[4] = {0};
    rep(z, 1, n){
        /// replace 1st -1 with 0;
        int j = 0;
        rep(i, 1, n) {
            if(a[i] == -1){
                a[i] = 0;
                j = i;
                break;
            }
        }
        mx[0] = profit(n);
        a[j] = -1;


        /// replace 1st 1 with 0
        j = 0;
        rep(i, 1, n){
            if(a[i] == 1){
                a[i] = 0;
                j = i;
                break;
            }
        }
        mx[1] = profit(n);
        a[j] = 1;

        /// replace last -1  with 1
        j = 0;
        repn(i, n, 1){
            if(a[i] == -1){
                a[i] = 1;
                j = i;
                break;
            }
        }
        mx[2] = profit(n);
        a[j] = -1;

        /// replace last 0 with 1
        j = 0;
        repn(i, n, 1){
            if(a[i] == 0){
                a[i] = 1;
                j = i;
                break;
            }
        }
        mx[3] = profit(n);
        a[j] = 0;


        int mx_ = *max_element(mx, mx + 4);
        if(mx[0] == mx_){

            rep(i, 1, n) {
                if(a[i] == -1){
                    a[i] = 0;
                    j = i;
                    break;
                }
            }

        } else if (mx[1] == mx_) {

            rep(i, 1, n){
                if(a[i] == 1){
                    a[i] = 0;
                    j = i;
                    break;
                }
            }


        } else if (mx[2] == mx_) {

            repn(i, n, 1){
                if(a[i] == -1){
                    a[i] = 1;
                    j = i;
                    break;
                }
            }

        } else {

            repn(i, n, 1){
                if(a[i] == 0){
                    a[i] = 1;
                    j = i;
                    break;
                }
            }

        }

        dp[z] = mx_;
    }

    cout<<*max_element(dp, dp + k + 1)<<endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    //  cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

