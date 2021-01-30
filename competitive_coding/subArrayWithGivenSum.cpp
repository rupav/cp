#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

/// for non-negative array elements only, window method - O(n) approach.
pair<int, int> nonNegativeSubArrayWithGivenSum(int *arr, int n, ll sum){
    int i=0;
    int j=0;
    ll temp_sum = arr[0];
    while(j<n){
        if(temp_sum == sum){
            return make_pair(i+1, j+1);  /// 1-based index values.
        } else if (temp_sum < sum){
            j++;
            if(j == n) break;
            temp_sum += arr[j];
        } else {
            temp_sum -= arr[i];
            i++;
        }
    }
    return make_pair(-1, -1);
}

/// for general case, (-ve and +ve elements) - O(n) approach, using sum_so_far and map!
pair<int, int> subArrayWithGivenSum(int *arr, int n, ll sum){
    map<ll, int> mp;
    ll sum_so_far = 0;
    fr(i, n){
        sum_so_far += arr[i];
        if(sum_so_far == sum){
            return make_pair(1, i+1);
        }
        if(mp.count(sum_so_far - sum)){
            return make_pair(mp[sum_so_far - sum]+1, i+1);
        }
        mp[sum_so_far] = i+1;
    }
    return make_pair(-1, -1);
}

int main(){
    int n;
    cin>>n;
    ll sum;
    cin>>sum;
    int arr[n];
    bool flag = true;  /// indicating with positive elements only
    fr(i, n){
        cin>>arr[i];
        if(arr[i]<0)
            flag = false;
    }

    pair<int, int> pp = (flag) ? nonNegativeSubArrayWithGivenSum(arr, n, sum) : subArrayWithGivenSum(arr, n, sum);
    cout<<pp.first<<" "<<pp.second;
    return 0;
}

