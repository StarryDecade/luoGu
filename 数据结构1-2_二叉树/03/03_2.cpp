#include <iostream>

using namespace std;
struct node {
	char id;
	node *left;
	node *right;
};

node *tree;

node* make(string s1, string s2) {
	node *root = new node; // 要开辟空间
	root->id = s2[0];
	int len1 = s1.find(root->id);
	int len2 = s1.size() - len1 - 1;
	if (len1)  root->left = make(s1.substr(0, len1), s2.substr(1, len1));
	if (len2)  root->right = make(s1.substr(len1 + 1, len2), s2.substr(len1 + 1, len2));
	return root;
}

void dfs(node *root) {
	if (root->id > 'Z' && root->id < 'A') return ;
	if (root->left) dfs(root->left);
	if (root->right) dfs(root->right);
	cout << root->id;
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	tree = make(s1, s2);
	dfs(tree);
	return 0;
}
