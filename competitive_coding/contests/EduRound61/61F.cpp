#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

int solve(string s, int n){
    if(n == 0)
        return 0;
    if(n==1)
        return 1;
    if(n==2)
        return 2;  /// compressed array, so cant have same values!
    unordered_map<char, int> mp;
    unordered_map<char, bool> tp;
    int maxE = INT_MIN;
    /// string maxC = "";
    char maxC[n+1];
    int k = 0;
    fr(i, n){
        mp[s[i]]++;  /// storing frequency.
        if(mp[s[i]] == maxE){
            maxC[k++] = s[i];
        }
        if(mp[s[i]] > maxE){
            k = 0;
            maxE = mp[s[i]];
            maxC[k++] = s[i];
        }
    }
    k = 0;
    fr(i, n){
        if(!tp[s[i]]){
            maxC[k++] = s[i];
            tp[s[i]] = true;
        }
    }
    maxC[k] = '\0';
    k = 0;
    if(maxE == 1)
        return n;  /// all are unique!
    int ans = INT_MAX;
    while(maxC[k++] != '\0'){
        int res = 0;
        int st = 0;
        int len = 0;
        fr(i, n){
            if(s[i] == maxC[k-1]){
                len = i - st;
                res += solve(s.substr(st, len), len);
                st  = i+1;
            }
        }
        res += solve(s.substr(st, n-st), n-st);
        ans = min(res, ans);
    }
    return ans + 1;
}

int main(){
    string s;
    int n;
    //cin>>n;
    cin>>s;
    n = s.size();
    /// first compress the string and then find unique characters! or find unique characters.
    string c = "";
    unordered_map<char, int> mp;
    int prev = INT_MAX;
    fr(i, n){
        if((int)s[i] != prev){
            prev = (int)s[i];
            c += s[i];
        }
    }

    n = c.size();
    int res = solve(c, n);

    cout<<res;

    /// greedy approach, pick highest freq element to delete as last element.


    /*

    int count  = 0;
    fr(i, n){
        if(!mp[s[i]]){
            mp[s[i]] = true;
            count ++;
        }
    }
    cout<<count;
    */

    return 0;
}

