#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define mod 1000000007
#define pb push_back
#define s(x) scanf("%d",&x)
#define nm 10000005  /// max element value caan be 10^7... i.e. nm for nmax
#define debug(x) printf("point %d\n",x)
int a[nm];
int b[nm];
int arr[1000005];  /// n can be max of 10^6.
int mi[nm],mi2[nm];
int f[nm];
int main()
{
    int i,j,n,m,s1,s2;
    ll ans = 1000000000000000000; /// 10^18
    s(n);
    for(i=1;i<=n;++i)
    {
        s(arr[i]);
        f[arr[i]]++;
        if(mi[arr[i]] == 0)
            mi[arr[i]] = i;
        else if(mi2[arr[i]] == 0)
            mi2[arr[i]] = i;
    }
    for(i=1;i<nm;++i)
    {   /// traversing all multiples of current gcd, G
        for(j=i;j<nm;j+=i)
        {
            if(!f[j])
                continue;
            m = (j/i);
            if(a[i] == 0)
            {
                if(f[j] > 1)
                    b[i] = m;
                a[i] = m;
                continue;
            }
            if(b[i] == 0)
            {
                b[i] = max(a[i],m);
                a[i] = min(a[i],m);
                continue;
            }
            /// unreachable code, m will always be greater than a[i] & b[i] from here!
            if(m < a[i])
            {
                cout<<"Hurr"<<endl;
                if(f[j] > 1)
                    b[i] = m;
                else
                    b[i] = a[i];
                a[i] = m;
                continue;
            }
            if(m < b[i])
            {
                cout<<"Ruhhh"<<endl;
                b[i] = m;
                continue;
            }
        }
    }
    /// a[i] & b[i] stores R & S resp. for given G.
    for(i=1;i<nm;i++)
    {
        if(a[i] == 0 || b[i] == 0)
            continue;
        if(ans > (ll)i*(ll)a[i]*(ll)b[i])
        {
            ans = (ll)i*(ll)a[i]*(ll)b[i];
            s1 = (ll)i*(ll)a[i];
            s2 = (ll)i*(ll)b[i];
        }
    }
    if(s1 == s2)
        cout << mi[s1] << " " << mi2[s1] << endl;
    else
        cout << min(mi[s1],mi[s2]) << " " << max(mi[s1],mi[s2]) << endl;
    return 0;
}
