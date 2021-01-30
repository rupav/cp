#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

struct Node{
    int prev;
    int next;
    int val;
};

int main(){
    int n, k;
    cin>>n>>k;
    Node s[n+1];
    /// reverse mapping reqd!
    int pos[n+1] = {0};
    rep(i, 1, n){
        cin>>s[i].val;
        s[i].prev = i-1;
        s[i].next = i+1;
        pos[s[i].val] = i;
    }
    bool flag = true;
    int ans[n+1] = {0};
    for(int i=n; i>0; i--){
        if(ans[pos[i]] == 0){
            /// available to pick up!
            int t = (flag) ? 1: 2;
            int p = pos[i];

            ans[p] = t;
            int temp = k;
            int ind = s[p].prev;
            while(ind != 0 && temp!=0){
                ans[ind] = t;
                ind = s[ind].prev;
                temp--;
            }
            int unmarked = ind;

            temp = k;
            ind = s[p].next;
            while(ind != n+1 && temp!=0){
                ans[ind] = t;
                ind = s[ind].next;
                temp--;
            }
            if(unmarked != 0){
                s[unmarked].next = ind;
            }
            if(ind != 0){
                s[ind].prev = unmarked;
            }
            flag = !flag;
        }
    }
    rep(i, 1, n)
        cout<<ans[i];
    return 0;
}

