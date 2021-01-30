#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, x, y, z;
    cin>>a>>b>>c>>x>>y>>z;
    int *arr = new int[3];
    int p1 = a-x >= 0? (a-x) / 2: a-x; /// - value indicates this color requires more ball than currently
    int p2 = b-y >= 0? (b-y) / 2: b-y;
    int p3 = c-z >= 0? (c-z) / 2: c-z;

    arr[0] = p1;
    arr[1] = p2;
    arr[2] = p3;

    int result = 0;
    for(int i=0; i<3; i++){
        if(arr[i]<0){
            result += arr[i];
        } else {
            result += arr[i];
        }
    }

    if(result>=0){
        cout<<"Yes";
    } else {
        cout<<"No";
    }

    return 0;
}
