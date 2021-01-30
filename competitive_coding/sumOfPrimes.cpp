#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;
const int LIM = (int)(1e6+5);
vector<bool> pr(LIM, true);

void constructPrimeSeive(int n = LIM, bool flag = false){
    if(!flag)
        return;
    pr[0] = pr[1] = false;  /// not primes.
    rep(i, 2, n-1){
        if(pr[i]){
            int j=i;
            while(j<n){
                pr[j] = false;
                j+=i;
            }
            pr[i] = true;
        }
    }
}

pii sumOfPrime(int n){
    for(int i=2; i<n; i++){
        if(pr[i] && pr[n-i])
            return make_pair(i, n-i);
    }
    return make_pair(-1, -1);
}

int main(){
    constructPrimeSeive(LIM, true);
    int t;
    int n;
    cin>>t;
    while(t--){
        cin>>n;
        pii ans = sumOfPrime(n);
        if(ans.first == -1)
            cout<<-1;
        else
            cout<<ans.first<<" "<<ans.second;
        cout<<endl;
    }
    return 0;
}

