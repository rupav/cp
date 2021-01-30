/*
#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;

/// https://www.codechef.com/LTIME84A/problems/CONVSTR

void solve(){
    int n;
    // n = s.size();
    cin>>n;
    string s, t;
    cin>>s>>t;

    int cnt = 0;
    bool f = true;

    vector<set<int>> p[2];  /// pos of characters
    fr(i, 2) p[i].resize(26);

    priority_queue<int> pq;
    map<char, bool> mp;

    fr(i, n){
        if(!mp[t[i]]){
            pq.push(t[i] - 'a');
            mp[t[i]] = 1;
        }

        p[0][s[i] - 'a'].insert(i);
        p[1][t[i] - 'a'].insert(i);
    }

    vector<vector<int>> ops;

    while(pq.size()){
        int x = pq.top();
        pq.pop();

        if(!p[0][x].size()){
            f = false;
            break;
        }

        auto jit = p[0][x].begin();
        vector<int> v;

        for(auto &it: p[1][x]){
            if(s[it] - 'a' != x){
                if(s[it] - 'a' < x) {
                    f = false;
                    break;
                }
                v.push_back(it);
                fr(i, 26){
                    if(p[0][i].size())
                        p[0][i].erase(it);
                }
            }
        }
        if(!f) break;

        if(v.size()){
            cnt++;
            v.push_back(*jit);
            ops.push_back(v);
        }

    }

    if(!f){
        cout<<-1<<endl;
    } else {
        assert(cnt <= 2);
        cout<<cnt<<endl;
        for(auto v: ops){
            cout<<v.size()<<" ";
            sort(v.begin(), v.end());
            for(auto it: v) cout<<it<<" ";
            cout<<endl;
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
*/

#include <bits/stdc++.h>
#define endl '\n'

#define SZ(x) ((int)x.size())
#define ALL(V) V.begin(), V.end()
#define L_B lower_bound
#define U_B upper_bound
#define pb push_back

using namespace std;
template<class T, class T1> int chkmin(T &x, const T1 &y) { return x > y ? x = y, 1 : 0; }
template<class T, class T1> int chkmax(T &x, const T1 &y) { return x < y ? x = y, 1 : 0; }
const int MAXN = (1 << 20);

int n;
string a;
string b;

void read() {
	cin >> n;
	cin >> a;
	cin >> b;
}

void solve() {
	vector<vector<int> > ans;
	for(int i = 0; i < n; i++) {
		if(a[i] < b[i]) {
			cout << -1 << endl;
			return;
		}
	}

	for(char c = 'z'; c >= 'a'; c--) {
		vector<int> pos;
		bool ok = 0;

		for(int i = 0; i < n; i++) {
			if(b[i] == c && a[i] != c) {
				pos.pb(i);
			}
		}

		if(!ok && !pos.empty()) {
			for(int i = 0; i < n; i++) {
				if(a[i] == c) {
					ok = 1;
					pos.pb(i);
				}
			}
		}

		if(!ok && !pos.empty()) {
			cout << -1 << endl;
			return;
		}

		if(!pos.empty()) ans.pb(pos);
		for(int i: pos) {
			a[i] = c;
		}
	}

	cout << SZ(ans) << endl;
	for(auto li: ans) {
		cout << SZ(li) << " ";
		for(int x: li) cout << x << " ";
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while(T--) {
		read();
		solve();
	}

	return 0;
}

