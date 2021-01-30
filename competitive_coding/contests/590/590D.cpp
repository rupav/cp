/// code can be improved by using 26 size BITs: refer - https://codeforces.com/contest/1234/submission/61679129
#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;  /// prime number

int conv(char c){
    return (int)(c-'a');
}

struct Node{
    int cnt[26];
};

Node BIT[100005];

int getNext(int i, int n){
    i += i&(-i);
    return i;
}

void modifyBIT(int n, int i, int x, int y){
    while(i <= n){
        BIT[i].cnt[x] = max(0, BIT[i].cnt[x]-1);
        BIT[i].cnt[y]++;
        i = getNext(i, n);
    }
}

/// updateBIT is a O(logn) operation
void updateBIT(int n, int i, int update){
    BIT[i].cnt[update]++;
    int next = getNext(i, n);
    while(next<=n){
        BIT[next].cnt[update]++;
        next = getNext(next, n);
    }
}

/// constructBIT is a O(n*logn) operation
void constructBIT(int n, int *arr){
    fr(i, n+1) fr(j, 26) BIT[i].cnt[j] = 0;
    fr(i, n) updateBIT(n, i+1, arr[i]);
}

int getParent(int i, int n){
    i -= i&(-i);
    return i;
}

/// getSum is a O(logn) operation
/// count occurences of a character only once, while travelling upwards.
map<int, int> getSum(int n, int i){
    int sum = 0;
    map<int, int> mp;
    fr(j, 26){
        if(BIT[i].cnt[j] >= 1) {
            mp[j] += BIT[i].cnt[j];
        }
    }
    int parentIndex = getParent(i, n);
    while(parentIndex>0){
        fr(j, 26){
            if(BIT[parentIndex].cnt[j] >= 1){
                mp[j] += BIT[parentIndex].cnt[j];
            }
        }
        parentIndex = getParent(parentIndex, n);
    }
    return mp;
}

int getCount(int x, int y, int n){
    map<int, int> m1 = getSum(n, x-1);
    map<int, int> m2 = getSum(n, y);
    map<int, int> ans;
    fr(i, 26) ans[i] = m2[i] - m1[i];
    int count = 0;
    fr(i, 26) if(ans[i]>=1) count++;
    return count;
}

void print(int n){
    return;
    fr(i, n+1) {
        cout<<i<<": ";
        fr(j, 26) cout<<BIT[i].cnt[j]<<" ";
        cout<<endl;
    }
}

int main(){
    string s;
    cin>>s;
    int n, q;
    n = s.size();
    int arr[n];

    fr(i, n){
        arr[i] = conv(s[i]);
    }

    constructBIT(n, arr);
    print(n);
    cin>>q;
    int t;
    int x, y;
    char z;
    while(q--){
        cin>>t;
        if(t == 1){
           cin>>x;
           x--;
           cin>>z;
           modifyBIT(n, x+1, arr[x], conv(z));
           arr[x] = conv(z);
           print(n);
        } else {
            cin>>x>>y;
            cout<<getCount(x, y, n)<<endl;
        }
    }
}
