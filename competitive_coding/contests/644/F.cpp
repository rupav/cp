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

vector<string> a;
bool check(string& s){
    /// if s is correct
    int m = s.size();
    int cnt;
    for(auto it: a){
        cnt = 0;
        fr(i, m){
            if(s[i] != it[i]) cnt++;
        }
        if(cnt > 1) return false;
    }
    return true;
}

string AL = "qwertyuiopasdfghjklzxcvbnm";

void solve(){
    int n, m;
    cin>>n>>m;
    a.resize(n);
    string s;
    fr(i, n) cin>>a[i];

    /// check all possibilities!
    bool f = false;
    char x;
    fr(i, n){
        s = a[i];
        fr(j, m){
            for(auto z: AL){
                x = s[j];
                s[j] = z;
                f = check(s);
                if(f){
                    cout<<s<<endl;
                    return;
                }
                s[j] = x;
            }
        }
    }

    if(!f){
        cout<<-1<<endl;
        return;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

