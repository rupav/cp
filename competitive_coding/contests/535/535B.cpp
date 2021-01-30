#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    unordered_map<int, int> myMap;

    int secondLargest = INT_MIN;
    cin>>arr[0];
    for(int i=1; i<n; i++){
        cin>>arr[i];
    }

    int max = arr[0];
    myMap[arr[0]] = 1;
    for(int i=1; i<n; i++){
        if(!myMap[arr[i]]){
            myMap[arr[i]] = 1;
        } else {
            myMap[arr[i]] += 1;
        }
        if(arr[i] > max){
            secondLargest = max;
            max = arr[i];
        } else if (arr[i] > secondLargest){
            secondLargest = arr[i];
        }else{
            continue;
        }
    }
    /// cout<<"second largest is"<<secondLargest;

    int y = INT_MIN;
    if(secondLargest!=INT_MIN && max % secondLargest != 0){
        cout<<max<<" "<<secondLargest;
    } else {
        // find second largest such that its freq. is 2
        for(int i=0; i<n; i++){
            if(max%arr[i] != 0 && arr[i] > y){
                y = arr[i];
            } else if(myMap[arr[i]] > 1 && arr[i]>y){
                y = arr[i];
            } else {
                continue;
            }
        }
        cout<<max<<" "<<y;
    }

    return 0;
}
