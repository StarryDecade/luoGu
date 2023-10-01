#include <iostream>
#include <cstring>
using namespace std;
typedef  long long ll;
const int maxl = 1e3 + 7;

char ch;
long long l[maxl], r[maxl], h[maxl], k[maxl], n, m, top;
int d[maxl][maxl];
ll ans;

void ddzl() {
	top = 0;
	for (int i = m; i >= 1; i--) {
		while(top != 0 && h[i] <= h[k[top]]) {
			l[k[top]] = i;
			top--;
		} 
		top++;
		k[top] = i;
	}
	while (top) {
		l[k[top]] = 0;
		top--;
	}
}

void ddzr() {
	top = 0;
	for (int i = 1; i <= m; i++) {
		while (top != 0 && h[i] < h[k[top]]) {
			r[k[top]] = i;
			top--;
		}
		top++;
		k[top] = i;
	}
	while (top) {
		r[k[top]] = m + 1;
		top--;
	}
}

void work() {
	ddzl();
	ddzr();
	for (int i = 1; i <= m; i++) ans += (i - l[i]) * (r[i] - i) * h[i];
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> ch;
			if (ch == '*') d[i][j] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			h[j]++;
			if (d[i][j]) h[j] = 0;
		}
		work();
	}
	cout << ans << endl;
	return 0;
}
