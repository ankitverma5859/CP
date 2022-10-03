//Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
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
    void zz_bfs(TreeNode* root, vector<vector<int>>& res){
        if(root == NULL) return;
        
        queue<TreeNode*> q;
        q.push(root);
        
        
        int l2r = 1;
        while(!q.empty()){
            int s = q.size();
            vector<int> r(s);   // checkout, declaring the vector with size so that index can be accessed
            
            for(int i=0; i<s; i++){
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                
                // if l2r is true that means we will fill from the left hence i based index
                // if l2r is false that means we will fill from the end
                int index = l2r ? i : s - i - 1;
                r[index] = node->val;
            }
            res.push_back(r);
            l2r = !l2r; // After ever level we reverse the direction.
        }
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        
        zz_bfs(root, res);
        
        return res;
    }
};
