#include <bits/stdc++.h>
using namespace std;

int a[100002];
int main()
{
    long long n,m,k,i,s=0,ss=0;
    double mx=0;
    cin>>n>>k>>m;
    for(int i=0; i<n; i++){
        cin>>a[i];
        ss+=1LL*a[i];
    }
    sort(a, a+n);
    for(int i=0; i<n&&i<=m; i++){
        mx = max(mx, double(ss-s+min(k*(n-i), m-i))/(n-i));
        s+=1LL*a[i];
    }
    cout<<setprecision(8)<<mx;
    return 0;
}
