#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    char temp;
    int mat[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>temp;
            if(temp=='X'||temp=='x')
                mat[i][j] = 1;
            else
                mat[i][j] = 0;
        }
    }
    int count = 0;
    for(int i=1; i<n-1; i++){
        for(int j=1; j<n-1; j++){
            if(mat[i][j] && mat[i-1][j-1] && mat[i-1][j+1] && mat[i+1][j-1] && mat[i+1][j+1]){
                count++;
            }
        }
    }

    cout<<count<<endl;

    return 0;
}
