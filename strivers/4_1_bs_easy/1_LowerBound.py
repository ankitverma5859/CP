'''
https://practice.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1?track=DSASP-Searching&amp%3BbatchId=154&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=floor-in-a-sorted-array
'''
class Solution:
    #User function Template for python3
    
    #Complete this function
    def findFloor(self,A,N,X):
        l = 0
        r = len(A) - 1
        ans = float("-inf")
        ans_idx = -1
        while l <= r:
            mid = (l+r) // 2
            
            # target lies on right side, ignore left 
            if X < A[mid]:
                r = mid - 1
            elif X >= A[mid]:
                if A[mid] > ans:
                    ans = A[mid]
                    ans_idx = mid
                l = mid + 1
        
        return ans_idx
