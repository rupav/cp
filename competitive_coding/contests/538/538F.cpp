#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

bool primeSeive[301];

int getNext(int i){
    i += i&(-i);
    return i;
}

int getParent(int i){
    i -= i&(-i);
    return i;
}

void updateProductBIT(int n, int *arr, int *BIT, int i, int update){
    while(i<=n){
        BIT[i] *= update;
        i = getNext(i);
    }
}

void constructProductBIT(int n, int *arr, int *BIT){
    fr(i, n+1) BIT[i] = 1;  /// initialization for product BIT.
    BIT[0] = 1;
    fr(i, n){
        updateProductBIT(n, arr, BIT, i+1, arr[i]);
    }
}

int getProduct(int n, int *arr, int *BIT, int l, int r){
    int prod_l = 1;
    l-=1;
    while(l){
        prod_l *= BIT[l];
        l = getParent(l);
    }
    int prod_r = 1;
    while(r){
        prod_r *= BIT[r];
        r = getParent(r);
    }
    return prod_r/max(prod_l, 0);
}

vector<int> constructSeive(int n, bool *seive){
    fr(i, n){
        seive[i] = true;  /// initialize all being prime.
    }
    vector<int> primes(64);
    rep(i, 2, n){
        if(seive[i]){
            primes.push_back(i);
            for(int j=i*2; j<n; j+=i){
                seive[j] = false;
            }
        }
    }
    return primes;
}

void constructPrimeBIT(int n, int *arr, int64_t *BIT, vector<int> primes){
    fr(i, n+1) BIT[i] = 0;
}

int main(){
    int n, q;
    cin>>n>>q;
    int *arr = new int[n];
    fr(i, n){
        cin>>arr[i];
    }
    int *BIT = new int[n+1];
    int64_t *primeBIT = new int64_t[n+1];  /// int64_t is gauranteed to have 64 bits! on any platform - thus storing the result if ith bit is prime or not!
    int l, r, x;
    constructProductBIT(n, arr, BIT);
    vector<int> primes = constructSeive(301, primeSeive);  /// map `mp` will have all the prime numbers less than 300;
    constructPrimeBIT(n, arr, primeBIT, primes);
    cin.ignore();
    while(q--){
        string s;
        cin>>s;
        bool operation = false;  /// false means multiply else find totient of product.
        int k = s.size();
        cin>>l>>r;
        if(s[0] == 'T'){
            /// get the result and print it out!
            operation = true;
        } else {
            /// get x
            cin>>x;
            /// update both BITS.
        }
    }
    /*
    while(1){
        cin>>l>>r;
        if(l <0 || r <0 || l>r || l>=n || r>=n){
            return 0;
        }
        ll res = getProduct(n, arr, BIT, l+1, r+1);
    }
    */
    return 0;
}
