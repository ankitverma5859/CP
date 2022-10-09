//Link: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/submissions/

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
    
    void inorder(TreeNode* root, vector<int>& sortedArr){
        if(root == NULL)
            return;
        
        inorder(root->left, sortedArr);
        sortedArr.push_back(root->val);
        inorder(root->right, sortedArr);
    }
    
    bool findTarget(TreeNode* root, int k) {
        vector<int> sortedArr;
        
        inorder(root, sortedArr);
        
        int i=0, j=sortedArr.size() - 1;
        bool res = false;
        while(i<j){
            int sum = sortedArr[i] + sortedArr[j];
            if(sum == k){
                res = true;
                break;
            }
            
            if(sum < k)
                i++;
            else if(sum > k)
                j--;
        }
        
        return res;
    }
};
