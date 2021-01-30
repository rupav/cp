#include<bits/stdc++.h>
using namespace std;

vector<string> permute(string s, int n, string t){
    if(n == 0){
        // base case
        return vector<string> (1, t);
    }
    vector<vector<string>> temp(n);
    for(int i=0; i<n; i++){
        temp[i] = permute(s.substr(0, i) + s.substr(i+1, n-i), n-1, t+s[i]);
    }
    /// stack all vectors into one
    vector<string> res;
    for(auto it: temp){
        for(auto jit: it){
            res.push_back(jit);
        }
    }
    return res;
}

int calc(string s, int n, string t, int m){
    /// converting cost of s into repeating t
    int res = 0;
    for(int i=0; i<n; i++){
        if(s[i] != t[i%m]) res++;
    }
    return res;
}

int main(){
    int n;
    string s;
    cin>>n>>s;

    string template_ = "RGB";
    int m = template_.size();

    vector<string> res = permute(template_, m, "");
    // for(auto it: res) cout<<it<<endl;

    vector<int> ans;
    for(auto it: res){
        ans.push_back(calc(s, n, it, m));
    }

    vector<int>::iterator it = min_element(ans.begin(), ans.end());
    cout<<*it<<endl;
    int ind = it - ans.begin();
    for(int i=0; i<n; i++){
        cout<<res[ind][i%m];
    }

    return 0;
}
