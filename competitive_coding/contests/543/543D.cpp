#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;


int main(){
    int m, k, n, s;
    cin>>m>>k>>n>>s;
    int arr[m];
    fr(i, m){
        cin>>arr[i];
    }
    int des[s];
    unordered_map<int, int> mp;
    fr(i, s){
        cin>>des[i];
        mp[des[i]] ++;
    }

    int count = 0;
    int temp = m - n*k;
    if(s>k){
        cout<<-1;
        return 0;
    }
    int req = s;
    unordered_map<int, int> cmp = mp;  /// copy of freq map.
    int res[1000];
    int l = 0;
    fr(i, m){
        if(cmp[arr[i]]>0){
            cmp[arr[i]] --;
            req--;
        } else {
            res[l++] = i+1;
        }
        if(req == 0){
            /// found!
            cout<<0;
            return 0;
        }
        if((i+1)%k == 0){
            /// move more temp steps;
            int j = i+1;
            while(temp!=0 && j<m){
                if(cmp[arr[j]]>0){
                    cmp[arr[j]] --;
                    req--;
                    res[l++] = j;
                } else {
                    res[l++] = j+1;
                }
                if(req == 0){
                    /// found!
                    cout<<j-i<<endl;
                    for(int x = 0; x<j-i; x++){
                        cout<<res[x]<<" ";
                    }
                    return 0;
                }
                j++;
                temp--;
            }
            cmp = mp;
            /// refresh
            temp = m - n*k;
            req = s;
            l = 0;
        }
    }

    cout<<-1;

    return 0;
}

