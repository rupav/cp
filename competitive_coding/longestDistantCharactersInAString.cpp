#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

int longestDistantCharactersInAString(string s, int n){
    /// store in arr[26] the last index found of a given character, found so far!
    int cnt[26];
    memset(cnt, -1, sizeof(cnt));
    int res = 1;
    int si = 0;
    char c;
    for(int i=0; i<n; i++){
        c = s[i];
        if(cnt[c-'a'] != -1){
            /// break the streak, calc current streak length, and reset prev cnt array!
            res = max(res, i-si);
            si = cnt[c-'a']+1;  /// starting new streak, from prev. index+1 of current character.
            int li = cnt[c-'a'];
            fr(i, 26){
                /// reset all characters indices which are less than equal to cnt[c-'a']
                if(cnt[i]!= -1 && cnt[i]<=li)
                    cnt[i] = -1;
            }
        }
        cnt[c-'a'] = i;
    }
    return max(res, n-si);
}

int main(){
    string s;
    cin>>s;
    cout<<longestDistantCharactersInAString(s, s.size())<<endl;
    return 0;
}

