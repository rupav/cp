#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;


int main(){
    int n;
    ll hp;
    cin>>hp>>n;
    int arr[n+1];
    ll psum[n+1] = {0};

    ll mpsum = 0;
    rep(i, 1, n){
        cin>>arr[i];
        psum[i] = psum[i-1] + 1ll*arr[i];
        if(psum[i] <= -1*hp){
            cout<<i;
            return 0;
        }
        mpsum = min(mpsum, psum[i]);
    }

    if(psum[n] >= 0){
        cout<<-1;
        return 0;
    }

    ll cyc = (hp + mpsum)/psum[n];
    cyc *= -1;
    hp += (1ll*psum[n])*cyc;
    ll ans = (1ll*n)*cyc;

    for(int i = 0; ; i++){
        if(hp <= 0){
            cout<<ans;
            return 0;
        }
        hp += 1ll*arr[(i%n) + 1];
        ans++;
    }

    return 0;
}

