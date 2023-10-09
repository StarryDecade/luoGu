#include <iostream>
using namespace std;
const int N = 1e6 + 7;

int n, k, ans, a[N], cnt[2];
int trie[N * 21][2], sz[N * 21], tot = 0;

void insert(int x) {
	int u = 0;
	for (int i = 21, c; i >= 0; i--) {
		c = (x >> i) & 1;
		if (!trie[u][c]) trie[u][c] = ++tot;
		u = trie[u][c];
		sz[u]++;
	}
}

int query(int x) {
	int ret = 0, u = 0;
	bool flag = 0;
	for (int i = 21, c; i >= 0; i--) {
		c = (x >> i) & 1;
		int t = (k >> i) & 1;
		if (t == 1) ret += sz[trie[u][1 - (c ^ t)]];
		if (!trie[u][c ^ t]) {
			flag = 1;
			break;
		}
		u = trie[u][c ^ t];
	}
	if (!flag) ret += sz[u];
	return ret;
}

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		insert(a[i]);
	}
	for (int i = 0; i < 2097152; i++) {
		ans = max(ans, query(i));
		if (ans == n) break;
	}
	cout << ans << endl;
	return 0;
}
