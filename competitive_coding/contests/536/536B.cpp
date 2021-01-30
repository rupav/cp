#include<bits/stdc++.h>
using namespace std;
/// using ll = long long;
typedef long long ll;

struct dishes{
    int index;
    int cost;
    int rem;
};

bool Compare(dishes a, dishes b){
    return (a.cost > b.cost);
};

int main(){
    int n,m;
    cin>>n>>m;
    priority_queue<dishes, vector<dishes>, decltype(&Compare)> minHeap(Compare);

    dishes dish[n];

    for(int i=0; i<n; i++)
        cin>>dish[i].rem;

    for(int i=0; i<n; i++){
        cin>>dish[i].cost;
        dish[i].index = i+1;
        minHeap.push(dish[i]);
    }

    int t, d;

    long int sum = 0;
    for(int i=0; i<m; i++){
        unsigned long long int totalCost = 0;
        cin>>t>>d;
        if(dish[t-1].rem >= d){
            totalCost += 1ll*(dish[t-1].cost)*d;  /// type casting, by multiplying with 1ll
            dish[t-1].rem -= d;
            d=0;
        } else {
            totalCost += 1ll*(dish[t-1].cost)*(dish[t-1].rem);
            d -= dish[t-1].rem;
            dish[t-1].rem = 0;

            while(d>0){
                while(minHeap.size()){
                    dishes cheapestDish = minHeap.top();
                    t = cheapestDish.index-1;
                    if(dish[t].rem >= d){
                        totalCost += 1ll*(dish[t].cost)*d;
                        dish[t].rem -= d;
                        d=0;
                        break;  /// break out of loop
                    } else {
                        totalCost += 1ll*(dish[t].cost)*(dish[t].rem);
                        d -= dish[t].rem;
                        dish[t].rem = 0;
                        minHeap.pop();
                    }
                }
                if(d){
                    totalCost = 0;
                    break;
                }
            }

        }
        cout<<totalCost<<endl;
        // sum += totalCost;

    }

    // cout<<sum<<endl;

    return 0;
}
