#include <iostream>
using namespace std;
const int maxl = 1e6 + 7;

int n;
string ss;
int kmp[maxl];

int main() {
	cin >> n >> ss;
	for (int i = 1, j = 0; i < n; i++) {
		while(j && ss[i] != ss[j]) j = kmp[j - 1];
		if (ss[i] == ss[j]) j++;
		kmp[i] = j;
	}
	cout << n - kmp[n - 1] << endl;// 减去相等的，后面就是 相等 + 不相等的。然后循环就可以得到当前·字串
	return 0;
}
