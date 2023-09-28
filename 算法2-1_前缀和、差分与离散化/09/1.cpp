#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
const int maxl = 1e4;
struct node {
	int x;
	int y0;
	int y1;
	int c;
}a[maxl];

int N, M, qy[maxl];
long long ans;

struct Segtree {
	#define i0 (i << 1)
	#define i1 (i << 1 | 1)
	int L[maxl << 2], R[maxl << 2], v[maxl << 2], len[maxl << 2];
	void init(int i, int l, int r) {
		L[i] = l, R[i] = r, v[i] = len[i] = 0;
		if (l != r) {
			int mid = (l + r) >> 1;
			init(i0, l, mid);
			init(i1, mid + 1, r);
		}
	}
	void add(int i, int l, int r, int c) {
		if (r < L[i] || R[i] < l) return;
		if (l <= L[i] && R[i] <= r) v[i] += c;
		else {
			add(i0, l, r, c);
			add(i1, l, r, c);
		}
		if (v[i]) len[i] = qy[R[i] + 1] - qy[L[i]];
		else len[i] = len[i0] + len[i1];
	}
}Seg; 

bool cmp(node a, node b) {
	return a.x < b.x;
}

unordered_map<int, int> H;

int main() {
	cin >> N;
	H.clear();
	for (int i = 1, x0, y1, x1, y0; i <= N; i++) {
		cin >> x0 >> y1 >> x1 >> y0;
		a[i] = node{x0, y0, y1, 1};
		a[i + N] = node{x1, y0, y1, -1};
		qy[++M] = y0;
		qy[++M] = y1;
	}
	sort(qy + 1, qy + M + 1);
	M = unique(qy + 1, qy + M + 1) - qy - 1;
	for (int i = 1; i <= M; i++) H[qy[i]] = i;

	Seg.init(1, 1, (N <<= 1));
	sort(a + 1, a + N + 1, cmp);
	for (int i = 1; i <= N; i++) {
		Seg.add(1, H[a[i].y0], H[a[i].y1] - 1, a[i].c);
		ans += (long long)Seg.len[1] * (a[i + 1].x - a[i].x);
	}
	cout << ans << endl;
	return 0;
}
