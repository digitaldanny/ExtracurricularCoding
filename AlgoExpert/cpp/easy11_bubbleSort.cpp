#include <vector>
using namespace std;

/*
	Time complexity: O(N^2)
		In worst case, the while(performedSwap) loop will happen N times.
		
	Space complexity: O(1)
		This algorithm happens in-place.
*/
vector<int> bubbleSort(vector<int> array) {
  
	// Bubble sort is complete after no swaps have happened for that iteration.
	bool performedSwap = true;
	
	// After each iteration of bubble sort, we know that the right-most 
	// number will be correctly sorted. After each iteration, we can reduce
	// this number by 1.
	int endIndex = array.size()-1;

	while (performedSwap)
  {
		performedSwap = false;
		for (int i = 0; i < endIndex; i++) {
			if (array[i] > array[i+1])
			{
				swap(array[i], array[i+1]);
				performedSwap = true;
			}
		}
		endIndex--;
	}
	return array;
}