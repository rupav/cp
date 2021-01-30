#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;


void solve(){
    int n, k;
    cin>>n>>k;
    int mat[n+1][n+1];

    int st = 1;
    rep(i, 1, n){
        rep(j, i, n){
            mat[i][j] = j - i + 1;
        }
        st = mat[i][n] + 1;
        rep(j, 1, i - 1){
            mat[i][j] = st++;
        }
    }

    int sp[n+1];    /// swapping pair
    rep(i, 1, n) sp[i] = i;
    bool isMirror = false;

    int sum;
    if(n&1){
        /// odd
        sum = (n*(n+1))/2;
        if(k%n != 0 && k != sum){
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }

        if(k%n == 0){
            sp[1] = k/n;
            sp[k/n] = 1;
        } else {
            isMirror = true;
        }
    } else {
        /// even
        int m = n/2;
        sum = (m*(m+1))/2;  /// distinct n/2 elements
        int mx = 0;
        repn(i, n, n/2 + 1) mx += i;    /// max limit, e.g case 6 34
        if(k%n != 0 && ((k&1) || k < 2*sum || k > 2*mx)){
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }

        if(k%n == 0){
            sp[1] = k/n;
            sp[k/n] = 1;
        } else {
            isMirror = true;
            m = k/2;
            int sz = 0;
            int temp;
            int suff[n+1] = {0};    ///max sum of length i
            suff[1] = n;


            repn(i, n-1, 1){
                suff[n - i + 1] = suff[n - i] + i;
            }

            /// finding n/2 distinct elements, such that sum of those is m. fixing 1 at a time
            vector<int> el;
            rep(i, 1, n){
                /// check if i is included
                if(sz == n/2 - 1) break;
                if(suff[n/2 - sz - 1] >= m - i){
                    sz++;
                    el.push_back(i);
                    m -= i;
                }
            }
            el.push_back(m);

            /// mapping in lower diagonal
            /// dont swap if already present in the lower diagonal
            set<int> s;
            rep(i, 1, n/2) s.insert(2*i);

            for(auto it: el){
                if((it&1) == 0){
                    s.erase(it);
                }
            }

            for(auto it: el){
                if(it&1){
                    sp[it] = *s.begin();
                    sp[*s.begin()] = it;
                    s.erase(s.begin());
                }
            }

        }
    }

    rep(i, 1, n){
        rep(j, 1, n){
            mat[i][j] = sp[mat[i][j]];
        }
    }

    int tmp;
    if(isMirror){
        rep(i, 1, n){
            rep(j, 1, n/2){
                tmp = mat[i][j];
                mat[i][j] = mat[i][n - j + 1];
                mat[i][n - j + 1] = tmp;
            }
        }
    }

    cout<<"POSSIBLE"<<endl;
    rep(i, 1, n){
        rep(j, 1, n){
            cout<<mat[i][j];
            if(j != n) cout<<" ";
        }
        cout<<endl;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    rep(i, 1, t){
        cout<<"Case #"<<i<<": ";
        solve();
    }

    return 0;
}


