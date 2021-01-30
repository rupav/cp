/// In a binary array, find min. of adjacent swaps to bring all 1s together.
#include<bits/stdc++.h>
using namespace std;

int make_a_pack(int a[], int n){
    vector<int> p;
    for(int i=0; i<n; i++) if(a[i]) p.push_back(i);
    /// optimal to choose median element, as the median 1 of the resulting pack
    int sz = p.size();
    int med = sz/2
    /// ans = sigma(ti - pi) for i <= med + sigma(pi - ti) for i > med

}

int main(){

    return 0;
}
