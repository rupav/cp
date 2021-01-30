#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
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

void square(int *arr, int n){
    fr(i, n) arr[i] = arr[i]*arr[i];
}

/// index method!
pii pairSum(int* arr, int n, int x, bool isSorted = true){
    if(!isSorted) sort(arr, arr+n);  /// in case, its not sorted!
    int i, j;
    i=0, j=n-1;
    while(i<j){
        if(arr[i] + arr[j] == x) return make_pair(arr[i], arr[j]);
        else if (arr[i] + arr[j] < x) i++;
        else j--;
    }
    return make_pair(-1, -1);
}

/// to find: a^2 = b^2 + c^2
/// it does not give correct answer with similar triplets! - which can be managed by changing pairSum method.
vector<pair<int, pii>> pTriplet(int *arr, int n){
    sort(arr, arr+n);
    square(arr, n);
    vector<pair<int, pii>> v;
    int curr;
    for(int i=n-1; i>1; i--){
        curr = arr[i];
        pii p = pairSum(arr, i, curr);
        if(p.first != -1){
            v.push_back(make_pair(curr, p));
        }
    }
    return v;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int arr[n];
    fr(i, n) cin>>arr[i];

    vector<pair<int, pii>> triplets = pTriplet(arr, n);
    for(auto it: triplets){
        cout<<sqrt(it.first)<<" = "<<sqrt(it.second.first)<<" + "<<sqrt(it.second.second)<<endl;
    }

    return 0;
}

