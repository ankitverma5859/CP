// Link: https://practice.geeksforgeeks.org/problems/reverse-a-stack/1
// Reference: https://www.youtube.com/watch?v=BmZnJehDzyU&list=PLDzeHZWIZsTrhXYYtx4z8-u8zA-DzuVsj&index=2&ab_channel=CodeHelp-byBabbar 
//            38:00

class Solution{
public:
    void insertAtBottom(stack<int>& St, int ele){
        if(St.empty()){
            St.push(ele);
            return;
        }
        
        int val = St.top();
        St.pop();
        
        insertAtBottom(St, ele);
        St.push(val);
    }
    
    void rev(stack<int>& St){
      
        /*
          Base Condition:
          If Stack is empty, RETURN;
          
          S1: Store the top, and then pop it.
          S2: Recurse with stack of size(n-1)
          S3: When recurses back store the top element at the bottom.
        */
        if(St.empty()){
            return;
        }
        
        //S1
        int top = St.top();
        St.pop();
      
        //S2
        rev(St);
        
        //S3
        insertAtBottom(St, top);
    }
    
    stack<int> Reverse(stack<int> St){
        rev(St);
        return St;
    }
};
