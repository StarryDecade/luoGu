#include <iostream>
#include <algorithm>
using namespace std;
const int maxl = 1e6 + 7;
const int mod = 1e8 - 3;
struct node {
	int x;
	int id;
};

int n;
node a[maxl], b[maxl];
int c[maxl], d[maxl];
long long ans = 0;

bool cmp1(node a, node b) {
	return a.x < b.x;
}
bool cmp2(node a, node b) {
	return a.id < b.id;
}
void merge_sort(int l, int r) {
	if (l >= r) return ;
	int mid = (l + r) / 2;
	int i = l, j = mid + 1, k = l;
	merge_sort(l, mid);
	merge_sort(mid + 1, r);

	while (i <= mid && j <= r) {
		if (c[i] <= c[j]) d[k++] = c[i++];
		else {
			d[k++] = c[j++];
			ans = (ans + mid - i + 1) % mod;
		} 
	}
	while(i <= mid) d[k++] = c[i++];
	while(j <= r) d[k++] = c[j++];
	for (int i = l; i <= r; i++) c[i] = d[i];
} 

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].x;
		a[i].id = i;
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i].x;
		b[i].id = i;
	}
	sort(a + 1, a + 1 + n, cmp1);
	sort(b + 1, b + 1 + n, cmp1);
	for (int i = 1; i <= n; i++) {
		a[i].x = i;
		b[i].x = i;
	}
	sort(b + 1, b + 1 + n, cmp2);
	for (int i = 1; i <= n; i++) {
		b[i].x = a[b[i].x].id;
		c[i] = b[i].x;
	}
	merge_sort(1, n);

	cout << ans << endl;
	return 0;
}
