#include <algorithm>
#include <iostream>
using namespace std;
const int N = 20;

int ans, ans_m = -1, t;
int a[N][N], h[N][N], l[N][N], g[N][N];
int pre[11][11] = {
	{0, 0 ,0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 1, 1, 2, 2, 2, 3, 3, 3},
	{0, 1, 1, 1, 2, 2, 2, 3, 3, 3},
	{0, 1, 1, 1, 2, 2, 2, 3, 3, 3},
	{0, 4, 4, 4, 5, 5, 5, 6, 6, 6},
	{0, 4, 4, 4, 5, 5, 5, 6, 6, 6},
	{0, 4, 4, 4, 5, 5, 5, 6, 6, 6},
	{0, 7, 7, 7, 8, 8, 8, 9, 9, 9},
	{0, 7, 7, 7, 8, 8, 8, 9, 9, 9},
	{0, 7, 7, 7, 8, 8, 8, 9, 9, 9}
};
int s[11][11] = {
	{0, 0 ,0, 0, 0, 0, 0, 0, 0, 0},
	{0, 6, 6, 6, 6, 6, 6, 6, 6, 6}, 
	{0, 6, 7, 7, 7, 7, 7, 7, 7, 6},
	{0, 6, 7, 8, 8, 8, 8, 8, 7, 6},
	{0, 6, 7, 8, 9, 9, 9, 8, 7, 6},
	{0, 6, 7, 8, 9, 10, 9, 8, 7, 6},
	{0, 6, 7, 8, 9, 9, 9, 8, 7, 6},
	{0, 6, 7, 8, 8, 8, 8, 8, 7, 6},
	{0, 6, 7, 7, 7, 7, 7, 7, 7, 6},
	{0, 6, 6, 6, 6, 6, 6, 6, 6, 6},
}; // socre

void dfs(int k) {
	t++;
	if (t > 1e7 + 1e6) return;
	if (k < 0) {
		ans = 0;
		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				ans += a[i][j] * s[i][j];
			}
			ans_m = max(ans_m, ans);
		}
		return ;
	}
	int x = k / 9 + 1;
	int y = k % 9 + 1;
	if (a[x][y] > 0) dfs(k - 1);
	else {
		for(int i = 1; i <= 9; i++) {
			if (!h[x][i] && !l[y][i] && !g[pre[x][y]][i]) {
				h[x][i] = 1;
				l[y][i] = 1;
				g[pre[x][y]][i] = 1;
				a[x][y] = i;
				dfs(k - 1);
				h[x][i] = 0;
				l[y][i] = 0;
				g[pre[x][y]][i] = 0;
				a[x][y] = 0;
			}
		}
	}
}

int main (int argc, char *argv[]) {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> a[i][j];
			int x = a[i][j];
			h[i][x] = 1;
			l[j][x] = 1;
			g[pre[i][j]][x] = 1;
		}
	}
	dfs(80);
	cout << ans_m << endl;
	return 0;
}

