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

ll gcdll(ll a, ll b){
    if(!b) return a;
    return gcdll(b, a%b);
}

int gcd(int a, int b){
    if(!b) return a;
    return  gcd(b, a%b);
}

void seive(int n){
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;

    for(int i=2; i*i<=n; i++){
        if(is_prime[i]){
            for(int j=i*i; j<=n; j+=i){
                is_prime[j] = false;
            }
        }
    }
}

vector<int> constructZFunc(string s){
    int n = s.size();
    vector<int> z(n);
    int l, r;
    l = r = 0;
    z[0] = 0;
    rep(i, 1, n-1){
        z[i] = 0;
        if(i<=r){
            z[i] = min(r-i+1, z[i-l]);  /// initialization, req. for linear time approach.
        }
        while(i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if(i+z[i]-1 > r){
            r = i+z[i]-1;
            l = i;
        }
    }
    return z;
}


struct Node{
    Node* parent;
    int val, s;
    Node(int i, int size){
        s = size;
        val = i;
        // parent = this;
    }
};

Node* make_set(int i){
    Node* leader = new Node(i, 1);
    leader->parent = leader;
    return leader;
}

Node* find_set(Node* x){
    if(x->parent == x) return x;
    return x->parent = find_set(x->parent);
}

Node* union_set(Node* x, Node* y){
    Node* l1 = find_set(x);
    Node* l2 = find_set(y);
    if(l1 == l2) return l1;
    if(l1->s > l2->s){
        l2->parent = l1;
        l1->s += l2->s;
        return l1;
    } else {
        l1->parent = l2;
        l2->s += l1->s;
        return l2;
    }
}

void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    vector<Node*> sets(n, NULL);
    int x;
    fr(i, n){
        cin>>x;
        x--;
        v[i] = x;
    }
    fr(i, n){
        if(sets[i] == NULL){
            int j = v[i];
            sets[i] = make_set(i);
            while(j != i){
                sets[j] = make_set(j);
                union_set(sets[j], sets[i]);
                j = v[j];
            }
        }
    }

    fr(i, n){
        cout<<find_set(sets[i])->s<<" ";
    }
    cout<<endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin>>q;
    while(q--){
        solve();
    }

    return 0;
}

