#include <vector>

using std::vector;

class Solution {
public:

    // LeetCode user - OldCodingFarmer
    /* [4,5,6,7,0,1,2], target == 0
     *  0 1 2 3 4 5 6
     * 
     * Iter 0:
     * l = 0
     * r = 6
     * m = 3
     * numM = 7, != target.. continue
     * if numM {7} < numR {2}.. False, check 'else'
     * else 
     *  if numL {4} <= target {0}.. False, check else
     *  else 
     *    l = m {3} + 1 = 4... (Increase mid pointer)
     *
     *
    */
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        
        while (l<=r) {
            int mid = (r-l)/2+l; // trunc
            
            // Target is found, return.
            if (nums[mid] == target)
                return mid;
                
            // Narrow down the Left and Right boundaries to pinpoint the target
            // [4, 5, 6, 7, 0, 1, 2]
            //     L  M  R           
            if (nums[mid] < nums[r]) {                     

                // [4, 5, 6, 7, 0, 1, 2]
                //     L  M  R   
                // *** NORMAL BIN SEARCH CASE    
                if (nums[mid]<target && target<=nums[r])  
                    l = mid+1;

                else                                       
                    r = mid-1;
            } 

            // Narrow down the Left and Right boundaries to pinpoint the target
            // [4, 5, 6, 7, 0, 1, 2]
            //        L  M  R    
            else {
                // If left value is less than, equal target AND target less than middle value, 
                // move RIGHT boundary left
                // *** NORMAL BIN SEARCH CASE
                // [4, 5, 6, 7, 0, 1, 2]
                //              L  M  R  : before
                //             /.LRM       : after (pinpoints target on next iteration)
                if(nums[l]<=target && target<nums[mid])
                    r = mid-1;

                // If left value is greater than target OR target greater/equal than middle value, 
                // move LEFT boundary right
                // [4, 5, 6, 7, 0, 1, 2]
                //  L        M        R     : before
                //              L  M  R     : after
                else
                    l = mid+1;
            }
        }
        
        // Target not found.
        return -1;
    }
};
