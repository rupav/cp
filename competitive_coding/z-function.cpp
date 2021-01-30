#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

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

/// applications of Z-Function
/// 1) Longest Prefix-Suffix
int findLPS(string s){
    vector<int> z = constructZFunc(s);
    int n = s.size();
    int res = 0;
    fr(i, n){
        if(z[i]+i == n){
            res = z[i];
            break;
        }
    }
    return res;
}

/// 2) Find all occurrences of pattern P in text T.
vector<int> patternSearch(string T, string P){
    string s = P+"#"+T;  /// assuming T and P dont have '#' in it.
    int n = s.size();
    int m = P.size();
    vector<int> z = constructZFunc(s);
    vector<int> o(n);  /// occurrences vector
    int k = 0;
    fr(i, n){
        if(z[i] == m){
            /// will only work because of #, otherwise z[i] can be even greater than m, which will include part of the text T!
            o[k++] = i-m-1;  /// starting positions of P in text T.
        }
    }
    o[k]=-1;
    return o;
}

/// 3) String compression.
/// Given a string s of length n. Find its shortest "compressed" representation, that is: find a string t of shortest length such that s can be represented as a concatenation of one or more copies of t.
string compress(string s){
    int n = s.size();
    vector<int> z = constructZFunc(s);
    int len = 0;
    rep(i, 1, n-1){
        if(n%i == 0 && i+z[i] == n){
            len = i;
        }
    }
    string c = "";
    fr(i, len){
        c += s[i];
    }
    return c;
}

int main(){
    string s, t;
    cin>>s>>t;
    vector<int> z = constructZFunc(s);
    for(auto i: z){
        cout<<i<<" ";
    }
    cout<<endl;
    vector<int> o = patternSearch(t, s);
    for(auto i: o){
        if(i == -1)
            break;
        cout<<i<<" ";
    }

    cout<<compress(s)<<endl;
    return 0;
}

