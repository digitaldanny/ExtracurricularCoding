// https://leetcode.com/problems/running-sum-of-1d-array/

#include <vector>
#include <stdio.h>

using std::vector;

#define SOL 2

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
#if SOL == 1
        return Sol1(nums);
#elif SOL == 2
        return Sol2(nums);
#endif
    }

#if SOL == 1
    /*
     * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
     * DESCRIPTION: Sol1
     * 
     * BIG O:
     * f(n) = O(n)
     * 
     * PERFORMANCE:
     * Runtime - 8 ms, faster than 42.34% of c++ submissions
     * Memory - 8.8 MB, less than 50.00% of c++ submissions
     * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    */
    vector<int> Sol1(vector<int>& nums) {
        int N = nums.size();
        vector<int> runSum(N); // saves time by avoiding push_back

        // Put first sum in output to avoid making a switch case
        // in the for loop.
        runSum[0] = nums[0];

        for (int i = 1; i < N; i++)
        {
            runSum[i] = runSum[i-1] + nums[i];
        }
        return runSum;
    }
#endif

#if SOL == 2
    /*
     * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
     * DESCRIPTION: Sol2
     * This solution is similar to Sol1 but saves space and time
     * by creating a running sum from the passed vector rather 
     * than creating a new vector.
     * 
     * BIG O:
     * f(n) = O(n)
     * 
     * PERFORMANCE:
     * Runtime - 4 ms, faster than 92.40% of c++ submissions
     * Memory - 8.5 MB, less than 100.00% of c++ submissions
     * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    */
    vector<int> Sol2(vector<int>& nums) {
        int N = nums.size();

        // First iteration can be skipped since the sum will be the same
        // as the original value.
        for (int i = 1; i < N; i++)
        {
            nums[i] += nums[i-1];
        }
        return nums;
    }
#endif
};