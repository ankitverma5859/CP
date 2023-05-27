'''
https://practice.geeksforgeeks.org/problems/print-1-to-n-without-using-loops-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=print_1_to_n_without_loop
'''

class Solution:    
    #Complete this function
    def printNos(self,N):
        i = 1
        def helper(i, N):
            # Base Condition
            if i > N:
                return
            
            print(i, end=' ')
            
            helper(i+1, N)
        return helper(i, N)
