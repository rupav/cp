#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;


int main(){
    int n, m, k;
    cin>>n>>m>>k;
    vector<pii> a(n);
    int *arr = new int[n];
    fr(i, n){
        cin>>a[i].first;
        arr[i] = a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end(), greater<pii>());
    /// now we have got the first m*k greater elements;
    ll beautySum = 0;
    unordered_map<int, int> mp;  /// for storing freq. of m*k elements;
    fr(i, m*k){
        beautySum += a[i].first;
        mp[a[i].first]++;
    }
    /// now to calculate divisions. - https://codeforces.com/blog/entry/65136?#comment-491791
    cout<<beautySum<<endl;
    int count = 0;
    fr(i, n){
        if(mp[arr[i]]){
            count ++;
            mp[arr[i]] --;
            if(count==m && k>1){
                cout<<i+1<<" ";
                count = 0;
                k--;
            }
        }
    }
    return 0;
}
