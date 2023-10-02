#include <iostream>
#include <algorithm>
using namespace std;
const int maxl = 1e4;
struct node {
	int pre, id;
}a[maxl];

int n, q;
int t[maxl];

bool cmp(node a, node b) {
	if(a.pre != b.pre) return a.pre < b.pre;
	return a.id < b.id;
}

int main() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].pre;
		a[i].id = i;
	}

	sort(a + 1, a + 1 + n, cmp);
	for (int i = 1; i <= n; i++) {
		t[a[i].id] = i;
	}
	while (q--) {
		int opt, x, v;
		cin >> opt;
		if (opt == 1) {
			cin >> x >> v;
			a[t[x]].pre = v;
			for (int j = n; j >= 2; j--) {
				if (cmp(a[j], a[j - 1])) {
					node tmp = a[j];
					a[j] = a[j - 1];
					a[j - 1] = tmp;
				}
			}
			for (int j = 2; j <= n; j++) {
				if (cmp(a[j], a[j - 1])) {
					node tmp = a[j];
					a[j] = a[j - 1];
					a[j - 1] = tmp;
				}
			}
			for (int i = 1; i <= n; i++) {
				t[a[i].id] = i;
			}
		} else {
			cin >> x;
			cout << t[x] << endl;
		}
	}

	return 0;
}
