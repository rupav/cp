#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pi acos(-1)
#define mod 998244353
#define all(x) x.begin(), x.end()
using namespace std;

bool check(int i, int j, vector<pair<pair<int, int>, int> > a){
    if(a[i].first.second > a[j].first.first){
        return true;
    }
    return false;
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++){
        int n;
        cin >> n;
        vector<pair<pair<int, int>, int> > a;
        for(int i = 0; i < n; i++){
            int x, y;
            cin >> x >> y;
            a.push_back({{x, y}, i});
        }
        sort(all(a));
        bool f = true;
        string ans(n, '0');
        int i = 0;
        int j = 0, c = 0;
        while(i < n){
            cout<<a[i].first.second<<endl;
            if(j <= a[i].first.first){
                ans[a[i].second] = 'J';
                j = max(j, a[i].first.second);
            }else {
                ans[a[i].second] = 'C';
                c = max(c, a[i].first.second);
            }
            i++;
        }
        for(int i = 0; i + 2 < n; i++){
            int x = i, y = i + 1, z = i + 2;
            bool f1 = check(x, y, a), f2 = check(y, z, a), f3 = check(x, z, a);
            if(f1 && f2 && f3){
                f = false;
                break;
            }
        }
        if(!f){
            ans = "IMPOSSIBLE";
        }
        cout << "Case #" << tc << ": " << ans << endl;
    }
}
