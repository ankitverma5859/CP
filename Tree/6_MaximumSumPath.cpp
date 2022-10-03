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
    int max_sum(TreeNode* root, int& maxi){
        if(root == NULL) return 0;
        
        int left_sum = max(0, max_sum(root->left, maxi));     //Ignoring negative sum
        int right_sum = max(0, max_sum(root->right, maxi));   //Ignoring negative sum
        
        maxi = max(maxi, left_sum + right_sum + root->val);
        
        return root->val + max(left_sum, right_sum);
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        max_sum(root, maxi);
        
        return maxi;
    }
};
