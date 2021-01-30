#include <iostream>
#include <queue>
using namespace std;
struct point {
	int x, y, lm, rm;
};

int main()
{
	int n, m, r, c, x, y;
	cin >> n >> m >> r >> c >> x >> y;
	char lamb[2005][2005];
	for (int i = 1; i <= n; i++) {
		scanf("%s", lamb[i] + 1);
	}
	for (int i = 0; i <= n + 1; i++) {
		lamb[i][0] = lamb[i][m + 1] = '*';
	}
	for (int i = 0; i <= m + 1; i++) {
		lamb[0][i] = lamb[n + 1][i] = '*';
	}

	queue<point> q;
	int ans = 0;
	point root = { c, r, 0, 0 };
	q.push(root);
	lamb[r][c] = '*';
	ans++;
	point up = { c, r - 1, 0, 0 };
	while (lamb[up.y][up.x] != '*') {
		q.push(up);
		lamb[up.y][up.x] = '*';
		up.y--;
		ans++;
	}
	point down = { c, r + 1, 0, 0 };
	while (lamb[down.y][down.x] != '*') {
		q.push(down);
		lamb[down.y][down.x] = '*';
		down.y++;
		ans++;
	}
	while (!q.empty()) {
		point here = q.front();
		q.pop();
		point left = { here.x - 1, here.y, here.lm + 1, here.rm };
		if (lamb[left.y][left.x] == '.' && left.lm <= x) {
			q.push(left);
			ans++;
			lamb[left.y][left.x] = '*';
			point up = { left.x, left.y - 1, left.lm, left.rm };
			while (lamb[up.y][up.x] != '*') {
				q.push(up);
				lamb[up.y][up.x] = '*';
				up.y--;
				ans++;
			}
			point down = { left.x, left.y + 1, left.lm, left.rm };
			while (lamb[down.y][down.x] != '*') {
				q.push(down);
				lamb[down.y][down.x] = '*';
				down.y++;
				ans++;
			}
		}
		point right = { here.x + 1, here.y, here.lm, here.rm + 1 };
		if (lamb[right.y][right.x] == '.' && right.rm <= y) {
			q.push(right);
			ans++;
			lamb[right.y][right.x] = '*';
			point up = { right.x, right.y - 1, right.lm, right.rm };
			while (lamb[up.y][up.x] != '*') {
				q.push(up);
				lamb[up.y][up.x] = '*';
				up.y--;
				ans++;
			}
			point down = { right.x, right.y + 1, right.lm, right.rm };
			while (lamb[down.y][down.x] != '*') {
				q.push(down);
				lamb[down.y][down.x] = '*';
				down.y++;
				ans++;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
