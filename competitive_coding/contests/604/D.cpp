#include<bits/stdc++.h>
using namespace std;

#define fr(i, n) for(int i=0; i<n; i++)
typedef pair<int, int> pii;


void solve(){
    int a[4];
    int n = 0;
    pii pq;
    int max_ = -1;
    fr(i, 4) {
        cin>>a[i];
        n+=a[i];
    }
    vector<int> ans(n, -2);

    max_ = max(a[1], a[2]);
    int ind = -1;
    if(a[1] >= a[2]){
        max_ = a[1];
        ind = 1;
    } else {
        max_ = a[2];
        ind = 2;
    }

    if(a[0] >= max_){
        max_ = a[0];
        ind = 0;
    }
    if(a[3] >= max_){
        max_ = a[3];
        ind = 3;
    }

    pq.first = max_;
    pq.second = ind;

    int l = 1;
    while(l--){
        pii x = pq;
        int el = x.second;
        int val;
        if(el == 3 || el == 0){
            if(x.first > n/2){
                cout<<"NO";
                return;
            }
            val = x.first;
            int i = 0;
            while(val--){
                ans[i] = el;
                i+=2;
            }
            int z = 1 + (el != 0);
            val = a[z];
            i = 1;
            while(val--){
                ans[i] = z;
                i+=2;
            }
            i -= 2;
            if(ans[i+1]!=-1){
                cout<<"NO";
                return;
            }

            z = 1 + (el == 0);
            val = a[z];
            i++;
            int j = i+1;

            while(val--){
                ans[i] = z;
                i += 2;
            }

            z = (el==0) ? 3 : 0;
            val = a[z];
            while(val--){
                ans[j] = z;
                j+=2;
            }
        } else if(el == 1) {
            val = x.first;
            int i = 0;
            while(val--){
                ans[i] = el;
                i+=2;
            }

            i=1;
            val = a[0];
            while(val--){
                ans[i] = 0;
                i+=2;
            }
            i-=2;



            i++;
            int j = i+1;
            val = a[2];
            while(val--){
                ans[i] = 2;
                i+=2;
            }

            val = a[3];
            while(val--){
                ans[j] = 3;
                j+=2;
            }

        } else {
            /// el = 2
            val = a[2];
            int i = 0;
            while(val--){
                ans[i] = 2;
                i+=2;
            }

            i=1;
            val = a[3];
            while(val--){
                ans[i] = 3;
                i+=2;
            }
            i-=2;

            i++;
            int j = i+1;
            val = a[1];
            while(val--){
                ans[i] = 1;
                i+=2;
            }


            val = a[0];
            while(val--){
                ans[j] = 0;
                j+=2;
            }

        }

        bool fl = true;
        fr(i, n-1){
            cout<<ans[i]<<" ";
            if(abs(ans[i] - ans[i+1]) != 1) fl = false;
        }
        if(!fl){
            cout<<"NO";
            return;
        }
        cout<<"YES"<<endl;
        fr(i, n) cout<<ans[i]<<" ";

    }

}

int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
