//Link: https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

class Solution {
public:
    // If a node doesn't have both the left and right children, then it is a leaf node
    bool isLeaf(Node* node){
        return (node->left == NULL) and (node->right == NULL);
    }
    
    // Method to add the left boundary nodes without the leaf nodes
    void addleftBoundary(Node* root, vector<int>& res){
        Node* curr = root->left;
        
        //Until current node exists go to left left left
        while(curr){
            if(!isLeaf(curr)) res.push_back(curr->data);
            if(curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }
    
    // Method to add the leaves of the tree
    void addLeaves(Node* node, vector<int>& res){
        if(isLeaf(node)){
            res.push_back(node->data);
            return;
        }
        
        if(node->left )addLeaves(node->left, res);
        if(node->right) addLeaves(node->right, res);
    }
    
    // Method to add the right boundary
    void addrightBoundary(Node* node, vector<int>& res){
        // DS to store the values and can be used to store in actual result in reverse order.
        vector<int> tmp;
        
        Node* curr = node->right;
        while(curr){
            if(!isLeaf(curr)) tmp.push_back(curr->data);
            
            if(curr->right) curr = curr->right;
            else curr = curr->left;
        }
        
        //Adding the tmp values in reverse order for the boundary
        for(int i=tmp.size() - 1; i>=0; i--){
            res.push_back(tmp[i]);
        }
        
    }
    
    vector <int> boundary(Node *root)
    {
        vector<int> res;
        
        //If there are no nodes
        if(root == NULL) return res;
        
        //Add the root node to result if it is not a leaf node.
        if(!isLeaf(root)) res.push_back(root->data);
        
        //Add the left boundary without the leaf nodes
        addleftBoundary(root, res);
        
        //Add the leaves
        addLeaves(root, res);
        
        //Add the right boudary, needs ds to store the elements in reverse order.
        addrightBoundary(root, res);

        return res;
    }
};
