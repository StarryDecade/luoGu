#include <iostream>
#include <cstring>
#include <climits>
using namespace std;
struct node {
	int left;
	int right;
	int father;
	int value;
}t[105];
int n, sum, ans = INT_MAX, vis[105];

void dfs(int step, int pos) {
	sum += step * t[pos].value;
	int fa = t[pos].father, l = t[pos].left, r = t[pos].right;
	if (fa && !vis[fa]) {
		vis[fa] = 1;
		dfs(step + 1, fa);
	}
	if (l && !vis[l]) {
		vis[l] = 1;
		dfs(step + 1, l);
	}
	if (r && !vis[r]) {
		vis[r] = 1;
		dfs(step + 1, r);
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i].value >> t[i].left >> t[i].right;
		t[t[i].left].father = i;
		t[t[i].right].father = i;
	}
	for (int i = 1; i <= n; i++) {
		sum = 0;
		memset(vis, 0, sizeof(vis));
		vis[i] = 1;
		dfs(0, i);
		ans = min(ans, sum);
	}
	cout << ans;
	return 0;
}
