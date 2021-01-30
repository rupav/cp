#include<bits/stdc++.h>
using namespace std;

int main(){
    int q;
    int l1, l2, r1, r2;
    cin>>q;
    while(q--){
        cin>>l1>>r1>>l2>>r2;
        if(l1 == l2){
            cout<<l1<<" "<<l2+1;
        } else {
            cout<<l1<<" "<<l2;
        }
        cout<<endl;
    }
    return 0;
}
