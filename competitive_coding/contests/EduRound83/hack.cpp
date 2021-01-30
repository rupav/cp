#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pi acos(-1)
#define mod 1000000009
#define all(x) x.begin(), x.end()
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int k = 1;
        while(k < 100){
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    if(a[i] + j - i == a[j]){
                        swap(a[i], a[j]);
                    }
                }
            }
            k++;
        }
        for(auto it : a){
            cout << it << " ";
        }
        cout << endl;
    }
}
