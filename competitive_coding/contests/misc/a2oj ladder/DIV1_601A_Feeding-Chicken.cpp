#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;

string chickens = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm0123456789";

void solve(){
    int n, m, k;
    cin>>n>>m>>k;
    char mat[n][m];
    vector<int> field;
    bool dir = true;
    int r = 0;  /// total rice fields
    fr(i, n){
        fr(j, m){
            cin>>mat[i][j];
            r += (mat[i][j] == 'R');
        }
        if(dir){
            fr(j, m) field.push_back(mat[i][j] == 'R');
        } else {
            repn(j, m-1, 0) field.push_back(mat[i][j] == 'R');
        }
        dir = !dir;
    }

    int mx = (r + k - 1)/k;
    int mn = r/k;
    int z = r%k;    /// these many chickens will have 1 extra rice fields!
    int zp = k - z;

    int pref = 0;
    int val = 0;

    char x;
    vector<char> ch;
    fr(i, n*m){
        if(!z && !zp) break;
        pref += field[i];
        ch.push_back(chickens[val]);
        if(z){
            if(pref == mx){
                pref = 0;
                val++;
                z--;
            }
        } else if(zp) {
            if(pref == mn){
                pref = 0;
                val++;
                zp--;
            }
        }
    }

    val--;
    int sz = ch.size();

    rep(i, sz, n*m - 1){
        ch.push_back(chickens[val]);
    }

    fr(i, n*m){
        mat[i/m][i%m] = ch[i];
    }

    dir = true;
    fr(i, n){
        if(dir){
            fr(j, m) cout<<mat[i][j];
        } else {
            repn(j, m-1, 0) cout<<mat[i][j];
        }
        dir = !dir;
        cout<<endl;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

