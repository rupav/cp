#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        int sum = 0;
        for(int i=0; i<str.size(); i++){
            if(isdigit(str[i])){
                sum += int(str[i] - '0');
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
