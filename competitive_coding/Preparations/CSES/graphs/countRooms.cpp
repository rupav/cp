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

int n, m;

bool in(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= m) return false;
    return true;
}

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

/// DSU
struct Node{
    Node* p;
    int val;
    int sz;
    Node(int val): val(val), sz(1), p(this) {}
};


Node* find_set(Node* a) {
    if(a->p == a) return a;
    return a->p = find_set(a->p);
}

Node* union_set(Node* a, Node* b){
    Node* l1 = find_set(a);
    Node* l2 = find_set(b);
    if(l1 == l2) return l1;
    if(l1->sz >= l2->sz){
        l2->p = l1;
        l1->sz += l2->sz;
        return l1;
    } else {
        l1->p = l2;
        l2->sz += l1->sz;
        return l2;
    }
}

bool check(char x){
    return (x == '.');
}

int solve(){

    int x, y, nx, ny;
    cin>>n>>m;
    vector<string> mat(n);
    fr(i, n) cin>>mat[i];

    vector<Node*> nodes(n * m);

    fr(x, n){
        fr(y, m){
            nodes[m * x + y] = new Node(m * x + y);
        }
    }

    fr(x, n){
        fr(y, m){
            if(!check(mat[x][y])) continue;
            fr(k, 4){
                nx = x + dx[k];
                ny = y + dy[k];
                if(in(nx, ny) && check(mat[nx][ny])){
                    union_set(nodes[m * x + y], nodes[m * nx + ny]);
                }
            }
        }
    }

    set<int> s;

    fr(x, n){
        fr(y, m){
            if(check(mat[x][y])){
                s.insert(find_set(nodes[x * m + y])->val);
            }
        }
    }

    return s.size();

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    // cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }

    return 0;
}

