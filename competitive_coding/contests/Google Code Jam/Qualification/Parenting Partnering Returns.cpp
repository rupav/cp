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

struct T{
    int st;
    int en;
    int i;
};

bool compare(T a, T b){
    return a.st < b.st;
}

const int N = 1445;
int bit[N] = {0};

void update(int i, int upd){
    for(; i < N; i += i&(-i)) bit[i] += upd;
}

int get(int i){
    int sum = 0;
    for(; i > 0; i -= i&(-i)) sum += bit[i];
    return sum;
}

void solve(){
    int n, st, en;
    cin>>n;
    T acts[n];
    rep(i, 1, N - 1) bit[i] = 0;
    fr(i, n){
        cin>>st>>en;

        update(st + 1, 1);
        update(en + 1, -1);

        acts[i].st = st;
        acts[i].en = en;
        acts[i].i = i;
    }

    bool f = true;
    rep(i, 1, N - 1){
        if(get(i) > 2) {
            f = false;
            break;
        }
    }

    if(!f) {
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }

    sort(acts, acts + n, compare);

    char res[n];
    int max_[2] = {-1, -1};
    char poss[2] = {'C', 'J'};

    fr(i, n) {
        if(max_[0] > acts[i].st){
            res[acts[i].i] = poss[1];
            max_[1] = max(max_[1], acts[i].en);
        } else {
            res[acts[i].i] = poss[0];
            max_[0] = max(max_[0], acts[i].en);
        }
    }



    fr(i, n) cout<<res[i];
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    rep(i, 1, t){
        cout<<"Case #"<<i<<": ";
        solve();
    }

    return 0;
}
