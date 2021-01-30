/// great question idea - refer https://codeforces.com/blog/entry/70233

#include<bits/stdc++.h>
using namespace std;
#define fr(i, n) for(int i=0; i<n; i++)

const int N = 20; /// characters in alphabet, a to t

int f[(1<<20)];  /// to store count of 1s in the mask, because of submasks.
vector<int> oms; /// original masks, max size can be 20*sizeof(string given)

int cnt(int x){
    return __builtin_popcount(x);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    int n = s.size();
    fr(i, 1<<N) f[i] = 0;   /// initialize
    int a[n];
    fr(i, n) a[i] = (int)(s[i] - 'a');

    int freq[N];
    int mask;
    fr(i, n){
        memset(freq, 0, sizeof(freq));
        mask = (1<<a[i]);
        f[mask] = cnt(mask);
        oms.push_back(mask);
        freq[a[i]]++;
        int j=i+1;
        while(j<n && freq[a[j]] == 0){
            mask = mask|(1<<a[j]);
            oms.push_back(mask);
            f[mask] = cnt(mask);
            freq[a[j]]++;
            j++;
        }
    }

    /// now fill all the masks
    fr(mask, (1<<N)){
        fr(i, N){
            if(mask&(1<<i)){
                f[mask] = max(f[mask], f[mask^(1<<i)]);
            } else {
                f[mask] = f[mask]; /// do nothing
            }
        }
    }

    int ans = 0;
    for(auto it: oms){
        mask = it;
        ans = max(ans, f[mask] + f[(1<<N) - 1 - mask]);
    }

    cout<<ans;

    return 0;
}
