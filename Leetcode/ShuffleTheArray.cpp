// https://leetcode.com/problems/shuffle-the-array/

#include <vector>
#include <stdio.h>

using std::vector;

#define SOL 1

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
#if SOL == 1
        return Sol1(nums, n);
#endif
    }

    /*
     * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
     * DESCRIPTION: Sol1
     * 
     * BIG O:
     * f(n) = n/2
     * f(n) = O(n)
     * 
     * PERFORMANCE:
     * Runtime - 8 ms, faster than 95.11% of c++ submissions
     * Memory - 9.9 MB, less than 63.47% of c++ submissions
     * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    */
    vector<int> Sol1(vector<int>& nums, int n) {
        int N = (n<<1)-1;

        vector<int> shuffle(N+1);

        // Set output array values in half the time
        for (int i = 0; i < n; i++)
        {
            //printf("i = %d\n", i);
            //printf("i<<1 = %d\n", i<<1);
            //printf("N-i = %d\n", N-i);
            //printf("N-(i<<1) = %d\n\n", N-(i<<1));
            shuffle[i<<1] = nums[i]; // first half of shuffle array
            shuffle[N-(i<<1)] = nums[N-i]; // second half of shuffle array
        }
        return shuffle;
    }
};