'''
https://practice.geeksforgeeks.org/problems/print-gfg-n-times/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=print-gfg-n-times
'''

class Solution:
    def printGfg(self, n):
        def printer(n):
            if n <= 0:
                return
            print("GFG", end=' ')
            printer(n-1)
            
        return printer(n)
