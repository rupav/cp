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


bool comp(pii a, pii b){
    return a.second > b.second;
}

void solve(){
    int n;
    cin>>n;
    string s;
    int lb, rb;
    vector<pii> v[2];

    pii pst = {-1, -1}, pen = {-1, -1};


    fr(i, n){
        cin>>s;
        int m = s.size();
        lb = rb = 0;
        stack<char> st;
        fr(j, m){
            if(s[j] == '(') {
                st.push('(');
                rb++;
            } else {
                if(st.size()){
                    st.pop();
                    rb--;
                } else lb++;
            }
        }

        if(lb == 0 && rb == 0) continue;
        if(!lb){
            pst.first = lb;
            pst.second = rb;
        }

        if(!rb){
            pen.first = lb;
            pen.second = rb;
        }

        v[lb > rb].push_back({lb, rb});

    }

    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end(), comp);

    int sm = 0;
    bool f = true;
    for(auto it: v[0]){
        // cout<<it.first<<endl;
        sm -= it.first;
        if(sm < 0) f = false;
        sm += it.second;
    }

    for(auto it: v[1]){
        sm -= it.first;
        if(sm < 0) f = false;
        sm += it.second;
    }

    f = f && (sm == 0);

    cout<<(f ? "Yes": "No");

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

