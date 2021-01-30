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


struct Node{
    Node* prev;
    Node* nxt;
    int val;

    Node(int val): val(val), nxt(nullptr), prev(nullptr){}
};


void solve(){
    int n;
    cin>>n;
    string in, out;
    cin>>in>>out;
    vector<vector<bool>> v(n, vector<bool>(n, 0));

    Node* nodes[n];
    fr(i, n) nodes[i] = new Node(i);

    fr(i, n){
        if((out[i] == 'Y') && (i + 1 < n) && (in[i+1] == 'Y')) nodes[i]->nxt = nodes[i + 1];
        if((out[i] == 'Y') && (i - 1 >= 0) && (in[i - 1] == 'Y')) nodes[i]->prev = nodes[i - 1];
    }

    fr(i, n){
        /// go left and right for each to check reachability
        v[i][i] = 1;
        int j = i;
        Node* tmp = nodes[j]->prev;
        while(tmp != nullptr){
            v[i][--j] = 1;
            tmp = nodes[j]->prev;
        }

        j = i;
        tmp = nodes[j]->nxt;
        while(tmp != nullptr){
            v[i][++j] = 1;
            tmp = nodes[j]->nxt;
        }
    }

    fr(i, n){
        fr(j, n){
            cout<<(v[i][j] ? 'Y': 'N');
        }
        cout<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("travel_restrictions_input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    ll t = 1;
    cin>>t;
    rep(i, 1, t){
        cout<<"Case #"<<i<<": "<<endl;
        solve();
    }

    return 0;
}

