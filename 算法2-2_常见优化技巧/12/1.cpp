#include <iostream>
#include <algorithm>
using namespace std;
const int maxl = 1e4;
struct node {
	int x, y;
}dot[maxl];

bool cmp1(node a, node b) { // 从左到右
	return a.y < b.y;
}
bool cmp2(node a, node b) { // 从上到下
	return a.x < b.x;
}
 
int main() {
	int L, W, n, x, y;
	cin >> L >> W >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;
		dot[i] = node{x, y};
	}
	dot[++n] = node{0, 0};
	dot[++n] = node{0, W};
	dot[++n] = node{L, 0};
	dot[++n] = node{L, W};

	// 从左到右
	int ans = 0;
	sort(dot + 1, dot + n + 1, cmp1);
	for (int i = 1; i <= n; i++) {
		int up = 0, down = L;
		for (int j = i + 1; j <= n; j++) {
			int l = dot[i].y, r = dot[j].y;
			ans = max(ans, (r - l) * (down - up));
			if (dot[j].x > dot[i].x) down = min(down, dot[j].x);
			else up = max(up, dot[j].x);
		}
	}

	// 从上往下
	sort(dot + 1, dot + 1 + n, cmp2);
	for (int i = 1; i <= n; i++) {
		int l = 0, r = W;
		for (int j = i + 1; j <= n; j++) {
			int up = dot[i].x, down = dot[j].x;
			ans = max(ans, (r - l) * (down - up));
			if (dot[j].y > dot[i].y) r = min(r, dot[j].y);
			else l = max(l, dot[j].y);
		}
	}
	cout << ans << endl;
	return 0;
}
