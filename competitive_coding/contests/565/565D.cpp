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

bool prime[200005];
vector<ll> np;
vector<ll> p;

void SieveOfEratosthenes(int n = 200005)
{
    memset(prime, true, sizeof(prime));

    for (int p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p greater than or
            // equal to the square of it
            // numbers which are multiple of p and are
            // less than p^2 are already been marked.
            for (int i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    SieveOfEratosthenes();
    cin>>n;
    ll arr[i];
    fr(i, 2*n){
        cin>>arr[i];
        if(arr[i] > 200000 || prime[i]) p.push_back(arr[i]);
        else np.push_back(arr[i]);
    }

    sort(p.begin(), p.end());
    sort(np.begin(), np.end(), greater<int>);

    int t = (np.size() % 2 == 0) ? np.size()/2 : (np.size()/2)+1;
    vector<ll> ans;

    for(auto it: np){
        if(t)
            ans.push_back(it);
        else break;
        t--;
    }

    for(auto it: p){
        if(it)
    }

    return 0;
}

