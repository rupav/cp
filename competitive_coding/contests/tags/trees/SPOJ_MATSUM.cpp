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

const int N = 1025;
int bit[N][N];
char s[10];

int n, x, y, val, x2, y2;

void update(int n, int x_, int y_, int val){
    for(int x=x_; x<=n; x += x&(-x)){
        for(int y=y_; y<=n; y += y&(-y))
            bit[x][y] += val;
    }
}

int query(int x_, int y_){
    int sum = 0;
    for(int x=x_; x > 0; x -= x&(-x)){
        for(int y=y_; y > 0; y -= y&(-y))
            sum += bit[x][y];
    }
    return sum;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        rep(i, 0, n) rep(j, 0, n) bit[i][j] = 0;
        while(true){
            scanf("%s", s);
            if(!strcmp(s, "END")) break;
            if(!strcmp(s, "SET")){
                scanf("%d%d%d", &x, &y, &val);
                x++;
                y++;
                int sum1 = query(x-1, y-1);
                int sum2 = query(x-1, y) - sum1;
                int sum3 = query(x, y-1) - sum1;
                int sum = query(x, y);
                sum -= (sum1 + sum2 + sum3);
                update(n, x, y, val-sum);  /// operation is set not update
            } else {
                scanf("%d%d%d%d", &x, &y, &x2, &y2);
                x++;
                y++;
                x2++;
                y2++;
                int sum1 = query(x-1, y-1);
                int sum2 = query(x-1, y2) - sum1;
                int sum3 = query(x2, y-1) - sum1;
                int sum = query(x2, y2);
                sum -= (sum1 + sum2 + sum3);
                printf("%d\n", sum);
            }
        }
    }

    return 0;
}
