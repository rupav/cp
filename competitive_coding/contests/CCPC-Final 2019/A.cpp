#include<bits/stdc++.h>
using namespace std;

using pis = pair<int, string>;
map<string, set<int>> mp;
string mths[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sept", "Oct", "Nov", "Dec"};
map<string, int> rmp;

string suffix(int n){
    if(n == 1) return "st";
    if(n == 2) return "nd";
    if(n == 3) return "rd";
    return "th";
}

void solve(int case_){
    int n;
    cin>>n;
    string z, s, t, num = "", suff = "";
    for(int i=1; i<=n; i++){
        num = "";
        s = "";
        t = "";
        cin>>z;
        bool fl = false;
        for(auto it: z){
            if(it == ' '){
                fl = true;
                continue;
            }
            if(!fl) s += it;
            else t += it;
        }
        for(auto it: t){
            if(it - '0' > 9) suff += it;
            else num += it;
        }
        mp[s].insert(atoi(num.c_str()));
    }
    num = "";
    s = "";
    t = "";

    cin>>z;
    bool fl = false;
    for(auto it: z){
        if(it == ' '){
            fl = true;
            continue;
        }
        if(!fl) s += it;
        else t += it;
    }

    for(auto it: t){
        if(it - '0' > 9) suff += it;
        else num += it;
    }


    string month = s;
    int val = rmp[month];
    if(mp[month].upper_bound(atoi(num.c_str())) != mp[month].end()){
        cout<<"Case #"<<case_<<": "<<month<<" "<<(*mp[month].upper_bound(atoi(num.c_str())))<<suffix(*mp[month].upper_bound(atoi(num.c_str())));
        return;
    }

    for(int i=val+1; i<12; i++){
        if(mp[mths[val]].size()){
            auto it = mp[mths[val]].begin();
            cout<<"Case #"<<case_<<": "<<mths[val]<<" "<<*it<<suffix(*it);
            return;
        }
    }

    cout<<"Case #"<<case_<<": "<<"See you next year";
    return;
}

int main(){
    int t;
    cin>>t;
    int val = 0;
    for(auto m: mths){
        rmp[m] = val++;
    }
    for(int i=1; i<=t; i++){
        solve(i);
        cout<<endl;
    }
    return 0;
}
