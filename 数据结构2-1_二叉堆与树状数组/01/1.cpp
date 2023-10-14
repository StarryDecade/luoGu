#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 2e5 + 7;

int n, m, r = 1, q;
int a[N];
priority_queue<int> A; // 维护第i小的数
priority_queue<int, vector<int>, greater<int>> B; 

/*
*	题意：每一次都先加入q个数，输出这前i + 1的数的大小
*	解法：用小顶堆维护前i个大小的数，用大顶堆维护i+1大小的数
*	目的：就是可以随时随地的取i 与i + 1
*/

int main (int argc, char *argv[]) {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 1; i <= m; i++) {
		cin >> q;
		for (int j = r; j <= q; j++) {
			A.push(a[j]);
			if (A.size() == i) {
				B.push(A.top());
				A.pop();
			}
		}
		r = q + 1;
		cout << B.top() << endl;
		A.push(B.top());
		B.pop();
	}
	return 0;
}
