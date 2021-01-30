#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;

/// greedy approach - idea is ti scale up to higher no. if there are many higher no.s on the right side.
/// dry run on - 2, 2, 4 & 2, 2, 4, 4, 4
int minDecIncNonIncreasing(int *a, int n){
    priority_queue<int, vector<int>, greater<int> > pq;
    int sum = 0;
    fr(i, n){
        if(!pq.empty() && pq.top() < a[i]){
            sum += a[i] - pq.top();  /// these 2 numbers are scaled up now theoretically.
            pq.pop();  /// remove the smaller of two numbers.
            pq.push(a[i]);  /// add the bigger number for the race of new minimum.
        }
        pq.push(a[i]);
    }
    return sum;
}

// Driver Code
int main()
{
    int n;
    cin>>n;
    int arr[n];
    fr(i, n) cin>>arr[i];

    cout << minDecIncNonIncreasing(arr, n);

    return 0;
}
