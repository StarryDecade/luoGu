#include <algorithm>
#include <iostream>
#include <climits>
#include <queue>
#include <cstring>
using namespace std;
const int maxl = 105;
struct node {
	int father;
	int left;
	int right;
	int deep;
}tree[105];

struct node2 {
	int val;
	int path;
};

int maxDeep = INT_MIN;
int width[maxl] = {0};
int maxWidth = INT_MIN;

void dfs(int root, int deep) {
	if (!root)	return;
	maxDeep = max(maxDeep, deep);
	width[deep]++;
	dfs(tree[root].left, deep + 1);
	dfs(tree[root].right, deep + 1);
}

int main() {
	int n, u, v;
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		if (!tree[u].left)	tree[u].left = v;
		else tree[u].right = v;
		tree[v].father = u;
	}
	cin >> u >> v;
	dfs(1, 1);
	for (int i = 1; i <= maxDeep; i++) maxWidth = max(maxWidth, width[i]);
	cout << maxDeep << endl << maxWidth << endl;

	bool vis[maxl];
	memset(vis, 0, sizeof(vis));	
	vis[u] = true;
	node2 tp = {u, 0};
	queue<node2> q;
	q.push(tp);
	while (!q.empty()) {
		tp = q.front();
		q.pop();

		if (tp.val == v) {
			cout << tp.path << endl;
			break;
		}

		int father = tree[tp.val].father, left = tree[tp.val].left, right = tree[tp.val].right;

		if (!vis[left] && left) {
			vis[left] = true;
			q.push({left, tp.path + 1});
		}

		if (!vis[right] && right) {
			vis[right] = true;
			q.push({right, tp.path + 1});
		}
		
		if (!vis[father] && father) {
			vis[father] = true;
			q.push({father, tp.path + 2});
		}
	}
	return 0;
}
