#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;


int main(){
    int n, m;
    cin>>n>>m;
    if(m%n != 0){
        cout<<-1;
        return 0;
    }
    int ans = m/n;
    int count3 = 0;
    int count2 = 0;
    int temp = ans;

    bool flag = false;

    while(true){
        flag = false;
        if(temp%3 == 0){
            temp/=3;
            count3++;
            flag = true;
        }
        if(temp%2 == 0){
            temp/=2;
            count2++;
            flag = true;
        }
        if(flag == false)
            break;
    }

    if(temp == 1){
        cout<<count3 + count2;
    } else {
        cout<<-1;
    }

    return 0;
}

