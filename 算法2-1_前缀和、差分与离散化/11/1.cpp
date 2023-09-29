#include <iostream>
#include <cstring>
#include <climits>
using namespace std;
#define N 5010

int n, ansm = INT_MAX, ansk;
int a[N];
bool diff[N];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		char ch;
		cin >> ch;
		if (ch == 'F') a[i] = 1;
	}
	for (int k = 1; k <= n; k++) {
		memset(diff, 0, sizeof(diff));
		int flag = 1, tot = 0, now = 0; 
		for (int i = 1; i <= n; i++) {
			now ^= diff[i];
			if ((a[i] ^ now) == 0) {
				if (i + k - 1 > n) {
					flag = 0;
					break;
				}
				tot++;
				now ^= 1;
				diff[i + k] ^= 1;
			}
		}
		if (flag) {
			if (tot < ansm) {
				ansm = tot;
				ansk = k;
			}
		}
	}
	cout << ansk << " " << ansm << endl;
	return 0;
}
