//Link: https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> res;
        if(root == NULL) return res;
        
        //<vertical_line_num, top/first_node_value>
        map<int, int> m;
        
        //<Node, vertical_line_num>
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()){
            auto tmp = q.front();
            Node* node = tmp.first;
            int line = tmp.second;
            q.pop();
            
            if(m.find(line) == m.end()) m[line] = node->data;
            
            if(node->left) q.push({node->left, line-1});
            if(node->right) q.push({node->right, line+1});
        }
        
        for(auto a : m){
            res.push_back(a.second);
        }
        return res;
    }

};
