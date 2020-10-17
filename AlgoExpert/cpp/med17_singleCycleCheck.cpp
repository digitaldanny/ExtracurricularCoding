using namespace std;

/*
	Time Complexity: O(N)
	Space Complexity: O(1)
*/
bool hasSingleCycle(vector<int> array) {
	int count = 0;
	int N = array.size();
	int index = 0;
	
	while (count < N)
	{
		index += array[index];
		
		// Handle array wrapping
		if (index >= N) 
			index = (index%N);
		else if (index < 0)
			index = (index%N) == 0 ? (index%N) : (index%N) + N;
		
		// first node visited again AND we haven't completed 0
		if (index == 0 && count < N-1) 
			return false;
		
		count++;
	}
	
	return index == 0;
}
