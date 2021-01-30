#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
    string s, t;
    cin>>s>>t;
    int n = s.size();
    int m = t.size();
    if(n!=m){
        cout<<"No";
    }else{
        int flag = 1;
        for(int i=0; i<n; i++){
            if(s[i]=='a' || s[i]=='o' || s[i]=='e' || s[i]=='u' || s[i]=='i'){
                if(t[i]=='a' || t[i]=='o' || t[i]=='e' || t[i]=='u' || t[i]=='i'){
                    continue;
                } else {
                    flag = 0;
                    break;
                }
            } else {
                if(t[i]=='a' || t[i]=='o' || t[i]=='e' || t[i]=='u' || t[i]=='i'){
                    flag = 0;
                    break;
                } else {
                    continue;
                }
            }
        }
        if(flag == 0){
            cout<<"No";
        } else {
            cout<<"Yes";
        }
    }
    return 0;
}
