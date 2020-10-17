using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = NULL;
    right = NULL;
  }
};

int dfsSum(BinaryTree* root, int parentDepth)
{
	// A NULL node will not add any depth to the total depth sum
	if (root == NULL)
		return 0;

	// This node's depth is +1 from the parent node's depth
	int currDepthSum = parentDepth + 1; 
	
	// Recursive calls to child nodes
	currDepthSum += dfsSum(root->left, parentDepth+1);
	currDepthSum += dfsSum(root->right, parentDepth+1);
	return currDepthSum;
}

int nodeDepths(BinaryTree *root) {
  return dfsSum(root, -1); // start depth at -1 so root node's depth == 0 after parentDepth + 1
}