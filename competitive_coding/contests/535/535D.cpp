#include<bits/stdc++.h>
using namespace std;

char rem(char x, char y, string temp){
    for(auto it: temp){
        if(it == x || it == y);
        else return it;
    }
}

int main(){
    int n;
    string s;
    cin>>n>>s;

    string temp = "RGB";
    map<char, int> mp;
    for(int i=0; i<3; i++) mp[temp[i]] = i;

    int dp[n][3]; /// cost till ith element if its s[temp[j]] for j = 1 to 3

    dp[0][0] = dp[0][1] = dp[0][2] = 1;
    dp[0][mp[s[0]]] = 0;
    char p[n][3];  /// parent
    p[0][0] = p[0][1] = p[0][2] = '@';

    for(int i=1; i<n; i++){
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + (s[i] != 'R');
        p[i][0] = (dp[i-1][1] < dp[i-1][2]) ? 'G' : 'B';

        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + (s[i] != 'G');
        p[i][1] = (dp[i-1][0] < dp[i-1][2]) ? 'R' : 'B';

        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + (s[i] != 'B');
        p[i][2] = (dp[i-1][0] < dp[i-1][1]) ? 'R' : 'G';
    }


    auto it = min_element(dp[n-1], dp[n-1]+3);
    cout<<*it<<endl;
    vector<char> res;
    int st = (it - dp[n-1]);
    int pos = n-1;
    res.push_back(temp[st]);
    while(p[pos][st] != '@'){
        res.push_back(p[pos][st]);
        st = mp[p[pos][st]];
        pos--;
    }

    reverse(res.begin(), res.end());
    for(auto it: res) cout<<it;

    return 0;
}

