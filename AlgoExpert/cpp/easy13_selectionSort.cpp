#include <vector>
using namespace std;

/*
	Selection sort:
	- Treat array as 2 separate portions - sorted first, then unsorted 2nd
	- Array starts fully unsorted, and the sorted portion grows by 1 each iteration
	- While not sorted:
	- 	Search for smallest value in remaining portion of the unsorted array
	-	Swap smallest value with first index of the unsorted array

	Time Complexity: O(N^2)
	Space Complexity: O(1)
*/
vector<int> selectionSort(vector<int> array) {
  
	/*
		for (i = 0; i < array.len; i++)
			min = array[i]
			for (j = i; j < array.len; j++)
				if (array[j] < min)
					min = array[j]
			swap(min, )
	*/
	
	for (int i = 0; i < array.size(); i++)
	{
		// Find the min value in the unsorted portion of the array
		int minIndex = i;
		for (int j = i; j < array.size(); j++)
		{
			if (array[j] < array[minIndex])
			{
				minIndex = j;
				cout << "Min: " << array[j] << endl;
			}
		}
		
		// Swap min value with the first element of the unsorted portion of the array
		cout << "Swapping: " << array[i] << ", " << array[minIndex] << endl;
		swap(array[i], array[minIndex]);
	}
	return array;
}
