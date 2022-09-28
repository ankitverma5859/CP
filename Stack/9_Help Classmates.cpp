//Link: https://practice.geeksforgeeks.org/problems/fab3dbbdce746976ba35c7b9b24afde40eae5a04/1
//Reference: https://www.youtube.com/watch?v=lJLcqDsmYfg&list=PLDzeHZWIZsTrhXYYtx4z8-u8zA-DzuVsj&index=3&ab_channel=CodeHelp-byBabbar
// 12:28

/*
    Approach is to find the next smallest element from the end of the array
*/
class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        
        stack<int> s;
        s.push(-1); // Since, there is no element at end, the next element will be -1
        
        vector<int> res(n);

        // We trace from the back of the array
        for(int i=n-1; i>=0; i--){
            int curr = arr[i];
            
            // If the stacks top is greater than the current then we keep popping
            // since we are looking the next smallest element.
            while(s.top() >= curr)
                s.pop();
                
            // Storing the next elements from the back(i)
            res[i] = s.top();
            
            // Storing the current array in the stack for future comparisons
            s.push(curr);
        }
        return res;
    } 
};
