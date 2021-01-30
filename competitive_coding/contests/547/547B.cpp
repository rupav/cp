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
    if(n==1){
        cout<<0;
        return 0;
    }
    int arr[n];
    int ans = 0;
    int last_si = 0;
    int si=0;
    bool streak = false;
    cin>>arr[0];

    si = (arr[0] == 1) ? 0 : -1;
    streak = (arr[0] == 1) ? true : false;
    int first_ei = (arr[0] == 1) ? 0 : -1;
    bool oneTime = (arr[0] == 1) ? true : false;


    rep(i, 1, n-1){
        cin>>arr[i];
        if(arr[i] == 0 && streak){
            ans = max(ans, i - si);
            streak = false;
            if(oneTime){
                first_ei = i-1;
                oneTime = false;
            }
        } else if (arr[i] == 1 && !streak){
            streak = true;
            si = i;
            last_si = i;
        }
    }

    if(streak){
        if(first_ei == -1){
            ans = max(ans, n - si);
        } else {
            ans = max(ans, n-si+first_ei+1);
        }
    }

    cout<<ans;
    return 0;
}

