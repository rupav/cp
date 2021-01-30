#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define LIM 100005

vector<bool> p;
vector<int> v;
void prime_seive(int n = LIM){
    p.assign(n, true);
    p[0] = p[1] = false;

    for(int i=2; i*i<n; i++){
        if(p[i]){
            for(int j=i*i; j<n; j+=i){
                p[j] = false;
            }
        }
    }
}

ll cost(int it){
    int n = v.size();
    /// n is divisible by it!
    ll sum = 0ll;
    int pos = it/2;
    int st = 0;

    while(st < n){
        int val = v[pos];
        int i;
        for(i=st; i<st+it; i++){
            sum += 1ll*abs(v[i] - val);
        }
        st = st + it;
        pos = i + (it/2);
    }

    return sum;

}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++) {
        cin>>a[i];
        if(a[i]) v.push_back(i);
    }
    vector<int> f;
    prime_seive();
    for(int i=0; i<LIM; i++){
        if(p[i]) f.push_back(i);
    }

    ll temp = 1ll;
    for(int i=0; i<12; i++)
        temp *= 1ll*f[i];
    cout<<temp<<endl;

    ll ans = 1e18;

    if(v.size() == 1){
        cout<<-1;
        return 0;
    }

    /// for each prime check if there exists a solution, if yes, then find medians.
    int x = v.size();
    for(auto it: f){
        if(x%it == 0){
            ans = min(ans, cost(it));
        }
    }

    cout<<ans;

    return 0;
}
