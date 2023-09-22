#include <iostream>
using namespace std;

struct node {
	char val;
	node *left;
	node *right;
	node() : val(0), left(nullptr), right(nullptr){}
	node(char x) : val(x), left(nullptr), right(nullptr){}
	node(char x, node *left, node *right) : val(x), left(left), right(right){}
};

node *traversal(string s1, int inorderBegin, int inorderEnd, string s2, int preorderBegin, int preorderEnd) {
	if (preorderEnd == preorderBegin) return nullptr;
	char val = s2[preorderBegin];
	node *root = new node(val);

	if (preorderEnd - preorderBegin == 1) return root;

	int delimiterIndex; // 左右子树的分割点
	for (delimiterIndex = inorderBegin; delimiterIndex < inorderEnd; delimiterIndex++) {
		if (s1[delimiterIndex] == val) break;
	}
	
	// 左子树
	// 中序
	int leftInorderBegin = inorderBegin;
	int leftInorderEnd = delimiterIndex;
	// 前序
	int leftPreorderBegin = preorderBegin + 1;
	int leftPreorderEnd = preorderBegin + 1 + delimiterIndex - inorderBegin;

	// 右子树
	int rightInorderBegin = delimiterIndex + 1;
	int rightInorderEnd = inorderEnd;
	int rightPreorderBegin = preorderBegin + delimiterIndex - inorderBegin + 1;
	int rightPreorderEnd = preorderEnd;

	root->left = traversal(s1, leftInorderBegin, leftInorderEnd, s2, leftPreorderBegin, leftPreorderEnd);
	root->right = traversal(s1, rightInorderBegin, rightInorderEnd, s2, rightPreorderBegin, rightPreorderEnd);
	return root;
}

void dfs(node *root) {
	if (!root) return ;
	dfs(root->left);
	dfs(root->right);
	cout << root->val;
}


int main() {
	node *tree;
	string s1, s2;
	cin >> s1 >> s2;
	tree = traversal(s1, 0, s1.size(), s2, 0, s2.size());
	dfs(tree);
	return 0;
}
