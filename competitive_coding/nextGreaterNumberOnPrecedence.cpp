#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;
int priority[10];  /// priorities/precedence of each digit.

struct compare{
    bool operator()(char x, char y){
        return priority[x-'0'] < priority[y-'0'];
    }
};

bool compare(char x, char y){
    return priority[x-'0'] < priority[y-'0'];
}

int main(){
    string s;
    cin>>s;  /// priority of numbers i.e. if 1675298043, means 1 has least priority, 3 has max
    int p=0;
    for(auto c: s){
        priority[c-'0'] = p++;  /// higher p means higher priority!
    }
    cin>>s;  /// number's whose next permutation has to be calculated based on above priority order!
    bool a = next_permutation(s.begin(), s.end(), compare);
    if(a)
        cout<<s;
    else{
        prev_permutation(s.begin(), s.end(), compare);
        cout<<s;
    }
    return 0;
}

