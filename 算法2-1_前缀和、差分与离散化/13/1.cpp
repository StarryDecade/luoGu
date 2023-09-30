#include <iostream>
#include <algorithm>
#include <map>
#include <climits>
using namespace std;
const int maxl = 1e5;
struct node {
	int x;
	int p;
}s[maxl];

int ans = INT_MAX, sum = 0, n, z, tail;
map<int, int> t;
map<int, bool> pan;

bool cmp(node a, node b) {
	return a.x < b.x;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i].x >> s[i].p;
		if (!pan[s[i].p]) {
			sum++;
			pan[s[i].p] = true;
		}
	}
	sort(s + 1, s + n + 1, cmp);
	tail = 1;
	t[s[1].p]++;
	z = 1;
	for (int i = 1; i <= n; i++) {
		while (z < sum && tail < n) {
			tail++;
			t[s[tail].p]++;
			if (t[s[tail].p] == 1) z++;
		}
		if (z == sum) ans = min(ans, s[tail].x - s[i].x);
		t[s[i].p]--;
		if (!t[s[i].p]) z--;
	}
	cout << ans << endl;
	return 0;
}
