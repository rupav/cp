
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

void reverseWords(string s) {
    int start = 0;
    while(s.find(".") != string::npos){
        reverse(s.begin()+start, s.begin() + s.find(".") - start);
        start = (s.begin()+start).find(".");
    }
    reverse(s.begin()+start, s.begin() + s.find(".") - start);
    reverse(s.begin(), s.end());
    cout<<s;
}

int main(){
    return 0;
}
