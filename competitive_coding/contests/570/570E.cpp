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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;

    queue<string> q;
    set<string> st;
    q.push(s);
    st.insert(s);
    int ans = 0;

    while(!q.empty() && (int)(st.size()) < k){
        string curr = q.front();
        q.pop();
        fr(i, curr.size()){
            string temp = curr;
            temp.erase(i, 1);
            if(st.find(temp) == st.end()){
                q.push(temp);
                st.insert(temp);
                ans += n - temp.size();
                if((int)(st.size()) == k) break;
            }
        }
    }

    if(st.size() < k) cout<<-1;
    else cout<<ans;

    return 0;
}

