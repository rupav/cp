#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c;
    cin>>a>>b>>c;
    int maxE = max(a, max(b, c));
    int sum = a+b+c;
    if(maxE >= sum - maxE){
        cout<<2*maxE - sum + 1;
    } else {
        cout<<0;
    }
    return 0;
}
