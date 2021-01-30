    #include<bits/stdc++.h>
    #define ll long long
    #define ld long double
    #define pi acos(-1)
    #define mod 1000000007
    #define all(x) x.begin(), x.end()
    using namespace std;

    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        int n;
        cin >> n;
        int a[n];
        set<int> s;
        s.insert(n);
        map<int, int> pos;
        bool f = true;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(i > 0 && a[i] < a[i - 1]){
                f = false;
            }
            s.insert(i);
            pos[a[i]] = i;
        }
        if(!f){
            cout << -1;
            return 0;
        }
        for(int i = n - 1; i >= 0; i--){
            s.erase(a[i]);
        }
        int b[n];
        for(int i = 0; i < n; i++){
            if(s.empty()){
                cout << -1;
                return 0;
            }
            b[i] = (*s.begin());
            s.erase(s.begin());
            if(pos[a[i]] <= i){
                s.insert(a[i]);
            }
        }
        for(int i = 0; i < n ;i++){
            cout << b[i] << " ";
        }
    }
