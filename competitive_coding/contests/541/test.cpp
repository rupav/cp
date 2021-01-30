#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

#define ff  first
#define ss  second
#define mp  make_pair
#define pb  push_back
#define N 100001
#define mem(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define endl "\n"
#define fast_IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


int main()
{
    fast_IO;
    ll n;

    cin>>n;
    vii arr;
    arr.pb(pair<int, int>(0, 0));
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        arr.pb(pair<int, int>(x,y));

    }
    ll sum=0;

    for(int i=0;i<=n;i++)
    {
        int x,y;
        x = max(arr[i].ff,arr[i].ss);
        y = min(arr[i+1].ff,arr[i+1].ss);
        if(y>=x)
        {
            if(x==y && x!=0)
                sum++;
            else
            sum+=(y-x);
        }
    }

    cout<<sum+1<<endl;

}
