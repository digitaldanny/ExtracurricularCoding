// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

#include <vector>
#include <stdio.h>

using std::vector;

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return Sol1(nums);
    }

    /*
     * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
     * DESCRIPTION: Sol1
     * 
     * BIG O:
     * O(n) since all N indices are visited once?
     * 
     * PERFORMANCE:
     * Runtime - 12 ms, faster than 98.23% of c++ submissions
     * Memory - 20.7 MB, less than 55.91% of c++ submissions
     * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    */
    TreeNode* Sol1(vector<int>& nums) {
        int L = 0;              // start at beginning of vector
        int R = nums.size()-1;  // end at end of the vector
        TreeNode* root = nullptr; // nullptr matches left/right pattern in recursive function
        return dfs(nums, root, L, R);
    }

    TreeNode* dfs(vector<int>& nums, TreeNode* node, int L, int R)
    {
        // Base requirement for recursion satisfied
        if (L > R)
            return node;

        // calculate midpoint index
        // Using bitshift >>1 caused infinite loop due to 'floor'-like functionality
        int mid = L + (R-L)/2;
        //printf("left: %d, right: %d, mid: %d, midVal: %d\n", L, R, mid, nums[mid]);
        
        // Found node's value.. only assigning midpoints forces the tree to be balanced upon creation
        // Use "new" to add into heap memory so struct allocation stays after func return
        node = new TreeNode(nums[mid]);

        // Recursively set all left nodes first, then right.
        node->left = dfs(nums, node->left, L, mid-1);
        node->right = dfs(nums, node->right, mid+1, R);
        return node;
    }
};
