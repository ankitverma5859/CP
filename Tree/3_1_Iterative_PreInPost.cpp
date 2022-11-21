/*
  The idea is to use one stack which stores a pair {node, itr}. 
  Condition 1: itr == 1
                  Take it in Preorder 
                  Increment itr and push back to stack
                  If a left node exists push back to stack
  Condition 2: itr == 2
                  Take it is Inorder
                  Increment itr and push back to stack
                  if a right node exists push back to stack
  Condition 3: itr == 3
                  Take it in Postorder
                  
                  
  TC: O(3n)     3 traversals for pre,in, and post
  SC: O(4n)     3 lists to store pre, in, and post. And 1 stack to store the pairs.
*/

void iterative_PreInPost(Treenode* root){
  if(root == NULL) return;
  
  stack<pair<Treenode*, int>> st;
  st.push_back({root, 1});
  vector<int> pre, in, post;
  while(!st.empty()){
    auto it = st.top();
    st.pop();
    
    if(st.second == 1){                 //Preorder
        pre.push_back(it.first->val);
        it.second++;
        st.push_back(it);
      
        if(it.first->left != NULL) st.push_back({it.first->left, 1});
    }
    else if(st.second == 2){            //Inorder
        in.push_back(it.first->val);
        it.second++;
        st.push_back(it);
      
        if(it.first->right != NULL) st.push_back(it.first->right, 1);
    }
    else{                               //Postorder
        post.push_back(it.first->val);
    }
  }
}
