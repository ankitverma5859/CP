//Link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        
        //q to store the node value, its vertical value, and its level value {val, {x, y}}
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0,0}});
        
        while(!q.empty()){
            int s = q.size();
            for(int i=0; i<s; i++){
                auto tmp = q.front();
                TreeNode* node = tmp.first;
                int x = tmp.second.first;
                int y = tmp.second.second;
                q.pop();
                
                // x is vertical
                // y is level
                // node->val is inserted in multiset
                nodes[x][y].insert(node->val);                
                // while going left, vertical value decrease by 1 and level order increase by 1
                if(node->left) q.push({node->left, {x-1, y+1}});
                // while going left, vertical value increase by 1 and level order increase by 1
                if(node->right) q.push({node->right, {x+1, y+1}});
            }
        }
        
        vector<vector<int>> res;
        for(auto n : nodes){
            // n represents (each vertical, with all levels and values)
            vector<int> r;
            for(auto m : n.second){
                // now taking all the levels of the vertical and inserting in.
                r.insert(r.end(), m.second.begin(), m.second.end());
            }
            res.push_back(r);
        }
        return res;
    }
};
