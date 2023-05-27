'''
https://practice.geeksforgeeks.org/problems/print-first-n-fibonacci-numbers1002/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=print-first-n-fibonacci-numbers
'''

# Recursive Solution
class Solution:
    #Function to return list containing first n fibonacci numbers.
    def printFibb(self,n):
        res = [1,1]
        def helper(res, cnt, n, prev, prev_prev):
            # base condition
            if cnt == n:
                return res
            
            # operation
            res.append(prev + prev_prev)

            # recursion
            return helper(res, cnt+1, n, prev_prev, prev + prev_prev)
        return helper(res, 1, n-1, 1, 1)
      
# Iterative Solution
class Solution:
    #Function to return list containing first n fibonacci numbers.
    def printFibb(self,n):
        if n == 0:
            return []
        elif n == 1:
            return [1]
        res = [1,1]
        prev, prev_prev = 1, 1
        
        for i in range(2, n):
            res.append(prev + prev_prev)    
            prev, prev_prev = prev_prev, prev + prev_prev
            
        return res
