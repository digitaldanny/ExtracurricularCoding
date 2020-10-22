#include <vector>
using namespace std;

class AncestralTree {
public:
  char name;
  AncestralTree *ancestor;

  AncestralTree(char name) {
    this->name = name;
    this->ancestor = NULL;
  }

  void addAsAncestor(vector<AncestralTree *> descendants);
};

#define SOL 2

#if SOL == 1
/*
	SOLUTION 1 (Brute force):
	------------------------
	Time Complexity: O(N^2)
	Space Complexity: O(1)
	Description:
		Iterate through both linked lists, looking for common nodes. 
*/
AncestralTree *getYoungestCommonAncestor(AncestralTree *topAncestor,
                                         AncestralTree *descendantOne,
                                         AncestralTree *descendantTwo) {
  
	// Capture head of the inner list for reseting later
	AncestralTree* headDescTwo = descendantTwo;
	
	while (descendantOne != topAncestor)
	{
		cout << "ONE: " << descendantOne->name << endl;
		// reset head to inner list for each iteration
		descendantTwo = headDescTwo; 
		
		while (descendantTwo != topAncestor)
		{
			cout << "TWO: " << descendantTwo->name << endl;
			if (descendantTwo == descendantOne)
				return descendantTwo;
			else
				descendantTwo = descendantTwo->ancestor;
		}
		descendantOne = descendantOne->ancestor;
	}
  return topAncestor;
}
#endif 

#if SOL == 2

// prototype
int findDepth(AncestralTree *topAncestor, AncestralTree *descendant);
	
/*
	SOLUTION 2:
	------------------------
	Time Complexity: O(D), where D is depth of the deeper node
	Space Complexity: O(1)
	Description:
		Iterate through the deeper node until both nodes are at the same height.
		Then iterate through both at the same time until finding common parent.
*/
AncestralTree *getYoungestCommonAncestor(AncestralTree *topAncestor,
                                         AncestralTree *descendantOne,
                                         AncestralTree *descendantTwo) {
  
	// Find depths of both nodes
	int depthOne = findDepth(topAncestor, descendantOne);
	int depthTwo = findDepth(topAncestor, descendantTwo);
	
	// Whichever node is deeper, catch up to the other node
	int diff = depthOne - depthTwo;
	cout << "DIFF: " << diff << endl;
	
	if (diff > 0)
	{
		// Catch descendantOne up
		for (int i = 0; i < diff; i++)
			descendantOne = descendantOne->ancestor;
	}
	else if (diff < 0)
	{
		// Catch descendantTwo up
		for (int i = 0; i < -1*diff; i++)
			descendantTwo = descendantTwo->ancestor;
	}
	// else (diff == 0)
	// 	they have equal depths already
	
	// Find the common ancestor by stepping through at the same time
	while (descendantTwo != descendantOne)
	{
		descendantTwo = descendantTwo->ancestor;
		descendantOne = descendantOne->ancestor;
	}
	return descendantOne;
}

int findDepth(AncestralTree *topAncestor, AncestralTree *descendant)
{
	int depth = 0;
	while (descendant != topAncestor)
	{
		depth++;
		descendant = descendant->ancestor;
	}
	return depth;
}
#endif
