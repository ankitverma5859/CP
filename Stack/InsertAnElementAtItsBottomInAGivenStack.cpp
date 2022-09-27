// Link: https://www.codingninjas.com/codestudio/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166?leftPanelTab=0

#include <bits/stdc++.h> 
void solve(stack<int>& s, int x){
  
    //Once the stack is empty, push the value
    if(s.empty()){
        s.push(x);
        return;
    }
    
    int num = s.top();
    s.pop();
    
    //Recursive for the stack with one less size
    solve(s, x);
  
    // Store back the value
    s.push(num);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    solve(myStack, x);
    return myStack;
}
