/// proof - https://codeforces.com/blog/entry/78633#comment-639885
#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a) * (a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// #define ll int
ll mod = 1e9+7;

// C++ program to find prime factorization of a
// number n in O(Log n) time with precomputation
// allowed.
#include "bits/stdc++.h"
using namespace std;

const ll MAXN = 1e7L + 5;

// stores smallest prime factor for every number
ll spf[MAXN];

// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve()
{
	spf[1] = 1;
	for (ll i=2; i<MAXN; i++)

		// marking smallest prime factor for every
		// number to be itself.
		spf[i] = i;

	// separately marking spf for every even
	// number as 2
	for (ll i=4; i<MAXN; i+=2)
		spf[i] = 2;

	for (ll i=3; i*i< (ll)MAXN; i++)
	{
		// checking if i is prime
		if (spf[i] == i)
		{
			// marking SPF for all numbers divisible by i
			for (ll j=i * i; j<MAXN; j+=i)

				// marking spf[j] if it is not
				// previously marked
				if (spf[j]==j)
					spf[j] = i;
		}
	}
}

void solve(){
    int n;
    cin>>n;
    vector<int> res[2];
    fr(i, 2) res[i].resize(n, -1);
    ll x;
    fr(i, n){
        cin>>x;

        set<ll> ret;
        ll z = spf[x];

        while(x % z == 0) x /= z;

        if(spf[x] == 1) continue;
        else res[0][i] = z, res[1][i] = x;

    }

    fr(i, 2){
        fr(j, n) cout<<res[i][j]<<" ";
        cout<<endl;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    sieve();

    ll t = 1;
    // cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

