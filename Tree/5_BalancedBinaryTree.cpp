//Link: https://leetcode.com/problems/balanced-binary-tree/

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
    int check(TreeNode* root){
        if(root == NULL) return 0;
        
        int lh = check(root->left);
        if(lh == -1) return -1; // checking if the left subree at anypoint has diff -1
        
        int rh = check(root->right);
        if(rh == -1) return -1; // checking if the right subree at anypoint has diff -1
        
        // Returning -1 when the difference between a right subtree and left subtree is more than 1 then its not balance.
        if(abs(lh - rh) > 1) return -1;
        return 1+max(lh, rh);
    }
    bool isBalanced(TreeNode* root) {
        return check(root) == -1 ? false : true;
    }
};
