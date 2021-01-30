#include<bits/stdc++.h>
using namespace std;

void print(int n)
{
    // array to store binary number
    int binaryNum[32] = {0};

    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // printing binary array in reverse order
    for (int j = 31; j >= 0; j--)
        cout << binaryNum[j];
}

void submasks(int m){
    for(int s=m; s!=0; s = ((s-1)&m)){
        print(s);
        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    submasks(n);
    return 0;
}
