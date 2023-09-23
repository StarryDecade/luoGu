#include <iostream>
#include <climits>
#include <cstring>
#include <queue>
using namespace std;
struct node {
	int value;
	int father;
	int left;
	int right;
	int step;
}t[107];
int n, sum, ans = INT_MAX, vis[105];

void bfs(int k) {
	queue<node> q;
	memset(vis, 0, sizeof(vis));
	vis[k] = 1;
	node tn = t[k];
	tn.step = 0;
	q.push(tn);
	while (!q.empty()) {
		tn = q.front();
		q.pop();
		sum += tn.value * tn.step;
		int fa = tn.father, l = tn.left, r = tn.right;
		if (fa && !vis[fa]) {
			vis[fa] = 1;
			node tn2 = t[fa];
			tn2.step = tn.step + 1;
			q.push(tn2);
		}
		if (l && !vis[l]) {
			vis[l] = 1;
			node tn2 = t[l];
			tn2.step = tn.step + 1;
			q.push(tn2);
		}
		if (r && !vis[r]) {
			vis[r] = 1;
			node tn2 = t[r];
			tn2.step = tn.step + 1;
			q.push(tn2);
		}
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
		bfs(i);
		ans = min(ans, sum);
	}
	cout << ans << endl;
	return 0;
}
