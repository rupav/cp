#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

queue<int>* returnAntiDiagonals(int **mat, int n){
    queue<int> *ms = new queue<int>[2*n-1];
    fr(i, n){
        fr(j, n){
            ms[i+j].push(mat[i][j]);
        }
    }
    return ms;
}

int main(){
        int t,n;
        cin>>t;
        while(t--) {
            cin>>n;
            int **mat = new int *[n];
            fr(i, n){
                mat[i] = new int[n];
                fr(j, n)
                    cin>>mat[i][j];
            }
            queue<int>* ms = returnAntiDiagonals(mat, n);
            for(int i=0; i<=2*n-2; i++){
                queue<int> m = ms[i];
                while(!m.empty()){
                    cout<<m.front()<<" ";
                    m.pop();
                }
            }
            cout<<endl;
        }
	//code
	return 0;
}
