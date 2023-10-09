#include <iostream>
#include <cstring>
using namespace std;
const int N = 5e5 + 7;

int n, m, k, ch[N][3], tot = 1, bo[N], sum[N], x;
bool p[N];

void add(bool p[]) {
	int u = 1;
	for (int i = 1; i <= k; i++) {
		int c = p[i];
		if (ch[u][c] == -1) ch[u][c] = ++tot;
		u = ch[u][c];
		sum[u]++;
	}
	bo[u]++;
}

int find(bool p[]) {
	int u = 1;
	int res = 0;
	for (int i = 1; i <= k; i++) {
		int c = p[i];
		if (ch[u][c] == -1) return res;
		u = ch[u][c];
		res += bo[u];
	}
	return res - bo[u] + sum[u];
}

int main() {
	int x;
	cin >> n >> m;
	memset(ch, -1, sizeof(ch));
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) cin >> p[j];
		add(p);
	}
	for (int i = 1; i <= m; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) cin >> p[j];
		cout << find(p) << endl;
	}
	return 0;
}
