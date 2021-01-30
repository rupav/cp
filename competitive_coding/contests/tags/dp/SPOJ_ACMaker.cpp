#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

void markInsignificant(string *p, int k, string& txt, map<int, bool>& insig){
    vector<string> v;
    int st = 0;
    while(st != txt.size()){
        v.push_back(txt.substr(st, txt.find(" ")))
        st = txt.find(" ")+1;
    }
    fr(i, k){
        fr(j, v.size()){
            if(p[i] == v[j]){
            }
        }
    }
}

int findMatches(string pat, int m, string txt, int n, int**dp, int i, int j, map<int, bool> insig){
    if(j==n || i==m)  /// end of strings, since 0-based indexing.
        return 0;

    if(pat[i] == txt[j]){
        /// a match!
        if(i == m-1){
            /// last character of pattern matched!
            cout<<"j: "<<j<<endl;
            return 1 + findMatches(pat, m, txt, n, dp, i, j+1);
        } else {
            return findMatches(pat, m, txt, n, dp, i+1, j+1) + findMatches(pat, m, txt, n, dp, i, j+1);
        }
    } else {
        /// not a match!
        return findMatches(pat, m, txt, n, dp, i, j+1);
    }
}

int main(){
    int k;
    cin>>k;
    string *insig = new string[k];
    fr(i, k)
        cin>>insig[i];

    int n, m;

    cin.ignore();
    while(true){
        string t, p, txt;
        getline(cin, t);
        if(t == "LAST CASE"){
            break;
        }

        int m = t.find(" ");
        n = t.size();
        p = t.substr(0, m);
        txt = t.substr(m+1, n-m);
        transform(p.begin(), p.end(), p.begin(), ::tolower);
        transform(txt.begin(), txt.end(), txt.begin(), ::tolower);
        n = n-m;

        int **dp = new int*[n];
        fr(i, n){
            dp[i] = new int[m];
            fr(j, m){
                dp[i][j] = 1;
            }
        }

        int ans = findMatches(p, m, txt, n, dp, 0, 0);
        cout<<ans<<endl;

    }
    return 0;
}

