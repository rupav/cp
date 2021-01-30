#include <bits/stdc++.h>
#define REP(i, n) for (int i = 1; i <= n; i++)
using namespace std;

typedef unsigned long long ll;
typedef vector<vector<ll> > matrix;
const ll MOD = 1000000007;
int K;

// computes A * B
matrix mul(matrix A, matrix B)
{
    matrix C(K+1, vector<ll>(K+1));
    REP(i, K) REP(j, K) REP(k, K)
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}

// computes A ^ p
matrix pow(matrix A, ll p)
{
    if (p == 1)
        return A;
    if (p % 2)
        return mul(A, pow(A, p-1));
    matrix X = pow(A, p/2);
    return mul(X, X);
}

int main(){

    /// in this, dp[i] = dp[i-m] + dp[i-1], F1[1][1] is dp[0] (1), therefore, we need to find, f(n+1), F(N+1) = T^N*F(N)
    ll n, m;
    cin>>n>>m;
    K = m;
    vector<ll> F1(K+1);
    REP(i, K) F1[i] = 1;  /// 1st vector

    matrix T(K+1, vector<ll>(K+1));  /// transformation matrix
    REP(i, K-1){
        REP(j, K){
            T[i][j] = 0;
            if(j == i+1) T[i][j] = 1;
        }
    }
    /// for K the row, dp[i] = dp[i-1] + dp[i-m]
    REP(j, K){
        T[K][j] = 0;
        if(j == 1 || j == K) T[K][j] = 1;
    }

    matrix Z = pow(T, n);
    ll ans = 0;
    REP(j, K){
        ans = (ans + Z[1][j]*F1[j])%MOD;
    }
    cout<<ans;
}
