#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;

void print(){
    cout<<"0 0 0";
    return;
}

void solve(){
    int n;
    cin>>n;
    int a[n];
    fr(i, n) cin>>a[i];
    int g, s, b;

    vector<int> p;
    int i=0;
    while(i<n){
        int j=i+1;
        while(j<n && a[i]==a[j])j++;
        p.push_back(j);
        i = j;
    }


    if(p.size() < 3){
        print();
        return;
    }

    auto z = upper_bound(p.begin(), p.end(), n/2) - p.begin();
    z-=1;

    if(z < 2){
        print();
        return;
    }


    g = p[0];
    s = b = 0;


    i = 1;
    while(i <= z){
        s += p[i] - p[i-1];
        i++;
        if(s > g) {
            break;
        }
    }

    while(i <= z) {
        b += p[i] - p[i-1];
        i++;
    }



    if(b <= g) {
        print();
        return;
    }

    cout<<g<<" "<<s<<" "<<b;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        solve();
        cout<<endl;
    }

    return 0;
}

