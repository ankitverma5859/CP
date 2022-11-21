//Link: https://leetcode.com/problems/binary-tree-level-order-traversal/
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
    SC: O(n) Auxiliary Space used by Queue
*/
class Solution {
public:
    
    void bfs(TreeNode* root, vector<vector<int>>& res){
        // If there are no nodes, simply return.
        if(root == NULL) return;
        
        // Create a queue to store the nodes that needs to be processed in the queue
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            vector<int> level;
            int size = q.size();
            for(int i=0; i<size; i++){
                // Take out the node from the queue
                TreeNode* node = q.front();
                q.pop();
                
                // Add the left and right elements in the queue, so that they can be preocessed lated in the level order 
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                
                level.push_back(node->val);
            }
            // Add the level data
            res.push_back(level);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        
        bfs(root, res);
        
        return res;
    }
};
