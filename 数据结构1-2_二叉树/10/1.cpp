#include <iostream>
#include <cstring>
using namespace std;

bool tree[1500];
int a[12] = {0, 1, 2, 5, 11, 23, 47, 95, 191, 383, 767, 1535}, m;
char maze[800][1550];

void dfs(int x, int y, int pos, int deep) {
	if (deep == 0) return;
	if (!tree[pos << 1]) {
		for (int i = 1; i <= a[deep]; i++) {
			maze[x + i][y - i] = '/';
		}
		maze[x + a[deep] + 1][y - a[deep] - 1] = 'o';
		dfs(x + a[deep] + 1, y - a[deep] - 1, pos << 1, deep - 1);
	}

	if (!tree[pos << 1 | 1]) {
		for (int i = 1; i <= a[deep]; i++) {
			maze[x + i][y + i] = '\\';
		}
		maze[x + a[deep] + 1][y + a[deep] + 1] = 'o';
		dfs(x + a[deep] + 1, y + a[deep] + 1, pos << 1 | 1, deep - 1);
	}
}

int main(){
	memset(maze, 32, sizeof(maze));
	int n, tx, ty;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		cin >> tx >> ty;
		int pos = (1<<(tx - 1)) + ty - 1;
		tree[pos] = 1;
	}
	maze[1][a[m] + 1] = 'o';
	dfs(1, a[m] + 1, 1, m - 1);
	
	for (int i = 1; i <= a[m] + 1; i++) {
		for (int j = 1; j <= a[m + 1] + 2; j++) {
			cout << maze[i][j];
		}
		cout << endl;
	}
	return 0;
}
