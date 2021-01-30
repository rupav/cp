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


int solve(){
    int n, m, x;
    cin>>n>>m;

    char ch;
    /// if there exists a sub matrix of size 4x4, not possible
    if(n >= 4 && m >= 4){
        rep(i, 1, n){
            rep(j, 1, m){
                cin>>ch;
            }
        }
        return -1;
    }


    /// either n or m is less than 4, just check 2x2 sub-matrices
    int a[n + 1][m + 1];

    string s;
    rep(i, 1, n){
        cin>>s;
        fr(j, m){
            a[i][j + 1] = (int)(s[j] == '1');
        }
    }

    if(n == 1 || m == 1){
        return 0;
    }

    /// n x 2 or n x 3 case left only!
    if(m == 2){
        /// 2 cases only, rows are alternatively even-odd
        int c1 = 0;
        /// even-odd
        for(int i = 1; i <= n; i += 2){
            if((a[i][1] + a[i][2])&1) c1++;
        }
        for(int i = 2; i <= n; i += 2){
            if((a[i][1] + a[i][2])&1);
            else c1++;
        }


        int c2 = 0;
        /// odd-even
        for(int i = 2; i <= n; i += 2){
            if((a[i][1] + a[i][2])&1) c2++;
        }
        for(int i = 1; i <= n; i += 2){
            if((a[i][1] + a[i][2])&1);
            else c2++;
        }

        return min(c1, c2);
    }

    if(n == 2){
        /// 2 cases only, rows are alternatively even-odd
        int c1 = 0;
        /// even-odd
        for(int i = 1; i <= m; i += 2){
            if((a[1][i] + a[2][i])&1) c1++;
        }
        for(int i = 2; i <= m; i += 2){
            if((a[1][i] + a[2][i])&1);
            else c1++;
        }


        int c2 = 0;
        /// odd-even
        for(int i = 2; i <= m; i += 2){
            if((a[1][i] + a[2][i])&1) c2++;
        }
        for(int i = 1; i <= m; i += 2){
            if((a[1][i] + a[2][i])&1);
            else c2++;
        }

        return min(c1, c2);
    }

    /// 3xm or nx3 case remaining

    /// 4 case, for 2 pairs of rows/columns


    bool f[2];
    int mn;
    if(m == 3){
        mn = INT_MAX;
        int c[4] = {0};   /// odd-odd, odd-even, even-odd, even-even: at odd positions
        for(int i = 1; i <= n; i += 2){
            f[0] = (a[i][1] + a[i][2])&1;
            f[1] = (a[i][2] + a[i][3])&1;

            c[0] += 1;
            c[1] += 1;
            c[2] += 1;
            c[3] += 1;

            c[0] -= (f[0] && f[1]);
            c[1] -= (f[0] && !f[1]);
            c[2] -= (!f[0] && f[1]);
            c[3] -= (!f[0] && !f[1]);
        }

        for(int i = 2; i <= n; i += 2){
            f[0] = (a[i][1] + a[i][2])&1;
            f[1] = (a[i][2] + a[i][3])&1;

            c[0] += 1;
            c[1] += 1;
            c[2] += 1;
            c[3] += 1;

            c[0] -= (!f[0] && !f[1]);
            c[1] -= (!f[0] && f[1]);
            c[2] -= (f[0] && !f[1]);
            c[3] -= (f[0] && f[1]);
        }

        mn = min({c[0], c[1], c[2], c[3], mn});


        c[4] = {0};   /// reverse of this odd-odd, odd-even, even-odd, even-even: at odd positions
        fr(k, 4) c[k] = 0;
        for(int i = 2; i <= n; i += 2){
            f[0] = (a[i][1] + a[i][2])&1;
            f[1] = (a[i][2] + a[i][3])&1;

            c[0] += 1;
            c[1] += 1;
            c[2] += 1;
            c[3] += 1;

            c[0] -= (f[0] && f[1]);
            c[1] -= (f[0] && !f[1]);
            c[2] -= (!f[0] && f[1]);
            c[3] -= (!f[0] && !f[1]);
        }

        for(int i = 1; i <= n; i += 2){
            f[0] = (a[i][1] + a[i][2])&1;
            f[1] = (a[i][2] + a[i][3])&1;

            c[0] += 1;
            c[1] += 1;
            c[2] += 1;
            c[3] += 1;

            c[0] -= (!f[0] && !f[1]);
            c[1] -= (!f[0] && f[1]);
            c[2] -= (f[0] && !f[1]);
            c[3] -= (f[0] && f[1]);
        }

        return min({c[0], c[1], c[2], c[3], mn});

    }

    if(n == 3){
        mn = INT_MAX;
        int c[4] = {0};   /// odd-odd, odd-even, even-odd, even-even: at odd positions
        for(int i = 1; i <= m; i += 2){
            f[0] = (a[1][i] + a[2][i])&1;
            f[1] = (a[2][i] + a[3][i])&1;

            c[0] += 1;
            c[1] += 1;
            c[2] += 1;
            c[3] += 1;

            c[0] -= (f[0] && f[1]);
            c[1] -= (f[0] && !f[1]);
            c[2] -= (!f[0] && f[1]);
            c[3] -= (!f[0] && !f[1]);
        }

        for(int i = 2; i <= m; i += 2){
            f[0] = (a[1][i] + a[2][i])&1;
            f[1] = (a[2][i] + a[3][i])&1;

            c[0] += 1;
            c[1] += 1;
            c[2] += 1;
            c[3] += 1;

            c[0] -= (!f[0] && !f[1]);
            c[1] -= (!f[0] && f[1]);
            c[2] -= (f[0] && !f[1]);
            c[3] -= (f[0] && f[1]);
        }

        mn = min({c[0], c[1], c[2], c[3], mn});


        c[4] = {0};   /// reverse of this odd-odd, odd-even, even-odd, even-even: at odd positions
        fr(k, 4) c[k] = 0;
        for(int i = 2; i <= m; i += 2){
            f[0] = (a[1][i] + a[2][i])&1;
            f[1] = (a[2][i] + a[3][i])&1;

            c[0] += 1;
            c[1] += 1;
            c[2] += 1;
            c[3] += 1;

            c[0] -= (f[0] && f[1]);
            c[1] -= (f[0] && !f[1]);
            c[2] -= (!f[0] && f[1]);
            c[3] -= (!f[0] && !f[1]);
        }

        for(int i = 1; i <= m; i += 2){
            f[0] = (a[1][i] + a[2][i])&1;
            f[1] = (a[2][i] + a[3][i])&1;

            c[0] += 1;
            c[1] += 1;
            c[2] += 1;
            c[3] += 1;

            c[0] -= (!f[0] && !f[1]);
            c[1] -= (!f[0] && f[1]);
            c[2] -= (f[0] && !f[1]);
            c[3] -= (f[0] && f[1]);
        }


        return min({c[0], c[1], c[2], c[3], mn});

    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    //  cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }

    return 0;
}


