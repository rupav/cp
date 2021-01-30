///  Equations of Mathematical Magic
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int setBits = __builtin_popcount(n);
        cout<<(1<<setBits)<<endl;
    }
    return 0;
}
