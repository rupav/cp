#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int x, y;
        cin>>x>>y;
        int d = abs(x-y);
        int ans = 0;
        int facs[3] = {5, 2, 1};
        for(int i=0; i<3; i++){
            ans += d/facs[i];
            d = d%facs[i];
        }
        cout<<ans<<endl;

    }
    return 0;
}
