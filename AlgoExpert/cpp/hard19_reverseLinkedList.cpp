using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value) {
    this->value = value;
    this->next = NULL;
  }
};

/*
	Time Complexity: O(N)
		Loops through entire linked list once
		
	Space Complexity: O(1)
		Only allocates 3 variables for any size linked list
*/
LinkedList *reverseLinkedList(LinkedList *head) {
  LinkedList* prev = NULL;
	LinkedList* curr = head;
	LinkedList* next = head->next;
	
	while (curr != NULL)
	{
		next = curr->next;
		
		// Reverse connection for curr/next nodes
		curr->next = prev;
		prev = curr; 
		curr = next; 
	}
  return prev;
}