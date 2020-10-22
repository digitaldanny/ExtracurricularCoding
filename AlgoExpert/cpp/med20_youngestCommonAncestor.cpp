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

/*
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