#include<bits/stdc++.h>
using namespace std;

class Solution{
    int n;
public:
    int longestConsecutives1s(vector<int> &arr){
        n = arr.size();
        int i(0), flip(-1), len(0), ans(INT_MIN);
        while(i<n){
            if(arr[i]) len++;
            else {
                if(flip == -1){
                    flip = i;
                    len++;
                } else {
                    /// break the length here!
                    ans = max(ans, len);
                    len = i - flip;
                    flip = i; /// including current 0 in the new ans!
                }
            }
            i++;
        }
        ans = max(len, ans);
        return ans;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    Solution ans;
    cout<<ans.longestConsecutives1s(v)<<endl;
    return 0;
}
