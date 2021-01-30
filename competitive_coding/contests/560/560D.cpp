#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;


int countDivisors(ll n)
{
    int cnt = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % (1ll*i) == 0) {
            // If divisors are equal,
            // count only one
            if (n / (1ll*i) == 1ll*i)
                cnt++;

            else // Otherwise count both
                cnt = cnt + 2;
        }
    }
    return cnt;
}

int main(){
    int n, t;
    int x;
    cin>>t;
    while(t--){
        cin>>n;
        int arr[n];
        int maxE, minE;
        maxE = 1;
        minE = INT_MAX;
        fr(i, n){
            cin>>x;
            arr[i] = x;
        }
        sort(arr, arr+n);
        ll ans = (1ll)*arr[0]*(1ll)*arr[n-1];
        bool flag = true;
        if(countDivisors(ans) != n+2){
            cout<<-1<<endl;
            flag = false;
        } else {
            rep(i, 1, n-2){
                if((1ll)*arr[i]*(1ll)*arr[n-i-1] != ans){
                    cout<<-1<<endl;
                    flag = false;
                    break;
                }
            }
        }
        if(flag)
            cout<<ans<<endl;
    }
    return 0;
}

