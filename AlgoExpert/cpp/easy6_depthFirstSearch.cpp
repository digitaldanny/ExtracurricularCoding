#include <vector>
using namespace std;

/*
 * Time Complexity: O(V + E)
 *		V = Number of vertices
 * 		E = Number of edges
 * 		Each vertex is visited + each vertices children are traversed.
 *
 * Space Complexity: O(V)
 * 		Each recursive call adds to the stack frame, and a dfs call
 *		happens for each of the vertices.
 */
class Node {
public:
  string name;
  vector<Node *> children;
	
  Node(string str) { name = str; }

  vector<string> depthFirstSearch(vector<string> *array) {
  	return *dfs(this, array);
  }
	
	vector<string>* dfs(Node* node, vector<string>* array) {
		if (node == nullptr)
			return array;
		
		// Add the next node's name
		array->push_back(node->name);
		//cout << node->name << endl; // DEBUGGING
		
		// Search child nodes from left to right
		for (int i = 0; i < node->children.size(); i++) {
			array = dfs(node->children[i], array);
		}
		return array;
	}

  Node *addChild(string name) {
    Node *child = new Node(name);
    children.push_back(child);
    return this;
  }
};
