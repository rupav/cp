#include<iostream>
using namespace std;

int main(){

    int a;
    cout<<"Enter 1 number";
    cin>>a;
    int rem = 0;
    int rev = 0;
    while(a!=0){
        rem = a%10;
        rev = rev*10 + rem;
        a = a/10;
    }
    cout<<rev;
}
