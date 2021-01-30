
#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pll;
ll mod = 1e9+7;

ll gcdll(ll a, ll b){
    if(!b) return a;
    return gcdll(b, a%b);
}

int gcd(int a, int b){
    if(!b) return a;
    return  gcd(b, a%b);
}

void seive(int n){
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;

    for(int i=2; i*i<=n; i++){
        if(is_prime[i]){
            for(int j=i*i; j<=n; j+=i){
                is_prime[j] = false;
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    pll arr[n];
    fr(i, n){
        cin>>arr[i].first;
        arr[i].second = i+1;
    }
    sort(arr, arr+n);
    /// finding the d.

    map<ll, ll> mp;
    ll minKey = -1;
    ll minCount = INT_MAX;
    rep(i, 1, n-1){
        mp[arr[i].first - arr[i-1].first]++;
        if(mp.size() > 3){
            cout<<-1;
            return 0;
        }
    }

    if(mp.size() == 3 || mp.size() == 2){
        bool global = false;
        for(auto it: mp){
            global = false;
            /*
            if(it.second < minCount){
                minCount = it.second;
                minKey = it.first;
            }
            */
        // }
            minKey = it.first;

            int culprit = -1;
            rep(i, 1, n-1){
                if(arr[i].first - arr[i-1].first == minKey){
                    //culprits[0] = i-1;
                    culprit = i;
                    break;
                }
            }

            map<ll, ll> rmp;
            bool flag = true;
            for(int i=1; i<n; ){
                if(i == culprit){
                    if(i+1 < n) rmp[arr[i+1].first - arr[i-1].first]++;
                    i += 2;
                } else {
                    rmp[arr[i].first - arr[i-1].first]++;
                    i++;
                }
                if(rmp.size() > 1){
                    flag = false;
                    break;
                }
            }
            if(flag){
                cout<<arr[culprit].second;
                return 0;
            } else {
                /// remove 1st element.
                map<ll, ll> zmp;
                rep(i, 2, n-1){
                    zmp[arr[i].first - arr[i-1].first]++;
                    if(zmp.size() > 1){
                        //cout<<-1;

                        //return 0;
                        global = true;
                    }
                }
            }
            if(!global){
                cout<<arr[0].second;
                return 0;
            }
        }
        cout<<-1;
        return 0;
    } else {
        cout<<arr[0].second;
    }

    return 0;
}
