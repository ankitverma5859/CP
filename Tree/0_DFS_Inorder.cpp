// Link: https://leetcode.com/problems/binary-tree-inorder-traversal/
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

/*
    TC: O(n)
    SC: O(n) Auxiliary Space used in Recursion
*/
class Solution {
public:
    void inorder(TreeNode* node, vector<int>& res){
        if(node == NULL)
            return;
        
        inorder(node->left, res);
        res.push_back(node->val);
        inorder(node->right, res);
        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        
        inorder(root, res);
        
        return res;
    }
};
