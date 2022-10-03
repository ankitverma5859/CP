//Link: https://leetcode.com/problems/same-tree/
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
    bool is_same(TreeNode* p, TreeNode* q){
        //Condition1: p and q are root nodes i.e no elements in both the trees
        //            if both are null i.e both are identical then return true
        
        //Condition2: p and q are left/right of leaf nodes then return true as 
        //            both will be null. If either of them in not null then one 
        //            of the tree has extre node
        if(p == NULL || q == NULL)
            return p == q;
        
        //Check for the tree conditions
        return (p->val == q->val) 
            and is_same(p->left, q->left) 
            and is_same(p->right, q->right);
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
       return is_same(p, q);
    }
};
