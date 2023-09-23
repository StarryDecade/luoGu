#include <iostream>
using namespace std;
const int maxL = 30;
struct node {
	char left;
	char right;
}tree[maxL];

void dfs(char root) {
	if (root == '*')	return ;
	cout << root;
	dfs(tree[root].left);
	dfs(tree[root].right);
}

int main() {
	string str[30];
	char root;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		char val, left, right;
		cin >> val >> left >> right;
		if (i == 1)	root = val;
		tree[val].left = left;
		tree[val].right = right;
	}
	dfs(root);
	return 0;
}
