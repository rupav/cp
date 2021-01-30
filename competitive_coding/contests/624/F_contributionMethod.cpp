#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fr(i, n) for(int i=0; i<n; i++)

const int N = 2e5 + 5;
int x[N], v[N];
using pii = pair<int, int>;
vector<pii> points;

int main() {

    int n;
    cin>>n;
    points.resize(n);
    fr(i, n) cin>>x[i];
    fr(i, n) cin>>v[i];
    fr(i, n) points[i] = {v[i], x[i]};

    sort(x, x + n);
    sort(points.begin(), points.begin() + n);
    map<int, int> mp;

    ll ans = 0ll;
    fr(i, n) {
        ans += 1ll * x[i] * 1ll * ( 2*i + 1 - n );
        mp[x[i]] = i;
    }

    fr(i, n) {
        ans -= 1ll * points[i].second * 1ll* (mp[points[i].second] - i);
    }

    cout<<ans;

    return 0;
}
