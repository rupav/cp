#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
const int N = 2e5+1;
int p[N], ans[N], pos[N], temp[N];
priority_queue<int> lp;
priority_queue<int, vector<int>, greater<int>> rp; // to maintain median in a running stream

int bit[N];  // to count no. of inversions

void update(int i, int upd){
    for(; i < N; i += i&(-i)) bit[i] += upd;
}

int pref(int i){
    int sum = 0;
    for(; i > 0; i -= i&(-i)) sum += bit[i];
    return sum;
}

int maintain(int x){
    if(!lp.size()) {
        lp.push(x);
        return lp.top();
    }
    if(lp.size() > rp.size()){
        if(x >= lp.top()){
            rp.push(x);
        } else {
            rp.push(lp.top());
            lp.pop();
            lp.push(x);
        }
    } else if (rp.size() > lp.size()){
        if(x <= rp.top()){
            lp.push(x);
        } else {
            lp.push(rp.top());
            rp.pop();
            rp.push(x);
        }
    } else {
        if(x > lp.top()){
            rp.push(x);
            return rp.top();
        } else lp.push(x);
    }
    return lp.top();
}

int sum(int st, int en){
    ll r = (1ll*(en)*(en+1))/2ll;
    st--;
    ll l = (1ll*(st)*(st+1))/2ll;
    return (int)(r - l);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int n;
    cin>>n;
    for(int i=0; i<n; i++) cin>>p[i];
    for(int i=n-1; i>=0; i--){
        pos[p[i]] = i+1;  // 1-based indexing
        temp[p[i]] = pref(p[i] - 1);  // storing no. of element smaller to p[i], to right of it
        ans[n] += temp[p[i]];
        update(p[i], 1);
    }

    // finding count of inversion for each sequence, by removing 1 max element from the current sequence
    int len = n-1;
    while(len){
        int rm = len + 1; // element to be removed
        ans[len] = ans[len+1] - temp[rm];
        len--;
    }

    for(int i=0; i<=n; i++) bit[i] = 0;
    int val = 1, x, med;
    // for each val from 1 to n, minimize swap to make a pack from 1 to val.
    while(val <= n){

        x = pos[val];
        update(x, x);
        med = maintain(x);
        /// ans = sigma(ti - pi) for i <= med + sigma(pi - ti) for i > med
        temp[val] = sum(med - (val - val/2 - 1), med) - sum(med+1, med + val/2);
        temp[val] += ((pref(n) - pref(med)) - (pref(med)));
        ans[val] += temp[val];
        val++;
    }

    for(int i=1; i<=n; i++) cout<<ans[i]<<" ";

    return 0;
}
