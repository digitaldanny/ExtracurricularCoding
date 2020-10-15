#include <vector>
#include <deque>

using namespace std;

class Node {
public:
  string name;
  vector<Node *> children;

  Node(string str) { name = str; }

	/*
		Time Complexity: O(V + E)
			All nodes traversed at some point O(V)
			For every node, we add every child node to the queue O(E)
			
		Space Complexity: O(V)
			Storing an array of V nodes.
			In worst case, all V nodes are children of the root and so the queue would contain all V nodes at once.
	*/
  vector<string> breadthFirstSearch(vector<string> *array) {
  	Node* curr;
		
		// Queue for BFS
		deque<Node*> queue;
		queue.push_front(this);
		
		while(!queue.empty())
		{
			// Get the next node to search
			curr = queue.front();
			queue.pop_front();
			
			cout << curr->name << endl; // debugging
			array->push_back(curr->name);
			
			for (int i = 0; i < curr->children.size(); i++)
			{
				cout << "Adding: " << curr->children[i]->name << endl;
				queue.push_back(curr->children[i]);
			}
		}
		return *array;
  }

  Node *addChild(string name) {
    Node *child = new Node(name);
    children.push_back(child);
    return this;
  }
};