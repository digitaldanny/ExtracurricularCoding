// https://leetcode.com/problems/merge-two-binary-trees/


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#define SOL 3

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        return Sol(t1, t2);
    }

#if SOL == 1
    TreeNode* Sol(TreeNode* t1, TreeNode* t2) {
        TreeNode* mergedTree;
        return bfs(mergedTree, t1, t2);
    }

    /*
     * val1;
     * val2;
     * 
     * if t1 == nullptr
     *      val1 = 0;     
     * else
     *      val1 = t1->val
     * 
      * if t2 == nullptr
     *      val2 = 0;     
     * else
     *      val2 = t2->val
     * 
     * // add node to new tree's current node
     * newNode->val = val1 + val2
     * 
     * // continue search
     * bfs(newNode->left, (t1 == nullptr) ? nullptr : t1->left, (t1 == nullptr) ? nullptr : t1->right)
     * bfs(newNode->right, (t1 == nullptr) ? nullptr : t1->left, (t1 == nullptr) ? nullptr : t1->right)
    */  

    TreeNode* bfs(TreeNode* newNode, TreeNode* t1, TreeNode* t2)
    {
        // If both trees are finished searching
        if (t1 == nullptr && t2 == nullptr)
            return nullptr;

        int val1, val2;

        // Get the tree1 value if it exists.. otherwise assign 0 so the 
        // sum doesn't error out.
        if (t1 == nullptr) {
            val1 = 0;
        }
        else {
            val1 = t1->val;
        }

        // Same as previous step for tree2
        if (t2 == nullptr) {
            val2 = 0;
        }
        else {
            val2 = t2->val;
        }

        // Tree1 + Tree2
        //printf("T1 = %d, T2 = %d, nextVal = %d\n", val1, val2, val1 + val2);
        newNode = new TreeNode(val1 + val2);

        // Explore left, then explore right (pre-order)
        newNode->left = bfs(newNode->left, (t1 == nullptr) ? nullptr : t1->left, (t2 == nullptr) ? nullptr : t2->left);
        newNode->right = bfs(newNode->right, (t1 == nullptr) ? nullptr : t1->right, (t2 == nullptr) ? nullptr : t2->right);    
        return newNode;
    }

#elif SOL == 2
    /*
     * Sol2
     * 
     * Time: O(n) -> every node is accessed
     * Space: O(n) -> up to n new nodes will be allocated
     * 
     * This solution improves on solution 1 by putting new values in place
     * of either tree 1 or tree 2 nodes. This could POSSIBLY reduce the 
     * max number of TreeNodes allocated with the TreeNode() constructor.
     * In the worst case, it will have the same performance as the first 
     * solution because selected in-place tree t1 could be a nullptr and 
     * ALL t2 values would have to be allocated and assigned to t1.
    */  
    TreeNode* Sol(TreeNode* t1, TreeNode* t2) {
        #define INPLACE t1

        // If both trees are finished searching
        if (t1 == nullptr && t2 == nullptr)
            return nullptr;

        int val1, val2;

        // Get the tree1 value if it exists.. otherwise assign 0 so the 
        // sum doesn't error out.
        if (t1 == nullptr) {
            val1 = 0;
        }
        else {
            val1 = t1->val;
        }

        // Same as previous step for tree2
        if (t2 == nullptr) {
            val2 = 0;
        }
        else {
            val2 = t2->val;
        }

        // Tree1 + Tree2
        //printf("T1 = %d, T2 = %d, nextVal = %d\n", val1, val2, val1 + val2);
        if (INPLACE == nullptr)
        {
            INPLACE = new TreeNode(val1 + val2);
        }
        else
        {
            INPLACE->val = val1 + val2;
        }
        

        // Explore left, then explore right (pre-order)
        INPLACE->left = Sol((t1 == nullptr) ? nullptr : t1->left, (t2 == nullptr) ? nullptr : t2->left);
        INPLACE->right = Sol((t1 == nullptr) ? nullptr : t1->right, (t2 == nullptr) ? nullptr : t2->right);    
        return INPLACE;
    }

#elif SOL == 3
    /*
     * Sol3
     * 
     * Time: O(n) -> every node is accessed
     * Space: O(n) -> up to n new nodes will be allocated
     * 
     * This removes the base case where t1 and t2 are null. If 1
     * tree is null, return the other.
     *
     * Also, in-order traversal is apparently faster for this problem.
     * Have not figured out why yet..
    */  
    TreeNode* Sol(TreeNode* t1, TreeNode* t2) {
        #define INPLACE t1

        // If 1 tree is a nullptr, return the other to speed up addition time.
        if (t1 == nullptr) return t2;
        if (t2 == nullptr) return t1;
        
        int val1, val2;
        
        // Explore left before processing (in-order traversal)
        INPLACE->left = Sol((t1 == nullptr) ? nullptr : t1->left, (t2 == nullptr) ? nullptr : t2->left);
        
        val1 = t1->val;
        val2 = t2->val;

        // Tree1 + Tree2
        //printf("T1 = %d, T2 = %d, nextVal = %d\n", val1, val2, val1 + val2);
        if (INPLACE == nullptr)
        {
            INPLACE = new TreeNode(val1 + val2);
        }
        else
        {
            INPLACE->val = val1 + val2;
        }
        
        // Explore right
        INPLACE->right = Sol((t1 == nullptr) ? nullptr : t1->right, (t2 == nullptr) ? nullptr : t2->right); 
        return INPLACE;
    }
#endif
};