#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 7;

int head[N], nxt[N << 1], to[N << 1], weight[N << 1], cnt;
int n, dis[N], ch[N << 5][2], tot = 1, ans;

void insert(int x) {
	for (int i = 30, u = 1; i >= 0; i--) {
		int c = ((x >> i) & 1);
		if (!ch[u][c]) ch[u][c] = ++tot;
		u = ch[u][c];
	}
}

void get(int x) {
	int res = 0;
	for (int i = 30 ,u = 1; i >=0; i--) {
		int c = ((x >> i) & 1);
		if (ch[u][c ^ 1]) {
			u = ch[u][c ^ 1];
			res |= (1 << i);
		} else u = ch[u][c];
	}
	ans = max(ans, res);
}

void add(int u, int v, int w) {
	nxt[++cnt] = head[u];
	head[u] = cnt;
	to[cnt] = v;
	weight[cnt] = w;
}

void dfs(int u, int fa) {
	insert(dis[u]);
	get(dis[u]);
	for (int i = head[u]; i; i = nxt[i]) {
		int v = to[i];
		if (v == fa) continue;
		dis[v] = dis[u] ^ weight[i];
		dfs(v, u);
	}
}
int main() {
	cin >> n;

	for (int i = 1; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		add(u, v, w);
		add(v, u, w);
	}
	dfs(1, 0);
	cout << ans << endl;
	return 0;
}
