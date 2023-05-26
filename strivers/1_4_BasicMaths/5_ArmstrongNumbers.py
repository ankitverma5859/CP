'''
https://practice.geeksforgeeks.org/problems/armstrong-numbers2727/1
'''
class Solution:
    def armstrongNumber (ob, n):
        # code here 
        N = n
        computed_val = 0
        while n > 0:
            rem = n % 10
            n = int(n/10)
            computed_val += rem**3
        
        return "Yes" if N == computed_val else "No"
