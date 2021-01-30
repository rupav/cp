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
    string s;
    cin>>s;
    int count = 0;
    char ans[n];
    char prev = s[0];
    int curr = 0;
    int len = 0;
    int i = 1;
    int k = 0;
    ans[k++] = s[0];

    while(i<n){
        len = 0;
        while(i<n && s[i] == prev){
            len++;
            i++;
        }
        count += len;
        if(i == n){
            break;
        }

        ans[k++] = s[i];
        prev = s[i+1];
        if(i+1 < n)
            ans[k++] = s[i+1];
        i+=2;
    }

    if(k%2 == 0){
        cout<<count<<endl;
        fr(i, k)
            cout<<ans[i];
    } else {
        cout<<count+1<<endl;
        fr(i, k-1)
            cout<<ans[i];
    }

    return 0;
}

