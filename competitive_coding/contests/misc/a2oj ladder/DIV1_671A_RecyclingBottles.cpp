#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;

double dist(double x1, double y1, double x2, double y2){
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

using pdl = pair<double, ll>;
void solve(){
    ll ax, ay, bx, by, tx, ty, n;
    cin>>ax>>ay>>bx>>by>>tx>>ty>>n;
    pll bins[n];
    pdl da[n], db[n];    /// distance of each point from Adil and Bani

    double tot = 0.0;
    double d;
    fr(i, n){
        cin>>bins[i].first>>bins[i].second;
        d = dist(bins[i].first, bins[i].second, tx, ty);
        tot += 2.0*d;
        da[i].first = dist(bins[i].first, bins[i].second, ax, ay) - d;
        db[i].first = dist(bins[i].first, bins[i].second, bx, by) - d;
        da[i].second = db[i].second = i;
    }

    sort(da, da + n);
    sort(db, db + n);

    double ans = numeric_limits<double>::max();
    /// case 1 - both of them pick atleast one bottle
    double temp = 0.0;
    if(n != 1){
        double temp1, temp2;
        temp1 = da[0].first;
        temp2 = db[0].first;
        if(da[0].second == db[0].second){
            temp1 += db[1].first;
            temp2 += da[1].first;
        } else {
            temp1 += db[0].first;
            temp2 += da[0].first;
        }
        temp = min(temp1, temp2);
    } else {
        temp = min(da[0].first, db[0].first);
    }

    ans = min(ans, tot + temp);

    /// case 2 - Abil picks all bottles
    temp = da[0].first;
    ans = min(ans, tot + temp);

    /// case 3 - bani picks all bottles
    temp = db[0].first;
    ans = min(ans, tot + temp);

    cout<<setprecision(18)<<ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    //  cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

