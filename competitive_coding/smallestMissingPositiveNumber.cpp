#include<bits/stdc++.h>
using namespace std;

void seperatePN(int *arr, int n){
    int i=0, j=n-1;
    while(i <= j){
        if(arr[i] <= 0){
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            j--;
        } else i++;
    }
    return;
}

int main()
 {
        int t,n;
        cin>>t;
        while(t--) {
            cin>>n;
            int arr[n];
            for(int i=0; i<n; i++){
                cin>>arr[i];
            }
            seperatePN(arr, n);
            int pos = 0;
            while(pos<n && arr[pos] > 0) pos++;


            for(int i=0; i<pos; i++){
                if(abs(arr[i])-1 < pos){
                    arr[abs(arr[i])-1] = -1*(abs(arr[abs(arr[i])-1]));
                }
            }


            int ans;
            bool flag = false;
            for(int i=0; i<pos; i++){
                if(arr[i] > 0){
                    flag = true;
                    ans = i+1;
                    break;
                }
            }
            if(!flag) ans = pos+1;
            cout<<ans<<endl;
        }
	//code
	return 0;
}
