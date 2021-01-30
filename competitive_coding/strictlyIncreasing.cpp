#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int longestIncreasingSequence(int *arr, int n){
        int count = 0;
        int len = 0;
        int prev = INT_MIN;
        for(int i=0; i<n; i++){
            if(arr[i] > prev){
                len++;
            } else {
                count = max(len, count);
                len = 1;
            }
            prev = arr[i];
        }
        return max(count, len);
    }
};

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    Solution ans;
    cout<<ans.longestIncreasingSequence(arr, n);
    return 0;
}
