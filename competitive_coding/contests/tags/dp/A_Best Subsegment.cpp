#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++)  cin>>a[i];
    int max_ = *max_element(a.begin(), a.end());
    int i=0;
    int ans = 1;
    while(i<n){
        if(a[i] == max_){
            int j=i+1;
            while(j<n && a[j] == a[i]) j++;
            ans = max(j-i, ans);
            i = j;
        } else i++;
    }
    cout<<ans;
    return 0;
}
