#include <cstdio>
#include <iostream>
using namespace std ;
const int maxl = 1e4 + 7;

int H[maxl];

int main() {
	int a, b, h;
	while (scanf("%d%d%d", &a, &h, &b) != EOF) {
		for (int i = a; i < b; i++) H[i] = max(H[i], h);
	}
	for (int i = 1, h = 0; i < 1e4; i++) {
		if (h != H[i]) {
			h = H[i];
			cout << i << " " << H[i] << " ";
		}
	}
	return 0;
}
