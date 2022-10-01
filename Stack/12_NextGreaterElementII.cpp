//Link: https://leetcode.com/problems/next-greater-element-ii/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> s;
        
        // 2*n - 1 circular 
        for(int i=2*n-1; i>=0; i--){
            while(!s.empty() and s.top() <= nums[i%n])
                s.pop();
            
            // Checkout
            if(i < n){
                if(!s.empty())
                    res[i%n] = s.top();
            }
            s.push(nums[i%n]);
        }
        return res;
    }
};
