#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
ll mod = 1e9+7;

int power(ull x, ll y)
{
    x = x%y;
    ull res = 1;     // Initialize result

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = res*1ull*x;

        y = y>>1;
        x = x*x;
    }
    return res;
}

int main(){
    ull n;
    int m;
    cin>>n>>m;

    return 0;
}
