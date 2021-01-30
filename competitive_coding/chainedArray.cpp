/// application of Kosaraju algorithm!
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

class Graph{
    int n;  /// vertices possible
    vector<int> *edges;
    int *in;  /// in degree
    stack<int> s; /// for kosaraju finish timing stack
public:

    /// constructor
    Graph(int V){
        this->n = V;
        edges = new vector<int>[n];
        in = new int[n];
        fr(i, n) in[i] = 0;
        while(!s.empty()) s.pop();
    }

    /// directed graph
    void addEdge(int u, int v, bool bilateral = false){
        edges[u].push_back(v);
        if(bilateral) edges[v].push_back(u);
    }

    void dfsUtil(int src, bool visited[], bool fillStack = true){
        visited[src] = true;
        for(auto it: this->edges[src]){
            if(!visited[it]){
                this->dfsUtil(it, visited, fillStack);
            }
        }
        if(fillStack)
            (this->s).push(src);
    };



    bool isEulerianCycle(){
        return isSC();
    }

    /// is single strongly component
    bool isSC();

    Graph getTranspose();

    void printG(){
        for(int i=0; i<n; i++){
            cout<<i<<": ";
            for(auto it: edges[i]){
                cout<<it<<" ";
            }
            cout<<endl;
        }
    }

};

Graph Graph::getTranspose(){
    Graph g(this->n);
    for(int i=0; i<n; i++){
        for(auto it: edges[i]){
            g.addEdge(it, i);
        }
    }
    return g;
}

bool Graph::isSC(){
    /// Kosaraju algorithm to find strongly connected components, if 1 return true
    bool visited[n];
    memset(visited, false, sizeof(visited));
    while(!s.empty()) s.pop();
    for(int i=0; i<n; i++){
        if(!edges[i].empty() && !visited[i]){
            dfsUtil(i, visited);
        }
    }

    Graph gt = this->getTranspose();
    memset(visited, false, sizeof(visited));
    int count = 0;
    while(!s.empty()){
        if(!gt.edges[s.top()].empty() && !visited[s.top()]){
            gt.dfsUtil(s.top(), visited, false);
            count ++;
        }
        s.pop();
    }
    return (count == 1);
}

int encode(char c){
    return (int)(c - 'a');
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> v(n);
        string s;
        fr(i, n){
            cin>>s;
            v.push_back(s);
        }
        Graph g(26);
        for(auto it: v){
            g.addEdge(encode(it[0]), encode(it[it.size()-1]));
        }
        // g.printG();
        cout<<g.isEulerianCycle()<<endl;
    }

    return 0;
}
