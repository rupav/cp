#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
ll mod = 1e9+7;


int main(){
    int n, m, k;
    cin>>n>>m>>k;
    ll arr[n];
    ll maxE[2];
    maxE[0] = 0;
    maxE[1] = 0;
    fr(i, n){
        cin>>arr[i];
        /// find 2 largest elements!
        if(arr[i] > maxE[0]){
            maxE[1] = maxE[0];
            maxE[0] = arr[i];
        } else if (arr[i] > maxE[1]){
            maxE[1] = arr[i];
        }
    }
    ull res = 0;
    int factor = m/(k+1);

    int rem = m%(k+1);
    res += 1ull*factor*1ull*(1ull*k*maxE[0] + 1ull*maxE[1]);
    res += 1ull*(1ull*(rem)*1ull*maxE[0]);
    cout<<res;
    return 0;
}

