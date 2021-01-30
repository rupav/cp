#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define DEBUG false
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;
int ALL_PERSON;
vector<vector<int> > v;  /// for reverse mapping from TShirt to persons.
ll dp[1025][110];

int stoi(string &s){
    stringstream ss(s);
    int t;
    ss>>t;
    return t;
}

ll calc(int mask, int tid){
    /// mask is for person who have already wore tshirts, from tids < tid.
    if(mask == ALL_PERSON){
        return 1;
    }

    if(tid > 100){
        return 0;
    }

    if(dp[mask][tid] != -1)
        return dp[mask][tid];

    ll &ans = dp[mask][tid];
    ans = 0;
    ans += calc(mask, tid+1);  /// ignoring TID to be assigned to any person.

    for(auto p: v[tid]){
        p--;
        if((mask&(1<<p)) == 0){
            /// i.e. person p, is yet to wear a TSHIRT.
            ans += calc( (mask|(1<<p)), tid+1);
        }
    }

    ans %= mod;
    return ans;
}

int main(){
    v.reserve(110);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        ALL_PERSON = (1<<n) - 1;

        string str;

        memset(dp, -1, sizeof(dp));
        for(int i=0; i<=100; i++){
            v[i].clear();
        }

        cin.ignore();
        rep(i, 1, n){
            getline(cin, str);
            stringstream ss(str);
            string temp;
            while(ss >> temp){
                v[stoi(temp)].push_back(i);
            }
        }

        for(int i=1; i<=100; i++){
            sort(v[i].begin(), v[i].end());
            if(v[i].size()>0 && DEBUG){
                cout<<i<<": ";
                for(auto p: v[i]){
                    cout<<p<<", ";
                }
                cout<<endl;
            }
        }

        cout<<calc(0, 1)<<endl;
    }
    return 0;
}
