/// https://codeforces.com/problemset/problem/817/D
/// finding sum of all subsegments' min and max, n is of order 10^6
#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+1;
int a[N], L[N], R[N];
typedef long long ll;

void fill_(int n){
    stack<int> s;
    for(int i=1; i<=n; i++) L[i] = 0;
    for(int i=1; i<=n; i++) R[i] = n+1;

    for(int i=1; i<=n; i++){
        while(s.size() && a[s.top()] > a[i]) s.pop();
        if(s.size()) L[i] = s.top();  // rightmost index, s.top() s.t. a[s.top()] <= a[i]
        s.push(i);
    }

    while(s.size()) s.pop();

    for(int i=n; i>=1; i--){
        while(s.size() && a[s.top()] >= a[i]) s.pop();
        if(s.size()) R[i] = s.top();  // leftmost index, s.top() s.t. a[s.top()] < a[i]
        s.push(i);
    }
}

int main(){
    int n;
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];

    fill_(n);
    ll min_sum = 0ll;
    for(int i=1; i<=n; i++){
        min_sum += 1ll*a[i]*(1ll*i - 1ll*L[i])*1ll*(1ll*R[i] - 1ll*i);
    }

    for(int i=1; i<=n; i++) a[i] *= -1;
    fill_(n);
    ll max_sum = 0ll;
    for(int i=1; i<=n; i++){
        max_sum += 1ll*abs(a[i])*(1ll*i - 1ll*L[i])*1ll*(1ll*R[i] - 1ll*i);
    }

    cout<<max_sum - min_sum;

    return 0;
}


