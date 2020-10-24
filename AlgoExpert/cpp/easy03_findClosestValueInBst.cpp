#include <cmath>
using std::abs;

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

/*
	Time Complexity: O(logn)
		- BST eliminates half of the tree on average
		- Worst case O(N) where BST is set up more like a Linked List
	
	Space Complexity: O(logn) with recursive solution
		- Calls dfs function multiple times 
		- O(1) with iterative solution because it will not use the callstack
*/
BST *dfsRec(BST *node, int target, BST *minNode) {
	
	if (node == NULL)
		return minNode;
	
	// Check if the current node is closer to the target value
	if (abs(node->value - target) < abs(minNode->value - target))
		minNode = node;
	
	// Continue DFS
	minNode = dfsRec(node->left, target, minNode);
	minNode = dfsRec(node->right, target, minNode);
	return minNode;
}

BST *dfsIter(BST *node, int target, BST *minNode) {
	
	while (node != NULL) {
		
		if (abs(node->value - target) < abs(minNode->value - target))
			minNode = node;
		
		// BST traversal
		if (target < node->value)
			node = node->left;
		else if (target > node->value)
			node = node->right;
		else
			break; // current node IS target
	}
	return minNode;
}

int findClosestValueInBst(BST *tree, int target) {
	BST* minNode = tree;
	//return dfsRec(tree, target, minNode)->value;
	return dfsIter(tree, target, minNode)->value;
}