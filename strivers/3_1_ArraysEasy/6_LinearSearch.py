'''
https://practice.geeksforgeeks.org/problems/who-will-win-1587115621/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=who-will-win
'''

class Solution:
    ##Complete this function
    def searchInSorted(self,arr, N, K):
        # Linear Search
        '''
        is_present = -1
        for item in arr:
            if item == K:
                is_present = 1
                break
        return is_present
        '''
        
        # Binary Search
        is_present = -1
        l = 0
        r = len(arr) - 1
        mid = (l+r)//2
        
        while l <= r:
            #print("{0}-mid".format(mid))
            if arr[mid] == K:
                is_present = 1
                break
            elif K > arr[mid]:
                l = mid + 1
            elif K < arr[mid]:
                r = mid - 1
            mid = (l+r)//2
        return is_present
