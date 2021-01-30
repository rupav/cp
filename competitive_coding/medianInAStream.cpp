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
    priority_queue<int> l;  /// max Heap to store elements of lower half of the resulting array.
    priority_queue<int, vector<int>, greater<int>> u;  /// min Heap to store elements of upper half of the resulting array.
    double m;
    int x;
    cin>>x;
    m = (double)x;
    cout<<m<<endl;
    l.push(x);
    n-=1;
    while(n--){
        cin>>x;
        if(l.size() > u.size()){
            if(x < m){
                /// then x must belong to lower half of the current array.
                u.push(l.top());  /// since l.top() is the deserving candidate to be in the upper half.
                l.pop();
                l.push(x);
            } else {
                u.push(x);
            }
            m = (double) ((l.top()+u.top())/2);
        } else if (l.size() < u.size()){
            if(x > m){
                l.push(u.top());
                u.pop();
                u.push(x);
            } else {
                l.push(x);
            }
            m = (double) ((l.top()+u.top())/2);
        } else {
            /// both have same number of elements!
            if(x > m){
                u.push(x);
                m = (double) u.top();
            } else {
                l.push(x);
                m = (double) l.top();
            }
        }
        cout<<m<<endl;
    }
    return 0;
}

