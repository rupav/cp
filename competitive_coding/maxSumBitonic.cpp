#include<iostream>
using namespace std;
int main()
 {
        int t,n;
        cin>>t;
        while(t--) {
            cin>>n;
            int *arr = new int[n];
            int msis[n];  // max sum increasing subsequence.
            int msds[n];  // max sum decreasing susequence.

            for(int i=0; i<n; i++){
                cin>>arr[i];
                msis[i] = msds[i] = arr[i];
            }

            for(int i=0; i<n; i++){
                for(int j=0; j<i; j++){
                    if(arr[i]>arr[j] && msis[i]<msis[j] + arr[i]){
                        msis[i] = msis[j] + arr[i];
                    }
                }
            }

            for(int i=n-1; i>=0; i--){
                for(int j=n-1; j>i; j--){
                    if(arr[i]>arr[j] && msds[i]<msds[j] + arr[i]){
                        msds[i] = msds[j] + arr[i];
                    }
                }
            }

            int maxs = -1;
            for(int i=0; i<n; i++){
                maxs = max(maxs, msis[i] + msds[i] - arr[i]);
            }
            cout<<maxs<<endl;


        }
	//code
	return 0;
}
