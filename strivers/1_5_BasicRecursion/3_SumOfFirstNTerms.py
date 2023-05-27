'''
https://practice.geeksforgeeks.org/problems/sum-of-first-n-terms5843/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=sum-of-first-n-terms
'''

# Recursion Error for large numbers
class Solution:
    def sumOfSeries(self,N) -> int:
        total_sum = 0
        def helper(total_sum, i, N) -> int:
            if i == N:
                total_sum += i**3
                return total_sum
            
            total_sum += i**3
            return helper(total_sum, i+1, N)
            
        return helper(total_sum, 1, N)
      
# Using the formula of i^3 + (i+1)^3 + (i+2)^3 + ..... n^3
'''
             
    |  n*(n+1) | ^ 2
    | -------  |
    |    2     |
'''
class Solution:
    def sumOfSeries(self,n) -> int:
        return ((n*(n+1))//2)**2
