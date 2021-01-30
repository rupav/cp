#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

int main(){
    int n;
    cin>>n;
    int arr[n+1];
    int pos = -1;
    int maxfr = 0;
    int maxf = 0;
    map<int, int> mp;
    rep(i, 1, n){
        cin>>arr[i];
        mp[arr[i]]++;
        if(mp[arr[i]] > maxfr){
            maxfr = mp[arr[i]];
            maxf = arr[i];
            pos = i;
        }
    }
    map<int, bool> mb;
    /// make partitions araound maxf element.
    vector<int> v;
    rep(i, 1, n){
        if(arr[i] == maxf)
            v.push_back(i);
    }
    int prev = 1;

    cout<<n-maxfr<<endl;

    for(auto p: v){
        //cout<<"p "<<p<<endl;
        // cout<<"prev "<<prev<<endl;
        for(int i=p-1; i>=prev; i--){
            if(arr[i] == maxf)
                break;
            if(arr[i] > maxf){
                cout<<2<<" ";
            } else {
                cout<<1<<" ";
            }
            cout<<i<<" "<<i+1<<endl;
        }
        prev = p;
    }
    for(int i=prev; i<n; i++){
        if(arr[i+1] > maxf){
            cout<<2<<" ";
        } else {
            cout<<1<<" ";
        }
        cout<<i+1<<" "<<i<<endl;
    }
    return 0;
}

