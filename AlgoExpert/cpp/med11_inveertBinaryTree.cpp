#include <vector>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value);
  void insert(vector<int> values, int i = 0);
  void invertedInsert(vector<int> values, int i = 0);
};

void invertBinaryTree(BinaryTree *node) {
	if (node == NULL)
		return;
	
	swap(node->left, node->right);
	
	// dfs
	invertBinaryTree(node->left);
	invertBinaryTree(node->right);
	return;
}