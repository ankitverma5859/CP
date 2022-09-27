// Link: https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275?leftPanelTab=1

#include <bits/stdc++.h> 

void insertSorted(stack<int> &stack, int ele){
    // Find the val which is smaller than the element and then push above it.
    if(stack.empty() || (!stack.empty() && stack.top() < ele)){
        stack.push(ele);
        return;
    }
    
    int num = stack.top();
    stack.pop();
    
    insertSorted(stack, ele);
    stack.push(num);
}

void sortStack(stack<int> &stack)
{
	  if(stack.empty())
        return;
    
    int num = stack.top();
    stack.pop();
    
    // Recurse
    sortStack(stack);
  
    // When we recurse back, we will insert in sorted order, i.e all the elements will be in sorted order only the num has to be inserted at 
    // right place
    insertSorted(stack, num);
}
