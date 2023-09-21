#include <iostream>

using namespace std;
const int maxsize = 1e6 + 7;

struct node {
	int left;
	int right;
};

int n;
node tree[maxsize];
int maxdeep = 1;

void dfs(int num, int deep) {
	if (num == 0) return;
	maxdeep = max(maxdeep, deep);
	dfs(tree[num].left, deep + 1);
    dfs(tree[num].right, deep + 1);
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int l, r;
		cin >> l >> r;
		tree[i].left = l;
		tree->right = r;
	}
	dfs(1, 1);
	cout << maxdeep << endl;
	return 0;
}
