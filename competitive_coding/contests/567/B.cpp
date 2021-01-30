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

void calculate(string &s1, string &s2, stack<int> &ans, ll n1, ll n2){

        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());

        ll i = 0;
        int rem = 0;
        int temp;
        for(; i<min(n1, n2); i++){
            temp = (int(s1[i]-'0') + int(s2[i]-'0') + rem);
            ans.push(temp%10);
            rem = temp/10;
        }
        if(n1>n2){
            for(; i<n1; i++){
                temp = (int(s1[i]-'0') + rem);
                ans.push(temp%10);
                rem = temp/10;
            }
        } else {
            for(; i<n2; i++){
                temp = (int(s2[i]-'0') + rem);
                ans.push(temp%10);
                rem = temp/10;
            }
        }
        if(rem) ans.push(rem);

        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, n1, n2;
    cin>>n;
    string s, s1, s2;
    cin>>s;

    ll r, l;
    if(true){
        r = n/2;
        l = n/2 - 1;
        while(l>=0 && s[l]=='0'){
            l--;
        }
        while(r<n && s[r] == '0') r++;

        /// add 2 string now!
        // string ans;
        stack<int> ans[2];

        if(true || !(n&1ll)){
            s2 = s.substr(r, string::npos);
            s1 = s.substr(0, r);
            calculate(s1, s2, ans[0], r, n-r);

            s2 = s.substr(l, string::npos);
            s1 = s.substr(0, l);
            calculate(s1, s2, ans[1], l, n-l);
        }

        if((n&1ll)){
            if((r == n/2) && s[r] > s[0] && (r<n) && (s[r+1]!='0')){
                if(true){
                    s1 = s.substr(0, r+1);
                    s2 = s.substr(r+1, string::npos);
                    calculate(s1, s2, ans[1], r+1, n-r-1);
                }
            }
        }



        if(ans[0].size() != ans[1].size()){
            bool x = ans[1].size() < ans[0].size();
            while(!ans[x].empty()){
                cout<<ans[x].top();
                ans[x].pop();
            }
        } else {
            queue<int> res[2];
            while(ans[0].top() == ans[1].top()){
                res[0].push(ans[0].top());
                res[1].push(ans[1].top());
                ans[0].pop();
                ans[1].pop();
            }
            if(!ans[0].empty() && (ans[0].top() < ans[1].top())){
                while(!res[0].empty()){
                    cout<<res[0].front();
                    res[0].pop();
                }
                bool x = false;
                while(!ans[x].empty()){
                    cout<<ans[x].top();
                    ans[x].pop();
                }
            } else {
                while(!res[1].empty()){
                    cout<<res[1].front();
                    res[1].pop();
                }
                bool x = true;
                while(!ans[x].empty()){
                    cout<<ans[x].top();
                    ans[x].pop();
                }
            }
        }

    } else {
        // if(s[n/2]>s[0])
    }

    return 0;
}

