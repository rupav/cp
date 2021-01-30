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

/// implement stack which gives push, pop, top, get_min in O(1)

class MinStack{
private:
    vector<int> s, mn;
public:
    MinStack(): s({}), mn({}) {}
    void push(int x){
        s.push_back(x);
        int tmp = ((int)mn.size()) ? min(x, *mn.rbegin()) : x;
        mn.push_back(tmp);
    }

    void pop(){
        s.pop_back();
        mn.pop_back();
    }

    int top(){
        return *s.rbegin();
    }

    int get_min(){
        return *mn.rbegin();
    }
};

void solve(){
    MinStack ms;
    int q, c, x;
    cin>>q;
    while(q--){
        cin>>c;
        if(!c){
            /// push
            cin>>x;
            ms.push(x);
        } else if (c == 1){
            /// pop
            ms.pop();
        } else if (c == 2){
            /// top
            cout<<ms.top()<<endl;
        } else {
            /// get min.
            cout<<ms.get_min()<<endl;
        }
    }
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

