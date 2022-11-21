//Link: https://leetcode.com/problems/binary-tree-preorder-traversal/
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
    void preorder(TreeNode* node, vector<int>& res){
        if(node == NULL)
            return;
        res.push_back(node->val);
        preorder(node->left,res);
        preorder(node->right,res);
    }
    vector<int> preorderTraversal(TreeNode* root) {
       vector<int> res;
        
        preorder(root, res);
        
        return res;
    }
};
