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


vector<vector<bool>> states;

void recurse(int st, vector<bool>& v, bool val){
    if(st >= 9){
        states.push_back(v);
        return;
    }
    v.push_back(val);
    recurse(st + 1, v, 0);
    recurse(st + 1, v, 1);
}


int solve(){
    int n, m, x;
    cin>>n>>m;

    /// if there exists a sub matrix of size 4x4, not possible
    if(n >= 4 && m >= 4){
        rep(i, 1, n){
            rep(j, 1, m){
                cin>>x;
            }
        }
        return -1;
    }

    /// either n or m is less than 4, just check 2x2 sub-matrices
    bool a[n + 1][m + 1];
    char ch;
    rep(i, 1, n){
        rep(j, 1, m){
            cin>>ch;
            a[i][j] = (ch == '1');
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
            if((a[i][0] + a[i][1])&1) c1++;
        }
        for(int i = 2; i <= n; i += 2){
            if((a[i][0] + a[i][1])&1);
            else c1++;
        }


        int c2 = 0;
        /// odd-even
        for(int i = 2; i <= n; i += 2){
            if((a[i][0] + a[i][1])&1) c2++;
        }
        for(int i = 1; i <= n; i += 2){
            if((a[i][0] + a[i][1])&1);
            else c2++;
        }

        return min(c1, c2);
    }

    if(n == 2){
        /// 2 cases only, rows are alternatively even-odd
        int c1 = 0;
        /// even-odd
        for(int i = 1; i <= m; i += 2){
            if((a[0][i] + a[1][i])&1) c1++;
        }
        for(int i = 2; i <= m; i += 2){
            if((a[0][i] + a[1][i])&1);
            else c1++;
        }


        int c2 = 0;
        /// odd-even
        for(int i = 2; i <= m; i += 2){
            if((a[0][i] + a[1][i])&1) c2++;
        }
        for(int i = 1; i <= m; i += 2){
            if((a[0][i] + a[1][i])&1);
            else c2++;
        }

        return min(c1, c2);
    }

    // return 0;
    /// last case, 3x3 matrix
    /// brute force all 3x3 matrices, 2e9, then match!, 18e9 time complexity
    int mn = INT_MAX;

    vector<bool> v;
    recurse(0, v, 0);
    v.clear();
    recurse(0, v, 1);
    int cnt = 0;

    /// now check if state is correct and parity count
    for(auto i: states[100]) cout<<i<<" ";

    bool board[4][4];
    for(auto s: states){
        fr(i, 9) board[i/3 + 1][i%3 + 1] = s[i];

        bool f = true;
        if((s[0] + s[1] + s[3] + s[4])%2 == 0) f = false;
        if((s[1] + s[2] + s[4] + s[5])%2 == 0) f = false;
        if((s[3] + s[4] + s[6] + s[7])%2 == 0) f = false;
        if((s[4] + s[5] + s[7] + s[8])%2 == 0) f = false;

        cnt = 0;
        if(f){
            /// check par diff
            rep(i, 1, n){
                rep(j, 1, m){
                    if(board[i][j] != a[i][j]) cnt++;
                }
            }
            mn = min(cnt, mn);
        }
    }

    return (mn == INT_MAX ? -1 : mn);



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

