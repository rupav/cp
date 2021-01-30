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

bool allPrev(string &t, int i, char prev){
    bool flag = true;
    for(; i<t.size(); i++){
        if(t[i] != prev){
            flag = false;
            break;
        }
    }
    return flag;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    string s, t;
    int m;
    fr(i, n){
        cin>>s;
        cin>>t;
        m = t.size();
        int j = 0;
        bool flag = true;
        char prev = '@';
        int k = 0;
        bool isP = false;
        for(; k<s.size(); k++){
            char it = s[k];
            flag = false;
            bool next = false;
            for(; j<m;){
                flag = true;
                if(t[j] == it){
                    next = true;
                    prev = t[j];
                    j++;
                    break;
                }
                if(t[j] == prev){
                    j++;
                    continue;
                }
                flag = false;
                break;
            }
            if((!next) || flag == false){
                isP = true;
                cout<<"NO"<<endl;
                break;
            }
        }
        if(!isP && flag){
            if(!allPrev(t, j, prev) || (k != s.size())){
                cout<<"NO"<<endl;
            } else {
                cout<<"YES"<<endl;
            }
        }
    }

    return 0;
}

