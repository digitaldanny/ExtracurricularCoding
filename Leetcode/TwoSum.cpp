#include <vector>
#include <algorithm>
#include <unordered_map>

using std::vector;
using std::sort;
using std::unordered_map;

#define SOL 3

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
#if SOL == 1
        return sol1(nums, target);
#elif SOL == 2
        return sol2(nums, target);  
#elif SOL == 3 
        return sol3(nums, target);  
#endif
    }

#if SOL == 1
    /*
     * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
     * DESCRIPTION: sol1
     * Brute force search.
     * 
     * BIG O:
     * f(n) = O(N^2)
     * 
     * PERFORMANCE:
     * Runtime - 188 ms, faster than 35.27% of c++ submissions
     * Memory - 9 MB, less than 99.04% of c++ submissions
     * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    */
    vector<int> sol1(vector<int>& nums, int target)
    {
        // this declaration avoids resizing with push_back
        vector<int> indices(2);

        int first;
        int N = (int)nums.size();

        for (int i = 0; i < N; i++)
        {
            // this assignment reduces # of vector accesses in next loop
            first = nums[i];

            // starting j at next index speeds up search
            for (int j = i+1; j < N; j++)
            {
                if (first + nums[j] == target)
                {
                    indices[0] = i;
                    indices[1] = j;
                }
            }
        }

        return indices;
    }

#elif SOL == 2
    /*
     * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
     * DESCRIPTION: sol2
     * - Sort the vector with std::sort which is O(n*log(n))
     * - Loop through vector with a = vec[i] which is O(n)
     * - Perform binary search for b such that target = a + b which is O(log(n))
     * - NOTE: This solution does NOT work because sorting the vector ruins the index values
     * 
     * BIG O:
     * f(n) = n*log(n) + n*log(n)
     *      = O(n*log(n)) 
     * 
     * PERFORMANCE:
     * N/A
     * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    */
    vector<int> sol2(vector<int>& nums, int target)
    {
        // this declaration avoids resizing with push_back
        vector<int> indices(2);

        int a;
        int b;
        int j;
        int binSearchStart;
        int binSearchEnd;
        int N = (int)nums.size();

        // For algorithm to work, vector must be sorted
        sort(nums.begin(), nums.end());

        // Iterate through sorted vector
        for (int i = 0; i < N; i++)
        {
            a = nums[i];

            // Binary search for b such that a+b = target
            b = target - a;
            binSearchStart = i + 1;
            binSearchEnd = N-1;

            // Solution was found if BinarySearch returns a valid index
            if ((j = BinarySearch(nums, binSearchStart, binSearchEnd, b)) > -1)
            {
                indices[0] = i;
                indices[1] = j;
                return indices;
            }
        }

        return indices;
    }

    // recursive binary search function returns index of target
    int BinarySearch(vector<int>& nums, int left, int right, int target)
    {
        // algorithm can continue
        if (right >= left)
        {
            int mid = left + (right - left) / 2;

            // Binary search has found the target
            if (nums[mid] == target)
                return mid;

            // If left, perform search to the left
            if (target < nums[mid])
                return BinarySearch(nums, left, mid-1, target);

            return BinarySearch(nums, mid+1, right, target);
        }

        // index could not be found
        else
        {
            return -1;
        }  
    }

#elif SOL == 3
    /*
     * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
     * DESCRIPTION: sol3
     * - This solution solves sol2's failure by mapping original 
     *   values and their vector indices. Additionally, it uses
     *   a map for instant target search rather than a binary
     *   search tree which improves the search from O(log(n))
     *   to O(1).
     * - Iterate through vector O(n)
     * - Search for complement in unordered map O(1) or O(n) worst case
     * - Insert to map if necessary O(1) or O(n) worst case
     * 
     * BIG O:
     * f(n) = n*(1 + 1) or n*(n + n)
     *      = 2*n average or 2*n^2 worst case
     *      = O(n) average or O(n^2) worst case
     * 
     * PERFORMANCE:
     * Runtime - 12 ms, faster than 97.03% of c++ submissions
     * Memory - 10.2 MB, less than 31.80% of c++ submissions
     * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    */
    vector<int> sol3(vector<int>& nums, int target)
    {
        // this declaration avoids resizing with push_back
        vector<int> indices(2);

        // hash map has O(1) search time except O(n) during collisions
        unordered_map<int, int> umap;
        int N = nums.size();

        // build map as I search through vector
        for (int i = 0; i < N; i++)
        {
            // search for complement key in map.
            auto iter = umap.find(target - nums[i]);
            
            // If the complement was found, return the indices
            if (iter != umap.end() && iter->second != i)
            {
                indices[0] = i;
                indices[1] = iter->second;
                return indices;   
            }
            
            // Add the new value to the map to be searched in the next iteration
            // The map's key will be the vector's values / map's values will be vector's indices 
            umap[nums[i]] = i;
        }

        return indices;
    }
#endif
};