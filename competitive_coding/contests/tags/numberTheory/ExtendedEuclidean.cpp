#include<bits/stdc++.h>
using namespace std;

/// solves ax + by = gcd(a, b)
int gcdExtended(int a, int b, int &x, int &y){
    if(a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = gcdExtended(b%a, a, x1, y1);
    x = y1 - (b/a)*x1;
    y = x1;
    return d;
}

int main(){
    int x, y, a, b;
    cin>>a>>b;
    cout<<gcdExtended(a, b, x, y)<<endl;
    cout<<"Solving ax + by = gcd"<<endl;
    cout<<"x: "<<x<<endl;
    cout<<"y: "<<y<<endl;
    return 0;
}

