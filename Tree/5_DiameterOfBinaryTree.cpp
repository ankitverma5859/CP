//Link: https://leetcode.com/problems/diameter-of-binary-tree/

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
    int find_diameter(TreeNode* root, int& diameter){
        if(root == NULL) return 0;
        
        int lh = find_diameter(root->left, diameter);
        int rh = find_diameter(root->right, diameter);
        diameter = max(diameter, lh+rh);

        return 1 + max(lh, rh);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        /*
        Approach: 
        Diamters is lh+rh so we take the height code. We know left height and right height at every node. Hence, we calculate the maximum of lh+rh at every node.
        */
        int diameter = 0;
        
        find_diameter(root, diameter);
        
        return diameter;
    }
};
