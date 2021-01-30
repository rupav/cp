#include<bits/stdc++.h>
using namespace std;

#define fr(i, n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    string s;
    cin>>s;
    int n = s.size();
    bool ans[n-1];
    int p_sum[n-1] = {0};
    int sum = 0;
    fr(i, n-1){
        ans[i] = (s[i] == s[i+1]);
        p_sum[i] = ans[i]+sum;
        sum = p_sum[i];
    }


    int m;
    cin>>m;
    int x, y;
    fr(i, m){
        cin>>x>>y;
        x--;
        y--;
        if(x)
            cout<<p_sum[y-1] - p_sum[x-1]<<endl;
        else
            cout<<p_sum[y-1]<<endl;
    }

    return 0;
}
