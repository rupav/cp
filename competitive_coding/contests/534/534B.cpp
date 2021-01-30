#include<bits/stdc++.h>
using namespace std;



int findAns(string s, int n){
    unordered_map<int, bool> myMap;  // checks if myMap[i] is already deleted or not!
    int count = 0;
    int deleted = 0;
    int flag = 1;  /// continue for passes.
    for(int i=0; i<n; i++)
        myMap[i] = false;

    for(int i=0; i<n; i++){
        if(deleted == n){
            break;
        }
        for(int j=0; j<n-1; j++){
            /// find consecutive elements not yet deleted.
            if(myMap[j] == false){
                /// find next non-deleted element.
                int k=j+1;
                while(k<n && myMap[k] == true){
                    k++;
                }
                if(k==n){
                    flag = 0;
                    break;
                } else {
                    if(s[j] == s[k]){
                        deleted += 2;
                        count++;
                        myMap[j] = true;
                        myMap[k] = true;
                        break;
                    }
                }
            }
        }
        if(flag == 0){
            break;
        }
    }

    return count;
}

int findAnsThroughStack(string s, int n){
    stack<int> myStack;
    myStack.push(0);
    int count = 0;
    for(int i=1; i<n; i++){
        if(!myStack.empty() && s[myStack.top()] == s[i]){
            myStack.pop();
            count++;
        } else {
            myStack.push(i);
        }
    }
    return count;
}

int main(){
    string s;
    cin>>s;
    int n = s.size();
    if(findAnsThroughStack(s, n)%2){
        cout<<"Yes";
    } else {
        cout<<"No";
    }
    return 0;
}
