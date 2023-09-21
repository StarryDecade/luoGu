#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

struct p {
	int num;
	int g;
};

int n;
p rd[200];

bool cmp(p a, p b) {
	return a.g > b.g;
}

int main() {
	cin >> n;
	n = pow(2, n);
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		rd[i].g = tmp;
		rd[i].num = i;
	}

	sort(rd + 1, rd + 1 + n / 2, cmp);
	sort(rd + 1 + n / 2, rd + 1 + n, cmp);
	
	if (rd[1].g > rd[1 + n / 2].g) cout << rd[1 + n / 2].num << endl;
	else cout << rd[1].num << endl;
	return 0;
}
