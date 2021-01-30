#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;
vector<int> factors(101);

void ConstructFactors(int n){
    int k = 0;
    rep(i, 2, n){
        if(n%i==0)
            factors[k++] = i;
    }
    factors[k] = -1;
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    int minE = INT_MAX;
    int sum = 0;
    fr(i, n){
        cin>>arr[i];
        minE = min(minE, arr[i]);
        sum += arr[i];
    }

    int res = sum;
    int b1, b2;
    int r1, r2;
    fr(i, n){
        if(arr[i] != minE){
            ConstructFactors(arr[i]);
            int k=0;
            while(factors[k++] != -1){
                int j = factors[k-1];
                if(true || j*minE < arr[i]){
                    b1 = j;
                    b2 = arr[i]/b1;
                    r1 = sum + b1*minE - minE + arr[i]/b1 - arr[i];
                    r2 = sum + b2*minE - minE + arr[i]/b2 - arr[i];
                    res = min(res, min(r1, r2));
                }
            }
        }
    }
    cout<<res;
    return 0;
}
