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

ll gcdll(ll a, ll b){
    if(!b) return a;
    return gcdll(b, a%b);
}

int gcd(int a, int b){
    if(!b) return a;
    return  gcd(b, a%b);
}

void seive(int n){
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;

    for(int i=2; i*i<=n; i++){
        if(is_prime[i]){
            for(int j=i*i; j<=n; j+=i){
                is_prime[j] = false;
            }
        }
    }
}

vector<int> constructZFunc(string s){
    int n = s.size();
    vector<int> z(n);
    int l, r;
    l = r = 0;
    z[0] = 0;
    rep(i, 1, n-1){
        z[i] = 0;
        if(i<=r){
            z[i] = min(r-i+1, z[i-l]);  /// initialization, req. for linear time approach.
        }
        while(i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if(i+z[i]-1 > r){
            r = i+z[i]-1;
            l = i;
        }
    }
    return z;
}

bool IsSafe(int x, int y, int n, int**mat){
    return (x<n && y<n && mat[x][y]);
}

bool RatInAMaze(int **mat, int x, int y, int n, bool **sol){
    if(x == n-1 && y == n-1){
        return sol[x][y] = true;
    }
    if(IsSafe(x, y, n, mat)){
        if(RatInAMaze(mat, x+1, y, n, sol) == true){
            return sol[x][y] = true;
        }
        if(RatInAMaze(mat, x, y+1, n, sol) == true){
            return sol[x][y] = true;
        }
        return sol[x][y] = false;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int **mat = new int*[n];
    fr(i, n){
        mat[i] = new int[n];
        fr(j, n){
            cin>>mat[i][j];
        }
    }
    bool **sol = new bool*[n];
    fr(i, n){
        sol[i] = new bool[n];
        fr(j, n) sol[i][j] = false;
    }



    cout<<RatInAMaze(mat, 0, 0, n, sol)<<endl;
    fr(i, n){
        fr(j, n) cout<<sol[i][j]<<" ";
        cout<<endl;
    }


    return 0;
}
