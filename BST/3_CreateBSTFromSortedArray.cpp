//Link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBST(vector<int>& nums, int start, int end){
        //Base Condition: if start > end return NULL
        if(start > end) return NULL;
        
        //Keep Creating root nodes
        int mid = (start + end) >> 1;
        TreeNode* root = new TreeNode(nums[mid]);
        
        root->left = createBST(nums, start, mid-1);
        root->right = createBST(nums, mid+1, end);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        
        //Recursive Approach
        return createBST(nums, 0, n-1);
    }
};
