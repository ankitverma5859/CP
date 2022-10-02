class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        
        // Root node's height is 1 and then we take max of left subtree and right subtree
        return 1 + max(lh, rh);
            
    }
};
