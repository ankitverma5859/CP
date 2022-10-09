//Link: https://leetcode.com/problems/search-in-a-binary-search-tree/
/*
All the elements on the left side are smaller than the root. 
All the elements on the right side are larger than the root.
*/

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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL) return NULL;
        
        if(root->val == val) return root;
        
        if(val < root->val)
            return searchBST(root->left, val);
        return searchBST(root->right, val);
    }
};
