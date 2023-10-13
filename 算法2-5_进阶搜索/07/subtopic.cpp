#include <iostream>
using namespace std;
const int N = 20;

int a[N][N], h[N][N], l[N][N], g[N][N], flag = 0;
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

void dfs(int k) {
	if (flag) return;
	if (k > 80) {
		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
		flag = 1;
		return ;
	}
	int x = k / 9 + 1;
	int y = k % 9 + 1;
	if (a[x][y] > 0) dfs(k + 1);
	else {
		for(int i = 1; i <= 9; i++) {
			if (!h[x][i] && !l[y][i] && !g[pre[x][y]][i]) {
				h[x][i] = 1;
				l[y][i] = 1;
				g[pre[x][y]][i] = 1;
				a[x][y] = i;
				dfs(k + 1);
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
	dfs(0);
	return 0;
}
