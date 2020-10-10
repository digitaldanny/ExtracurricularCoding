#include <vector>
using namespace std;

/*
	Time Complexity: O(N^2)
		Worst case
		
	Space Complexity: O(1)
		Swaps in place
*/ 
vector<int> insertionSort(vector<int> array) {
	
	for (int i = 0; i < array.size()-1; i++)
	{
		for (int j = i; j >= 0; j--)
		{
			if (array[j+1] < array[j])
			{
				cout << "Swapping: " << array[j] << ", " << array[j+1] << endl;
				swap(array[j], array[j+1]);
			}
			else
				break;
		}
		cout << "Iteration Complete\n" << endl;
	}
	
	// display array contents
	for (int i = 0; i < array.size(); i++)
	{
		cout << array[i] << ", ";
	}
	return array;
}