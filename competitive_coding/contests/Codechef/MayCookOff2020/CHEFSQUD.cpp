#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a) * (a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;

const int N = 2e5 + 5;
int n;

int bit[N] = {0};
void update(int i, int upd){
    for(; i <= n; i += i&(-i)) bit[i] += upd;
}

int get(int i){
    int sm = 0;
    for(; i > 0; i -= i&(-i)) sm += bit[i];
    return sm;
}

int solve(){
    cin>>n;
    int a[n+1];

    map <int, vector <int> > mp;

    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        mp[a[i]].push_back(i);
    }

    int id = 0;

    for(auto i:mp)
    {
        id++;

        for(int j:i.second)
            a[j] = id;
    }


    int m = (n*(n+1))/2;

    /// binary search over the answer x, and check if count of subarrays whose inversion count <= x is equal to (m + 1)/2 - 1;
    int lb = 0, rb = m;
    int target = (m - 1)/2;

    int ans = m;
    while(lb <= rb) {

        int x = (lb + rb)/2;
        int cnt = 0, tot = 0;

        rep(i, 0, id) bit[i] = 0;    /// max A[i] is n, because of coordinate compression!
        int i = 1, j = 1;
        while(i <= n && cnt <= x){

            update(a[i], 1);
            cnt += (get(n) - get(a[i]));

            while(j <= i && cnt > x){
                update(a[j], -1);
                cnt -= get(a[j] - 1);
                j++;
            }

            tot += (i - j + 1);
            i++;
        }

        // watch(x);
        // watch(tot);

        if(tot > target){
            ans = x;
            rb = x - 1;
        } else {
            lb = x + 1;
        }
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }

    return 0;
}

