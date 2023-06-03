'''
https://practice.geeksforgeeks.org/problems/check-if-an-array-is-sorted0701/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=check-if-an-array-is-sorted
'''

#User function Template for python3

class Solution:
    def arraySortedOrNot(self, arr, n):
        #arr_desc = sorted(arr)
        #return 1 if arr == arr_desc else 0
        
        for idx, item in enumerate(arr):
            if idx+1 < len(arr):
                if arr[idx+1] < arr[idx]:
                    return 0
        return 1
