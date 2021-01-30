#include<bits/stdc++.h>
using namespace std;

bool Compare(){
    return 3 > 4;
}

int main(){
    auto x = 3.7;
    int y;
    cout<<typeid(x).name()<<endl;
    cout<<typeid(y).name()<<endl;
    decltype(&Compare) z;
    cout<<typeid(z).name();
}
