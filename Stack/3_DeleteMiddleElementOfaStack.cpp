// Link: https://practice.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1

class Solution
{
    public:
    
    void solve(stack<int>&s, int cnt, int size){
        //When we reach the middle element, we pop it. Job Done
        if(cnt == size/2){
            s.pop();
            return;
        }
        
        //If we havent reached the middle element, we will store the current element in a variable so that we can add it while we are recursing back
        int num = s.top();
        s.pop();  // We pop the element so that we can go access the next element
        solve(s, cnt+1, size); // Recursing untill we reach the middle element
        s.push(num);  //Pushing back the element.
    }
    
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // Recurse till the middle element of the stack, delete it, and while recursing back push the elements.
        int count = 0;
        solve(s, count, sizeOfStack);
    }
};
