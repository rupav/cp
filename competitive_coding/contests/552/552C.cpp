#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;


int main(){
    vector<int> a(3);
    cin>>a[0]>>a[1]>>a[2];
    int full = min({a[0]/3, a[1]/2, a[2]/2});
    int fac[] = {3, 2, 2};
    fr(i, 3) a[i] -= full*fac[i];
    int idx[] = {0, 1, 2, 0, 2, 1, 0};
    int ans = full;
    fr(start, 7){
        int curr = 0;
        vector<int> b = a;
        int day = start;
        while(b[idx[day]] > 0){
            --b[idx[day]];
            day = (day+1)%7;
            ++curr;
        }
        ans = max(ans, full*7 + curr);
    }
    cout<<ans;
    return 0;
}

