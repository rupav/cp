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

void print(bool flag){
    if(!flag){
        cout<<"NO";
    } else {
        cout<<"YES";
    }
    cout<<endl;
}

void check(vector<pair<char, int>> &sv, vector<pair<char, int>> &tv){
    if(sv.size() != tv.size()){
        print(0);
        return;
    }

    while(!sv.empty()){
        if((sv.back().first != tv.back().first) || (sv.back().second > tv.back().second)){
            print(0);
            return;
        }
        sv.pop_back();
        tv.pop_back();
    }
    print(1);
}

void preprocess(string &s, vector<pair<char, int>> &v){
    char prev = s[0];
    int count = 1;
    for(int i=1; i<s.size(); i++){
        if(s[i] != prev){
            v.push_back(make_pair(prev, count));
            count = 1;
            prev = s[i];
        } else {
            count++;
        }
    }
    v.push_back(make_pair(prev, count));
}

void print_v(vector<pair<char, int>> &v){
    for(auto it: v){
        cout<<it.first<<" "<<it.second<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    string s, t;
    fr(i, n){
        cin>>s;
        cin>>t;
        vector<pair<char, int>> sv, tv;
        preprocess(s, sv);
        preprocess(t, tv);
        // print_v(sv);
        check(sv, tv);
    }

    return 0;
}

