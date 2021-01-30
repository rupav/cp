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

vector<int> constructZFunc(string s){
    int n = s.size();
    vector<int> z(n);
    int l, r;
    l = r = 0;
    z[0] = 0;
    rep(i, 1, n-1){
        z[i] = 0;
        if(i<=r){
            z[i] = min(r-i+1, z[i-l]);  /// initialization, req. for linear time approach.
        }
        while(i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if(i+z[i]-1 > r){
            r = i+z[i]-1;
            l = i;
        }
    }
    return z;
}

typedef struct Suffixes{
    int index;
    string suff;
} Suffixes_t;

bool cmp(Suffixes_t suff1, Suffixes_t suff2){
    return suff1.suff.compare(suff2.suff)<0 ? 1 : 0;
}

Suffixes suffs[100];

/// construction is done in O(n^2logn) time - check O(n) time to build the same.
int* ConstructSuffixArray(string s){
    /// return suffix-array of string s
    int n = s.size();
    for(int i=0; i<n; i++){
        suffs[i].index = i;
        suffs[i].suff = s.substr(i, string::npos);
    }
    sort(suffs, suffs+n, cmp);
    int *suff_arr = new int[n];
    fr(i, n) suff_arr[i] = suffs[i].index;
    return suff_arr;
}

int FindPattern(string s, string t){
    /// finding t in s, using suffix array - in m*log(n) time, where m = t.size(): given that we have the suffix array build already!
    /// we could have used z-function instead i.e O(n+m) time to find all indices of pattern.
    /// this function returns only 1 index if string t is found in string s.
    int* suff_arr = ConstructSuffixArray(s);
    int n = s.length();
    int m = t.length();
    int l = 0, r = n-1;
    while(l <= r){
        int mid = (l+r)/2;
        int temp = suffs[mid].suff.substr(0, m).compare(t);
        if(!temp) return suff_arr[mid];
        else if (temp > 0) r = mid-1;
        else l = mid+1;
    }
    return -1;  /// not found!
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s, t;
    cin>>s>>t;
    int* suff_arr = ConstructSuffixArray(s);
    fr(i, s.length()) cout<<suff_arr[i]<<" ";
    cout<<endl;
    cout<<FindPattern(s, t)<<endl;

    return 0;
}

