#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;


int main(){
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        int t;
        t = s.size();
        bool flag = true;
        int table[26] = {0};
        for(auto c: s){
            if(table[c-'a'] > 0){
                cout<<"No"<<endl;
                flag = false;
                break;
            } else {
                table[c-'a']++;
            }
        }
        if(flag){
            int pos = 0;
            for(int i=0; i<26; i++){
                if(table[i]!=0){
                    pos = i;
                    break;
                }
            }
            bool f = true;
            for(int j=pos; j<pos+t; j++){
                if(!table[j]){
                    cout<<"No"<<endl;
                    f = false;
                    break;
                }
            }
            if(f)
                cout<<"Yes"<<endl;
        }
    }
    return 0;
}

