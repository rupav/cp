#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

int rev(int i, int n){
    return (n-i-1);
}

int update(int **res, vector<pair<int, int>> &v, priority_queue<pair<int, int>>& pq, int n){
    pair<int, int> ce = pq.top();
    pq.pop();
    if(ce.first >= n){
        fr(i, n){
            res[v[i].first][v[i].second] = ce.second;
        }
        ce.first -= n;
        pq.push(ce);  /// even with negative freq, it will never come up again!
    } else {
        cout<<"NO";
        return 0;
    }
    return 1;
}

int main(){
    int n;
    cin>>n;
    int val;

    unordered_map<int, int> mp;
    fr(i, n*n){
        cin>>val;
        mp[val]++;
    }

    unordered_map<int, int>::iterator it = mp.begin();
    priority_queue<pair<int, int>> pq;

    while(it != mp.end()){
        pq.push({it->second, it->first});
        it++;
    }

    /// dp based solution, solve for the first quad, and mid, and the center element separately.
    int m = n/2;



    int **res = new int*[n];
    fr(i, n){
        res[i] = new int[n];
    }

    fr(i, m){
        fr(j, m){
            vector<pair<int, int>> v = {{i, rev(j, n)}, {i, j}, {rev(i, n), rev(j, n)}, {rev(i, n), j}};
            if(!update(res, v, pq, 4))
                return 0;
        }
    }

    if(n&1){
        /// fill up the + sign elements!
        fr(i, m){
            vector<pair<int, int>> v = {{i, m}, {rev(i, n), m}};
            if(!update(res, v, pq, 2))
                return 0;
            v = {{m, i}, {m, rev(i, n)}};
            if(!update(res, v, pq, 2))
                return 0;
        }

        vector<pair<int, int>> v = {{m, m}};
        if(!update(res, v, pq, 1))
            return 0;
    }

    cout<<"YES";
    fr(i, n){
        cout<<endl;
        fr(j, n){
            cout<<res[i][j]<<" ";
        }
    }

    return 0;
}
