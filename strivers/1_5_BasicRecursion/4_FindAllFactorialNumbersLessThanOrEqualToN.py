'''
https://practice.geeksforgeeks.org/problems/find-all-factorial-numbers-less-than-or-equal-to-n3548/0?problemType=functional&difficulty[]=-1&page=1&query=problemTypefunctionaldifficulty[]-1page1&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-all-factorial-numbers-less-than-or-equal-to-n
'''

# Iterative
class Solution:
    def factorialNumbers(self, N):
    	ans = []
    	
    	current_fact_val = 1
    	i = 1
    	while True:
    	    if current_fact_val > N:
    	        break
    	    
    	    ans.append(current_fact_val)
    	    current_fact_val *= i + 1
    	    i += 1
    	return ans
    
# Recursive
class Solution:
    def factorialNumbers(self, N):
        res = []
        def helper(res, curr_val, i, N):
            if curr_val > N:
                return
    
            res.append(curr_val)
            return helper(res, curr_val*(i+1), i+1, N)
        helper(res, 1, 1, N)
        return res
    	    
          
  
