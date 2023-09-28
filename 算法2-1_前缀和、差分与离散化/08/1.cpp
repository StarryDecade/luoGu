#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxl = 1e6 + 7;
struct node {
	int x, y, e;
}a[maxl];

int t, n, f[maxl], book[maxl * 3];

void first(int reu) {
	for (int i = 1; i <= reu; i++) f[i] = i;
}

bool cmp(node a, node b) {
	return a.e > b.e;
}

int get(int x) {
	if (x == f[x]) return x;
	return f[x] = get(f[x]);
}

int main() {
	cin >> t;
	while (t--) {
		int tot = -1;
		memset(book, 0, sizeof(book));
		memset(a, 0, sizeof(a));
		memset(f, 0, sizeof(f));
		int flag = 1;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].x >> a[i].y >> a[i].e;
			book[++tot] = a[i].x;
			book[++tot] = a[i].y;
		}
		sort(book, book + tot);
		int reu = unique(book, book + tot) - book;
		for (int i = 1; i <= n; i++) {
			a[i].x = lower_bound(book, book + reu, a[i].x) - book;
			a[i].y = lower_bound(book, book + reu, a[i].y) - book;
		}
		
		first(reu);
		sort(a + 1, a + n + 1, cmp);
		for (int i = 1; i <= n; i++) {
			int x = get(a[i].x);
			int y = get(a[i].y);
			if (a[i].e) f[x] = y;
			else if (x == y) {
				cout << "NO" << endl;
				flag = 0;
				break;
			}
 		}
		if (flag) cout << "YES" << endl;
	}
	return 0;
}
