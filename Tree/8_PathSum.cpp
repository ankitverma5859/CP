//Link: https://leetcode.com/problems/path-sum/
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
    bool hastargetsum(TreeNode* root, int targetSum){
        if(root == NULL) return false;

        // For backtracking
        targetSum -= root->val;
        
        //Check if we have reached the leaf node and target sum has become zero return true
        if(!root->left and !root->right)
            return targetSum == 0; //returns true if targetSum is reached else false
        
        bool left = hastargetsum(root->left, targetSum);
        bool right = hastargetsum(root->right, targetSum);
        
        return left || right;  // Anyside we find true propagate backwards
        //return hastargetsum(root->left, targetSum) || hastargetsum(root->right, targetSum);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        return hastargetsum(root, targetSum);
    }
};
